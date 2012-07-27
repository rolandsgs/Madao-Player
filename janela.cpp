#include "janela.hpp"

QTextStream out(stdout);


MadaoWindow::MadaoWindow()
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);
    musicGetter = new Phonon::MediaObject(this);

    connect(mediaObject, SIGNAL(aboutToFinish()),
            this, SLOT(autoNext()));

    connect(musicGetter, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State,Phonon::State)));

    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));

    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
             this, SLOT(sourceChanged(Phonon::MediaSource)));

    Phonon::createPath(mediaObject, audioOutput);

    setAllActions();
    setGui();

    resize(720,480);
    setMinimumSize(720,480);
    playing = false;
    set = false;
    currentSong = 0;
    songsNumber = 0;
    addToTable = 0;
    lastRow = 0;
    QIcon icon("Data/taizo_hasegawa_2564.jpg");
    setWindowIcon(icon);
}

MadaoWindow::~MadaoWindow()
{
    delete audioOutput;
    delete mediaObject;
    delete musicGetter;
}

void MadaoWindow::setGui()
{
    mainWidget = new QWidget;
    bar = new QToolBar;

    bar->addAction(playPauseAction);
    bar->addAction(stopAction);
    bar->addAction(prevAction);
    bar->addAction(nextAction);
    bar->addAction(addFilesAction);

    audioSlider = new Phonon::SeekSlider(this);
    audioSlider->setMediaObject(mediaObject);
    audioSlider->setIconVisible(false);
    audioSlider->setGeometry(0,0,480,30);

    QStringList headers;
    headers << tr(" ") <<tr("N.") << tr("Nome:") << tr("Album:") << tr("Artista:");

    QSize size(120,120);

    musicTable = new QTableWidget(0, 5);/**	cellDoubleClicked ( int row, int column )**/
    musicTable->setHorizontalHeaderLabels(headers);
    musicTable->setSelectionMode(QAbstractItemView::SingleSelection);
    musicTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    musicTable->setColumnWidth(0,30);
    musicTable->setColumnWidth(1,30);
    musicTable->setColumnWidth(2,305);
    musicTable->setColumnWidth(3,170);
    musicTable->setColumnWidth(4,170);
    musicTable->setGridStyle(Qt::NoPen);
    musicTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    musicTable->setShowGrid(false);
    musicTable->verticalHeader()->setVisible(false);
    connect(musicTable, SIGNAL(cellDoubleClicked(int,int)),
             this, SLOT(tableClicked(int,int)));


    grey.setRgb(220,220,220,255);
    greySong = false;

    splitter1 = new QSplitter(Qt::Horizontal, this);
    splitter1->addWidget(bar);
    splitter1->addWidget(audioSlider);

    topLayout = new QHBoxLayout;
    topLayout->addWidget(splitter1);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(musicTable);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void MadaoWindow::setAllActions()
{
    playPauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay)
    ,tr("Play"), this);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop)
    ,tr("Stop"), this);
    addFilesAction = new QAction(style()->standardIcon(QStyle::SP_ArrowUp)
    ,tr("Add"), this);
    nextAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipForward)
    ,tr("Next"), this);
    prevAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipBackward)
    ,tr("Previous"), this);

    connect(playPauseAction, SIGNAL(triggered()), this, SLOT(playPauseMusic()));
    connect(stopAction,      SIGNAL(triggered()), this, SLOT(stopMusic()));
    connect(addFilesAction,  SIGNAL(triggered()), this, SLOT(addFiles()));
    connect(nextAction,      SIGNAL(triggered()), this, SLOT(nextMusic()));
    connect(prevAction,      SIGNAL(triggered()), this, SLOT(previousMusic()));

}

