#include "fenetre_resultat.h"

Fenetre_Resultat::Fenetre_Resultat(QString code)
{
    QDialog *fenetre_resultat = new QDialog;
    QVBoxLayout* modele = new QVBoxLayout;

    resultat = new QTextEdit();
    resultat->setPlainText(code);
    resultat->setFont(QFont("Courier"));
    resultat->setReadOnly(true);

    btn_valider = new QPushButton("Valider");

    modele->addWidget(resultat);
    modele->addWidget(btn_valider);

    fenetre_resultat->setLayout(modele);
    fenetre_resultat->exec();

    QWidget::connect(btn_valider, SIGNAL(clicked()), this, SLOT(accept()));
}
