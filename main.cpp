#include "model/sharecount/ShareCount.h"
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "vues/pageaccueil/PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FenetrePrincipale fenetrePrincipale;
    fenetrePrincipale.setPageActive(new PageAccueil(&fenetrePrincipale, &fenetrePrincipale, new ShareCount()));
    //fenetrePrincipale.setPageActive(new PageCreationCompte(&fenetrePrincipale, &fenetrePrincipale));

    fenetrePrincipale.show();
    return a.exec();
}
