/** @file Cluster.cc
 * 	@brief Còdig de la classe Cluster.
 */

#include "Cluster.hh"

Cluster::Cluster(const string& id){
    pair<string, double> clust;
    clust.first = id;
    clust.second = 0;
    cluster = BinTree<pair<string, double>> (clust);
}
Cluster::Cluster(const Cluster clus1, const Cluster clus2, const double& dist) {
    pair<string, double> clust;
    clust.first = clus1.cluster.value().first + clus2.cluster.value().first;
    clust.second = dist/2;
    cluster = BinTree<pair<string,double>> (clust,clus1.cluster,clus2.cluster);
}

void Cluster::escriure() const {
    inm_escriure(cluster);
    cout << endl;
}

void Cluster::inm_escriure(const BinTree<pair<string,double>>& a) const {
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





