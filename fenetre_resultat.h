#ifndef FENETRE_RESULTAT_H
#define FENETRE_RESULTAT_H

#include <QVBoxLayout>
#include <QTextEdit>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QFileDialog>

class Fenetre_Resultat : public QDialog
{
public:
    Fenetre_Resultat(QString codeH, QString codeCPP);
private:
    void Enregistrer_fichier(QString ext, QString *code);
    QTabWidget* onglets;
    QTextEdit* resultatH;
    QTextEdit* resultatCPP;
    QVBoxLayout* modele;
    QString* code_H;
    QString* code_CPP;
};

#endif // FENETRE_RESULTAT_H
