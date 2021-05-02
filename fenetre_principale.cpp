#include "fenetre_principale.h"

Fenetre_Principale::Fenetre_Principale(QWidget *parent) : QMainWindow(parent)
{
    QWidget *zoneCentrale = new QWidget;
    Page = new QVBoxLayout();

    g1 = new QGroupBox(tr("Définition de la classe"));
    form1 = new QFormLayout();
    g1->setLayout(form1);

    nom = new QLineEdit();
    mere = new QLineEdit();

    form1->addRow("Nom", nom);
    form1->addRow("Classe mère", mere);


    g2 = new QGroupBox(tr("Options"));
    form2 = new QFormLayout();

    g2->setLayout(form2);

    protection = new QCheckBox;
    constructeur = new QCheckBox;
    destructeur = new QCheckBox;
    protection->setLayoutDirection(Qt::RightToLeft);
    constructeur->setLayoutDirection(Qt::RightToLeft);
    destructeur->setLayoutDirection(Qt::RightToLeft);

    form2->addRow("Protéger le header contre les inclusions multiples", protection);
    form2->addRow("Générer un constructeur par défaut", constructeur);
    form2->addRow("Générer un destructeur", destructeur);


    g3 = new QGroupBox(tr("Ajouter des commentaires"));
    g3->setCheckable(true);
    g3->setChecked(true);
    form3 = new QFormLayout();
    g3->setLayout(form3);

    auteur = new QLineEdit;
    date = new QDateEdit;
    role = new QTextEdit;

    form3->addRow("Auteur", auteur);
    form3->addRow("Date de création", date);
    form3->addRow("Rôle de la classe", role);

    valider = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    Page->addWidget(g1);
    Page->addWidget(g2);
    Page->addWidget(g3);
    Page->addWidget(valider);



    zoneCentrale->setLayout(Page);
    setCentralWidget(zoneCentrale);

    QObject::connect(valider, SIGNAL(rejected()), qApp, SLOT(quit()));
    QObject::connect(valider, SIGNAL(accepted()), this, SLOT(creerClasse()));
}

void Fenetre_Principale::creerClasse(){
    classe.auteur = auteur->text();
    classe.constructeur = constructeur->checkState();
    classe.destructeur = destructeur->checkState();
    classe.mere = mere->text();
    classe.nom = nom->text();
    classe.role = role->toPlainText();
    classe.protection = protection->checkState();
    classe.creation = new QDate(date->date());
    classe.commentaires = true;

    if (!g3->isChecked()){
        classe.commentaires = false;
    }

    Fenetre_Resultat *rs = new Fenetre_Resultat(classe.Generer());
}
