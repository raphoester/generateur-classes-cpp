#ifndef NCLASSE_H
#define NCLASSE_H
#include <QString>
#include <QDate>

class Nclasse
{
public:
    Nclasse();
    QString GenererH();
    QString GenererCPP();

    QString nom;
    QString mere;

    bool protection;
    bool constructeur;
    bool destructeur;

    bool commentaires;
    QString auteur;
    QDate* creation;
    QString role;

private:


};

#endif // NCLASSE_H
