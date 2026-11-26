#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <QDate>
#include "TypeTransaction.h"

class Transaction{
private:
    int id;
    int compteId;
    int categorieId;
    double montant;
    TypeTransaction type;
    QString libelle;
    QDate date;

public:
    Transaction(){
        this->id = -1;
        this->compteId = 0;
        this->categorieId  = 0;
        this->montant = 0;
        this->libelle ="";
        this->type = TypeTransaction::Depense;
    }

    Transaction(int id, int compteId, int categorieId, double montant,  TypeTransaction type, QString libelle, QDate date){
        this->id = id;
        this->compteId = compteId;
        this->categorieId = categorieId;
        this->montant = montant;
        this->type = type;
        this->libelle = libelle;
        this->date = date;
    }
    int getId() const;

    int getCompteId() const;

    int getCategorieId() const;

    double getMontant() const;

    TypeTransaction getType() const;

    QString getLibelle() const;

    QDate getDate() const;

    bool modifierMontant(double);

    bool modifierDate(QDate);

    bool changerCategorie(int);

    bool changerCompte(int);

    bool changerLibelle(QString);

};

#endif // TRANSACTION_H
