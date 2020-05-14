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


bool Cluster::inm_cerca(const BinTree<pair<string,double>>& cluster, const string& id) const {
    bool b;
    if (cluster.empty()) {
        b=false;
    } 
    else if (cluster.value().first == id) {
        BinTree<pair<string, double>> cluster2(cluster.value(),cluster.left(), cluster.right());
        inm_escriure(cluster2);
        b=true;
    }
    else {
    b = inm_cerca(cluster.left(), id);
    if (not b) b = inm_cerca(cluster.right(), id);

    }
    return b;
}

bool Cluster::cerca(const string& id) const {
    return inm_cerca(cluster, id);
}


