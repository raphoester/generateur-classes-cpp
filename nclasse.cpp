#include "nclasse.h"

Nclasse::Nclasse()
{
    /*
    this->auteur = " ";
    this->commentaires = false;
    this->constructeur = false;
    this->creation = new QDate(2020, 12, 4);
    this->destructeur = false;
    this->mere = " ";
    this->nom = " ";
    this->protection = false;
    this->role = " ";
    */
}

QString Nclasse::GenererH(){
    QString texte = "";
    if (this->commentaires == true){
        texte += "/*\n";
           if(!this->auteur.isEmpty()){
               texte += "Auteur : " + this->auteur + "\n";
           }
           if(!this->creation->toString().isEmpty()){
               texte += "Date de création : " + this->creation->toString() + "\n";
           }
           if(!this->role.isEmpty()){
               texte += "Rôle : \n" + this->role + "\n";
           }

        texte += "*/\n\n";
    }
    if(this->protection == true){
        texte += "#ifndef HEADER_"+ this->nom.toUpper() + "\n#define HEADER_"+this->nom.toUpper()+"\n\n";
    }
    texte += "class " + this->nom;
    if(!this->mere.isEmpty()){
        texte += " : public " + this->mere;
    }
    texte+="\n{\npublic:";
    if(this->constructeur == true){
        texte += "\n\t" + this->nom + "();";
    }
    if(this->destructeur == true){
        texte += "\n\t~" + this->nom + "();";
    }

    texte+="\n\n\nprotected:\n\n\n";

    texte+="private:\n\n\n";

    texte +="};\n";

    if(this->protection == true){
        texte += "\n#endif HEADER_"+ this->nom.toUpper() + "\n";
    }

    return texte;
}

QString Nclasse::GenererCPP(){
    QString texte = "";
    if (this->commentaires == true){
        texte += "/*\n";
           if(!this->auteur.isEmpty()){
               texte += "Auteur : " + this->auteur + "\n";
           }
           if(!this->creation->toString().isEmpty()){
               texte += "Date de création : " + this->creation->toString() + "\n";
           }
           if(!this->role.isEmpty()){
               texte += "Rôle : \n" + this->role + "\n";
           }

        texte += "*/\n\n";
    }

    texte += "#include " + this->nom + ".h\n\n";

    if(this->constructeur==true){
        texte += this->nom + "::" + this->nom + "()\n{\n\n}\n";
    }

    if(this->destructeur==true){
        texte += this->nom + "::~" + this->nom + "()\n{\n\n}\n";
    }


    return texte;
}
