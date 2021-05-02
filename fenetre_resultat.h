#ifndef FENETRE_RESULTAT_H
#define FENETRE_RESULTAT_H

#include <QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QTabWidget>

class Fenetre_Resultat : public QDialog
{
public:
    Fenetre_Resultat(QString codeH, QString codeCPP);
private:
    QTabWidget* onglets;
    QTextEdit* resultatH;
    QTextEdit* resultatCPP;
    QVBoxLayout* modele;
};

#endif // FENETRE_RESULTAT_H