void MadaoWindow::addToMusicTable(MusicaMetaData song)
{

    QTableWidgetItem *titleItem0 = new QTableWidgetItem;
    QTableWidgetItem *titleItem1 = new QTableWidgetItem(song.track());
    QTableWidgetItem *titleItem2 = new QTableWidgetItem(song.title());
    QTableWidgetItem *titleItem3 = new QTableWidgetItem(song.album());
    QTableWidgetItem *titleItem4 = new QTableWidgetItem(song.artist());

    if(greySong)
    {
        titleItem0->setFlags(titleItem0->flags() ^ Qt::ItemIsEditable);
        titleItem0->setData(Qt::BackgroundRole, grey);
        titleItem2->setFlags(titleItem2->flags() ^ Qt::ItemIsEditable);
        titleItem2->setData(Qt::BackgroundRole, grey);
        titleItem3->setFlags(titleItem3->flags() ^ Qt::ItemIsEditable);
        titleItem3->setData(Qt::BackgroundRole, grey);
        titleItem4->setFlags(titleItem4->flags() ^ Qt::ItemIsEditable);
        titleItem4->setData(Qt::BackgroundRole, grey);
        greySong = false;
    }
    else
    {
        titleItem0->setFlags(titleItem0->flags() ^ Qt::ItemIsEditable);
        titleItem0->setData(Qt::BackgroundRole, Qt::white);
        titleItem2->setFlags(titleItem2->flags() ^ Qt::ItemIsEditable);
        titleItem2->setData(Qt::BackgroundRole, Qt::white);
        titleItem3->setFlags(titleItem3->flags() ^ Qt::ItemIsEditable);
        titleItem3->setData(Qt::BackgroundRole, Qt::white);
        titleItem4->setFlags(titleItem4->flags() ^ Qt::ItemIsEditable);
        titleItem4->setData(Qt::BackgroundRole, Qt::white);
        greySong = true;
    }

    titleItem1->setFlags(titleItem1->flags() ^ Qt::ItemIsEditable);
    titleItem1->setData(Qt::BackgroundRole, grey);

    int currentRow = musicTable->rowCount();
    musicTable->insertRow(currentRow);
    musicTable->setItem(currentRow, 0, titleItem0);
    musicTable->setItem(currentRow, 1, titleItem1);
    musicTable->setItem(currentRow, 2, titleItem2);
    musicTable->setItem(currentRow, 3, titleItem3);
    musicTable->setItem(currentRow, 4, titleItem4);
    addToTable++;
    musicGetter->setCurrentSource(list[addToTable]);
}

void MadaoWindow::metaStateChanged(Phonon::State newState,Phonon::State oldState)
{
    if (newState == Phonon::ErrorState)
    {
        QMessageBox::warning(this, tr("Error opening files"),
            musicGetter->errorString());
        return;
    }

    if (newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    if (musicGetter->currentSource().type() == Phonon::MediaSource::Invalid)
        return;

    if(addToTable == songsNumber)
        return;

    MusicaMetaData song(musicGetter->currentSource().fileName());
    addToMusicTable(song);
}

void MadaoWindow::stateChanged(Phonon::State newState, Phonon::State oldState)
{
    switch(newState)
    {
        case Phonon::ErrorState:
            if (mediaObject->errorType() == Phonon::FatalError)
            {
                QMessageBox::warning(this, tr("Fatal Error"),
                mediaObject->errorString());
            }
            else
            {
                QMessageBox::warning(this, tr("Error"),
                mediaObject->errorString());
            }
            break;
        case Phonon::PlayingState:
                playPauseAction->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
                stopAction->setEnabled(true);
                break;
        case Phonon::StoppedState:
                stopAction->setEnabled(false);
                break;
        case Phonon::PausedState:
                playPauseAction->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                stopAction->setEnabled(true);
                break;
        case Phonon::BufferingState:
                break;
        default:
            break;
    }
}

void MadaoWindow::playPauseMusic()
{
    if(!set)
    {
        mediaObject->setCurrentSource(list[currentSong]);
        mediaObject->play();
        set = true;
        playing = true;
    }
    else if(!playing)
    {
        mediaObject->play();
        playing = true;
    }
    else
    {
        playing = false;
        mediaObject->pause();
    }
}

void MadaoWindow::stopMusic()
{
    mediaObject->stop();
    playing = false;
}

void MadaoWindow::setMusic()
{
    mediaObject->setCurrentSource(list[currentSong]);
}

void MadaoWindow::nextMusic()
{
    ///(selecionado+1) % numeroitens
    currentSong = ((currentSong+1)%songsNumber);
    mediaObject->stop();
    mediaObject->setCurrentSource(list[currentSong]);
    mediaObject->play();
}

void MadaoWindow::previousMusic()
{
    ///(selecionado+numeroitens-1) % numeroitens
    currentSong = ((currentSong+songsNumber-1)%songsNumber);
    mediaObject->stop();
    mediaObject->setCurrentSource(list[currentSong]);
    mediaObject->play();
}

void MadaoWindow::addFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Select Music Files"),
    QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    if(files.isEmpty())
        return;

    int i=0;
    int index;

    index = list.numbersNos();
    for(;i < files.length();i++,songsNumber++)
    {
        Phonon::MediaSource source(files[i]);
        list.pushBack(source);
    }
    musicGetter->setCurrentSource(list[index]);
}

void MadaoWindow::autoNext()
{
	nextMusic();
}

void MadaoWindow::tableClicked(int row, int  column)
{
    mediaObject->stop();

    if (row >= list.numbersNos())
     return;

    currentSong = row;

    mediaObject->setCurrentSource(list[row]);

    mediaObject->play();
}

void MadaoWindow::sourceChanged(const Phonon::MediaSource &source)
{
    int i;
    for(i=0;;i++)
    {
        if(source == list[i])
            break;
    }
    QIcon icon("Data/current_song_image.png");
    QIcon emp;
    musicTable->item(lastRow,0)->setIcon(emp);
    musicTable->item(i,0)->setIcon(icon);
    //musicTable->selectRow(i);
    lastRow = i;
}

#include "moc_janela.cpp"
