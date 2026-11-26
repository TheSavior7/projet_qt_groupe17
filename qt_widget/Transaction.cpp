#include "Transaction.h"

int Transaction::getCategorieId() const{
    return categorieId;
}

int Transaction::getCompteId() const{
    return compteId;
}

int Transaction::getId() const{
    return id;
}

double Transaction::getMontant() const{
    return montant;
}

QDate Transaction::getDate() const{
    return date;
}

QString Transaction::getLibelle() const{
    return libelle;
}


TypeTransaction Transaction::getType() const{
    return type;
}

bool Transaction::modifierMontant(double new_montant){
    if(new_montant<=0)
        return false;
    this->montant = new_montant;
    return true;
}

bool Transaction::modifierDate(QDate new_date){
    if(!new_date.isValid() || new_date > QDate::currentDate())
        return false;
    this->date = new_date;
    return true;
}

bool Transaction::changerCategorie(int new_categorieId){
    if(new_categorieId<=0)
        return false;
    this->categorieId = new_categorieId;
    return true;
}

bool Transaction::changerCompte(int new_compteId){
    if(new_compteId<=0)
        return false;
    this->compteId = new_compteId;
    return true;
}

bool Transaction::changerLibelle(QString new_libelle){
    if(new_libelle.trimmed().isEmpty())
        return false;
    this->libelle = new_libelle;
    return true;
}

