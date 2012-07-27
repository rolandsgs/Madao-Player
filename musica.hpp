#ifndef MUSICA_H
#define MUSICA_H

#include "MadaoPlayer.hpp"
#include <qt/qstring.h>
#include <taglib/fileref.h>

class MusicaMetaData : public TagLib::FileRef
{
private:
    QString dir;

public:
    MusicaMetaData();
    MusicaMetaData(QString dir);

    virtual ~MusicaMetaData();

    QString getDir();
    QString title();
    QString artist();
    QString album();
    QString comment();
    QString genre();
    QString year();
    QString track();

    void setTitle(QString a);
    void setArtist(QString a);
    void setAlbum(QString a);
    void setComment(QString a);
    void setGenre(QString a);
    void setYear(QString a);
    void setTrack(QString a);

    void setData(QString dir);
    void setData(Phonon::MediaSource source);

    void operator=(MusicaMetaData a);

};

char *qstringToChar(QString str);     ///converte de QString para char *

#endif
