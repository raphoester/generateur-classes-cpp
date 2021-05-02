#ifndef FENETRE_RESULTAT_H
#define FENETRE_RESULTAT_H

#include <QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

class Fenetre_Resultat : public QDialog
{
public:
    Fenetre_Resultat(QString code);
private:
    QPushButton* btn_valider;
    QTextEdit* resultat;
    QVBoxLayout* modele;
};

#endif // FENETRE_RESULTAT_H
