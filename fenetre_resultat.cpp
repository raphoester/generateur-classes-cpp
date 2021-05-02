#include "fenetre_resultat.h"

Fenetre_Resultat::Fenetre_Resultat(QString codeH, QString codeCPP)
{
    std::string ch = codeH.toStdString();
    std::string ccpp = codeCPP.toStdString();

    QString *code_H = new QString(ch.c_str());
    QString *code_CPP = new QString(ccpp.c_str());

    QDialog *fenetre_resultat = new QDialog;
    QVBoxLayout* modele = new QVBoxLayout;
    QTabWidget* onglets = new QTabWidget();
    QPushButton* enregistrerH = new QPushButton("Enregistrer le .h");
    QPushButton* enregistrerCPP = new QPushButton("Enregistrer le .cpp");
    QVBoxLayout* modeleCPP = new QVBoxLayout();
    QVBoxLayout* modeleH = new QVBoxLayout();
    QWidget* boiteH = new QWidget();
    QWidget* boiteCPP = new QWidget();

    resultatH = new QTextEdit();
    resultatH->setPlainText(codeH);
    resultatH->setFont(QFont("Courier"));
    resultatH->setReadOnly(true);

    modeleH->addWidget(resultatH);
    modeleH->addWidget(enregistrerH);
    boiteH->setLayout(modeleH);

    resultatCPP = new QTextEdit();
    resultatCPP->setPlainText(codeCPP);
    resultatCPP->setFont(QFont("Courier"));
    resultatCPP->setReadOnly(true);

    modeleCPP->addWidget(resultatCPP);
    modeleCPP->addWidget(enregistrerCPP);
    boiteCPP->setLayout(modeleCPP);

    onglets->addTab(boiteH, "classe.h");
    onglets->addTab(boiteCPP, "classe.cpp");
    modele->addWidget(onglets);



    QObject::connect(enregistrerH, &QPushButton::clicked, [this](){ Fenetre_Resultat::Enregistrer_fichier("h", this->code_H) ;});
    QObject::connect(enregistrerCPP, &QPushButton::clicked, [this](){ Fenetre_Resultat::Enregistrer_fichier("cpp", this->code_CPP) ;});


    fenetre_resultat->setLayout(modele);
    fenetre_resultat->exec();
}

void Fenetre_Resultat::Enregistrer_fichier(QString ext, QString *code){
    QString nom_fichier = QFileDialog::getSaveFileName(this, "Enregistrer le fichier", QString(), "Fichiers de code C++ (*."+ext+")");

    if(nom_fichier.isEmpty()){

    }
    else{
        QFile fichier(nom_fichier);
        if (fichier.open(QIODevice::WriteOnly) == true){

            fichier.write(code->toUtf8());
            fichier.close();
        }
    }
}
