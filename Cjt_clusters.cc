#include "Cjt_clusters.hh"

void Cjt_clusters::inicialitza_clusters(Cjt_especies& conjunt) {
    map_clusters.clear();
    tabla_distancias_cluster.clear();
    conjunt.inicio();
         while (not conjunt.final()) {
             string x;
             conjunt.actual(x);
             Cluster clust(x);
              map_clusters.insert(make_pair(x, clust));
             conjunt.avanza();

        }
    tabla_dist_clust(conjunt);
    imprime_tabla_distancias();

}


void Cjt_clusters::imprime_arbol_filogenetico() const {
    for (auto it = map_clusters.begin(); it != map_clusters.end(); ++it) {
        cout << it->first << endl;
    }

}

void Cjt_clusters::tabla_dist_clust(const Cjt_especies& conjunt) {
    for (auto it = map_clusters.begin(); it != map_clusters.end(); ++it) {
        map<string, double> aux;
        for (auto it2 = it; it2 != map_clusters.end(); ++it2) {
            if (it->first != it2->first) {
            double x = conjunt.calcular_distancia(it->first, it2->first);
            aux.insert(make_pair(it2->first, x));
            }
        }
        tabla_distancias_cluster.insert(make_pair(it->first, aux));
    }
}


void Cjt_clusters::imprime_tabla_distancias() const {
	for (auto it2 = tabla_distancias_cluster.begin(); it2 != tabla_distancias_cluster.end(); ++it2) {
		cout << it2->first << ":";
		for (auto it3 = it2; it3 != tabla_distancias_cluster.end(); ++it3) {
			bool espai = true;
		if (it2->first != it3->first) {
			const auto it = tabla_distancias_cluster.find(it2->first);
			const auto ti = it->second.find(it3->first);
			if (not espai) cout << " ";
			else espai = true;
			cout << " " << it3->first << " (" << ti->second << ")";			
			}
		}
		cout << endl;
	}
}


/*void Cjt_clusters::imprime_cluster(string id) const {
    auto it = map_clusters.find(id);
    if (it == map_clusters.end()) cout << "Error, el cluster no existeix" << endl;
    else {
        it->second.escriure();
    }
}*/
