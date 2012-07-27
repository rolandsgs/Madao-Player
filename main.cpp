#include "MadaoPlayer.hpp"

///http://www.joelverhagen.com/blog/2010/11/how-to-compile-taglib-on-windows/

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MadaoWindow janela;
    janela.show();

    return app.exec();
}
