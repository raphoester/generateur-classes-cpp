#include "fenetre_resultat.h"

Fenetre_Resultat::Fenetre_Resultat(QString codeH, QString codeCPP)
{
    QDialog *fenetre_resultat = new QDialog;
    QVBoxLayout* modele = new QVBoxLayout;
    QTabWidget* onglets = new QTabWidget();

    resultatH = new QTextEdit();
    resultatH->setPlainText(codeH);
    resultatH->setFont(QFont("Courier"));
    resultatH->setReadOnly(true);

    resultatCPP = new QTextEdit();
    resultatCPP->setPlainText(codeCPP);
    resultatCPP->setFont(QFont("Courier"));
    resultatCPP->setReadOnly(true);

    onglets->addTab(resultatH, "classe.h");
    onglets->addTab(resultatCPP, "classe.cpp");
    modele->addWidget(onglets);


    fenetre_resultat->setLayout(modele);
    fenetre_resultat->exec();
}
