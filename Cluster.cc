#include "Cluster.hh"

Cluster::Cluster(const string& id){
    pair<string, double> clust;
    clust.first = id;
    clust.second = 0.00;
    BinTree<pair<string, double>> arbre_cluster(clust);
    cluster = arbre_cluster;

}

