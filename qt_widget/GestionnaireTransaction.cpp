#include "GestionnaireTransaction.h"

bool GestionnaireTransaction::supprimerTransaction(Transaction t){
    if(t.getId()<=0 || transactions.isEmpty())
        return false;
    int i = 0;
    while(i<transactions.count()){
        if (transactions[i].getId() ==t.getId()){
            transactions.removeAt(i);
            // TODO : annuler l'impact de cette transaction sur le solde et le budget
            return true;
        }
        i++;
    }
    return false;

}

QList<Transaction> GestionnaireTransaction::consulterTransactions(int compteId) const{
    QList<Transaction> resultat;
    int i = 0;
    while(i<transactions.count()){
        if(transactions.at(i).getCompteId() == compteId)
            resultat.append(transactions.at(i));
        i++;
    }
    return resultat;
}

QList<Transaction> GestionnaireTransaction::filtreTransaction(int compteId, int categorieId, QString libelle, QDate date, double montant, TypeTransaction type) const{
    QList<Transaction> resultat;
    int i = 0;
    while (i<transactions.count()) {
        bool correspond = true;
        if (compteId > 0 && transactions.at(i).getCompteId() != compteId) {
            correspond = false;
        }
        if (correspond && categorieId > 0 && transactions.at(i).getCategorieId() != categorieId) {
            correspond = false;
        }
        if (correspond && !libelle.trimmed().isEmpty() && !transactions.at(i).getLibelle().contains(libelle.trimmed(), Qt::CaseInsensitive)) {
            correspond = false;
        }
        if (correspond && date.isValid() && transactions.at(i).getDate() != date) {
            correspond = false;
        }
        if (correspond && montant > 0.0 && transactions.at(i).getMontant() != montant) {
            correspond = false;
        }
        if (correspond && transactions.at(i).getType() != type) {
            correspond = false;
        }

        if (correspond) {
            resultat.append(transactions.at(i));
        }

        i++;
    }
    return resultat;

}



