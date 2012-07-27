#ifndef MADAO_WINDOW_HPP
#define MADAO_WINDOW_HPP

#include "MadaoPlayer.hpp"

#include <QtGui>
#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

class MusicaMetaData;

class MadaoWindow : public QMainWindow
{
    Q_OBJECT

public:
    MadaoWindow();
    virtual ~MadaoWindow();

private:
    bool playing;
    bool set;
    int currentSong;
    int songsNumber;
    int addToTable;
    short int lastRow;
    bool greySong;
    Phonon::SeekSlider *audioSlider;                ///Barra de tempo da musica
    Phonon::MediaObject *mediaObject;               ///Objeto de Media do phonon
    Phonon::MediaObject *musicGetter;               ///Objeto de Media do phonon onde pegara toda informação das musicas
    Phonon::AudioOutput *audioOutput;               ///Saida de audio do phonon
    Phonon::VolumeSlider *volumeSlider;             ///Barra de volume
    ListaDuplaEncadeada<Phonon::MediaSource> list;  ///Lista de Musicas
    QColor grey;

    QAction *playPauseAction;
    QAction *stopAction;
    QAction *nextAction;
    QAction *prevAction;
    QAction *addFilesAction;
    QTableWidget *musicTable;
    QSplitter *splitter1;
    QHBoxLayout *topLayout;
    QVBoxLayout *mainLayout;
    QToolBar *bar;
    QWidget *mainWidget;

    void setGui();                        ///Função para setar toda a gui
    void setAllActions();                 ///Função para setar todas as ações
    void addToMusicTable(MusicaMetaData song);

private slots:
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
    void stateChanged(Phonon::State newState, Phonon::State oldState);
    void playPauseMusic();
    void stopMusic();
    void setMusic();
    void nextMusic();
    void previousMusic();
    void addFiles();
    void autoNext();
    void tableClicked(int row, int column);
    void sourceChanged(const Phonon::MediaSource &source);
};


#endif
