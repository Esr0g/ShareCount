#include "model/sharecount/ShareCount.h"
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "vues/pageaccueil/PageAccueil.h"
#include "vues/pagecreationcompte/PageCreationCompte.h"
#include "vues/pageprincipale/PagePrincipale.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FenetrePrincipale fenetrePrincipale;
    ShareCount* sc = new ShareCount();
    fenetrePrincipale.setPageActive(new PageAccueil(&fenetrePrincipale, &fenetrePrincipale, sc));
    //fenetrePrincipale.setPageActive(new PageCreationCompte(&fenetrePrincipale, &fenetrePrincipale));

    fenetrePrincipale.show();
    return a.exec();
}
