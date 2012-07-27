#include "musica.hpp"

MusicaMetaData::MusicaMetaData()
{
    if(this == NULL)
        return;

    dir = "";
}

MusicaMetaData::MusicaMetaData(QString dir) : TagLib::FileRef(qstringToChar(dir))
{
    if(this == NULL)
        return;

    this->dir  = dir;
}

MusicaMetaData::~MusicaMetaData()
{

}

QString MusicaMetaData::getDir()
{
    return dir;
}

QString MusicaMetaData::title()
{
    std::string title = tag()->title().to8Bit();

    if(title == "")
    {
        QFile file(dir);
        QFileInfo fileInfo(file.fileName());
        title = fileInfo.fileName().toLocal8Bit().constData();
        int len = title.size();
        for(int i=(len-1);i>=0;i--)
        {
            if(title[i] == '.')
            {
                title[i] = '\0';
                break;
            }

            title[i] = '\0';
        }
    }

    return QString::fromStdString(title);
}

QString MusicaMetaData::artist()
{
    std::string artist = tag()->artist().to8Bit();

    if(artist == "")
    {
        artist = "UNKNOW";
    }
    return QString::fromStdString(artist);
}

QString MusicaMetaData::album()
{
    std::string album = tag()->album().to8Bit();

    if(album == "")
    {
        album = "UNKNOW";
    }
    return QString::fromStdString(album);
}

QString MusicaMetaData::comment()
{
    std::string comment = tag()->comment().to8Bit();

    if(comment == "")
    {
        comment = "UNKNOW";
    }
    return QString::fromStdString(comment);
}

QString MusicaMetaData::genre()
{
    std::string genre = tag()->genre().to8Bit();

    if(genre == "")
    {
        genre = "UNKNOW";
    }
    return QString::fromStdString(genre);
}

QString MusicaMetaData::year()
{
    uint year = tag()->year();
    QString year_str;
    if(year == 0)
        year_str = "UNKNOW";
    else
        year_str = QString::number(tag()->year());

    return year_str;
}

QString MusicaMetaData::track()
{
    uint track = tag()->track();
    QString track_str;
    if(track == 0)
        track_str = "0";
    else
        track_str = QString::number(tag()->track());

    return track_str;
}

void MusicaMetaData::operator=(MusicaMetaData a)
{
    TagLib::FileRef fr(qstringToChar(a.dir));
    TagLib::FileRef::operator=(fr);
    this->dir = a.dir;
}

char *qstringToChar(QString str)
{
	QByteArray ba = str.toLocal8Bit();
	char *str2 = ba.data();
	return str2;
}
