#include "Mainwindow.h"
#include "model/sharecount/Sharecount.h"
#include "screen/fenetreprincipale/FenetrePrincipale.h"
#include "vues/pageaccueil/PageAccueil.h"
#include "vues/pageCreationCompte/PageCreationCompte.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShareCount shareCount = ShareCount();

    FenetrePrincipale fenetrePrincipale;
    fenetrePrincipale.setPageActive(new PageAccueil(&fenetrePrincipale, &fenetrePrincipale));
    //fenetrePrincipale.setPageActive(new PageCreationCompte(&fenetrePrincipale, &fenetrePrincipale));

    fenetrePrincipale.show();
    return a.exec();
}
