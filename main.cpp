#include <QApplication>
#include "fenetre_principale.h"

void main(int argc, char* argv[]){

    QApplication app(argc, argv);
    Fenetre_Principale mw;



    mw.show();
    app.exec();

}
