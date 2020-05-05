#include "Cluster.hh"

Cluster::Cluster(const string& id){
    pair<string, double> clust;
    identificador = id;
    clust.first = id;
    clust.second = 0.00;
    BinTree<pair<string, double>> cluster(clust);
}
Cluster::Cluster(const Cluster clus1, const Cluster clus2, const double& dist) {
    pair<string, double> clust;
    string id = clus1.identificador + clus2.identificador;
    clust.first = id;
    clust.second = dist/2;
    BinTree<pair<string, double>> cluster(clust);
}

void Cluster::escriure() const {
    inm_escriure(cluster);
}

void Cluster::inm_escriure(const BinTree<pair<string,double>>& a) const {
    if (not a.empty()) cout << 2 << endl;
}

