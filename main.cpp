#include <QApplication>
#include "fenetre_principale.h"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    Fenetre_Principale mw;



    mw.show();
    app.exec();

}
