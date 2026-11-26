#ifndef GESTIONNAIRETRANSACTION_H
#define GESTIONNAIRETRANSACTION_H
#include <QString>
#include <QList>
#include <QDate>
#include "Transaction.h"

class GestionnaireTransaction{

private:
    QList <Transaction> transactions;
    bool actualiserSolde(Transaction);
    bool actualiserBudget(Transaction);


public:
    bool enregistrerTransaction(Transaction);

    bool supprimerTransaction(Transaction);

    QList<Transaction> consulterTransactions(int) const;

    QList<Transaction> filtreTransaction(int, int, QString, QDate, double, TypeTransaction) const;
};

#endif // GESTIONNAIRETRANSACTION_H
