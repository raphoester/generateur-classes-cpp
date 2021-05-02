#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H

#include <QMainWindow>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QApplication>
#include <QDialog>

#include "fenetre_resultat.h"
#include "nclasse.h"

class Fenetre_Principale : public QMainWindow
{
    Q_OBJECT
public:
    explicit Fenetre_Principale(QWidget *parent = nullptr);

public slots:
    void creerClasse();

private:
    QVBoxLayout* Page;

    QFormLayout* form1;
    QFormLayout* form2;
    QFormLayout* form3;

    QGroupBox* g1;
    QGroupBox* g2;
    QGroupBox* g3;

    QLineEdit* nom;
    QLineEdit* mere;

    QCheckBox* protection;
    QCheckBox* constructeur;
    QCheckBox* destructeur;

    QLineEdit* auteur;
    QDateEdit* date;
    QTextEdit* role;

    QDialogButtonBox *valider;

    Nclasse classe;


signals:

};

#endif // FENETRE_PRINCIPALE_H
