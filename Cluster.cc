/** @file Cluster.cc
 * 	@brief Còdig de la classe Cluster.
 */

	//invariant Els clusters contenen una única espècie o bé estàn formats
	//per altres clusters. Així mateix, un cluster és assimilable a un
	//arbre binari on té espècies a les fulles. 


#include "Cluster.hh"


// Constructores

Cluster::Cluster(const string& id){
    //Es crea un pair on hi ha l'identificador del cluster i
    //la distancia respecte els seus fills. Al ser un cluster sense fills, la distancia es 0.
    pair<string, double> clust;
    clust.first = id;
    clust.second = 0;
    //Es crea l'arbol binari de cluster.
    cluster = BinTree<pair<string, double>> (clust);
}

Cluster::Cluster(const Cluster clus1, const Cluster clus2, const double& dist) {
    //Es fusionen dos clusters en un. El identificador del pair és el
    //resultat de fusionar els dos id's.
    //El double dist és la distancia entre els dos clusters.
    pair<string, double> clust;
    clust.first = clus1.cluster.value().first + clus2.cluster.value().first;
    clust.second = dist/2; //dist/2 ja que la formula ho demana així.
    //Es crea un arbre amb node principal el pair acabat de crear, node esquerra el 
    //arbre del primer cluster i node dret el arbre del segon cluster.
    cluster = BinTree<pair<string,double>> (clust,clus1.cluster,clus2.cluster);
}


// Modificadores

// Consultores

//Lectura i escriptura


void Cluster::escriure() const {
    //Entra el arbre del paràmetre implícit a la funció recursiva.
    inm_escriure(Cluster::cluster);
    cout << endl;
}

// Mètodes privats

void Cluster::inm_escriure(const BinTree<pair<string,double>>& a)  {
    //Escriptura del arbre binari. Si aquest té els nodes 
    //dret i esquerre buit, es a dir, són fulles de l'arbre,
    //no escriu la distancia respecte als fills.
    	if (not a.empty()) {
        if (not a.left().empty() and not a.right().empty()) {
		cout <<"["<< "(" << a.value().first << ", " << a.value().second<< ") ";
        }
        else {
            cout <<"["<< a.value().first;
        }
		inm_escriure(a.left());
		inm_escriure(a.right());
        cout << "]";
	}
}




