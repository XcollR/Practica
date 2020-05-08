#include "Cjt_clusters.hh"



void Cjt_clusters::inicialitza_cluster_sense_imprimir(Cjt_especies& conjunt) {
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

}

void Cjt_clusters::inicialitza_clusters(Cjt_especies& conjunt) {
    inicialitza_cluster_sense_imprimir(conjunt);
    imprime_tabla_distancias();

}


void Cjt_clusters::imprime_arbol_filogenetico(Cjt_especies& conjunt) {
    inicialitza_cluster_sense_imprimir(conjunt);
    if (map_clusters.size() != 0) {
    while (map_clusters.size() > 1) {
        ejecuta_paso_wpgm_sense_imprimir();
    }
    auto it = map_clusters.begin();
    it->second.escriure();
    }
    else cout << "ERROR: El conjunto de clusters es vacio." << endl;


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


void Cjt_clusters::imprime_cluster(string id) const {
    auto it = map_clusters.find(id);
    if (it == map_clusters.end()) cout << "ERROR: El cluster "<< id << " no existe." << endl;
    else {
        it->second.escriure();
    }
}


void Cjt_clusters::ejecuta_paso_wpgm_sense_imprimir() {
    double distancia = 100;
    string x1,x2;
    auto it = tabla_distancias_cluster.begin(), it2 = it;
    ++it2;
    while (it != tabla_distancias_cluster.end()) {
        while (it2 != tabla_distancias_cluster.end()) {
			const auto a = tabla_distancias_cluster.find(it->first);
			const auto ti = it->second.find(it2->first);
                if (ti->second < distancia) {
                distancia = ti->second;
                x1 = a->first;
                x2= ti->first;
                }
            ++it2;
        }
        ++it;
    }

    string x = x1+x2;
    auto a = map_clusters.find(x1);
    auto b = map_clusters.find(x2);

    Cluster c(a->second,b->second,distancia);
    map_clusters.insert(make_pair(x,c));
    afegeix_especie_clusters(x1,x2,distancia);
}

void Cjt_clusters::ejecuta_paso_wpgm() {
    if (map_clusters.size() > 1) {
    ejecuta_paso_wpgm_sense_imprimir();   
    imprime_tabla_distancias();
    }
    else cout << "ERROR: num_clusters <= 1";
}
 



void Cjt_clusters::elimina_especie_clusters(const string& id) {
	auto it = tabla_distancias_cluster.find(id);
	for (auto it2 = tabla_distancias_cluster.begin(); it2 != it; ++it2) {
			it2->second.erase(it2->second.find(id));
		}
	tabla_distancias_cluster.erase(it);
    auto it2 = map_clusters.find(id);
    map_clusters.erase(it2);

}

void Cjt_clusters::afegeix_especie_clusters(const string& c1, const string& c2, const double& dist) {
    string id = c1+c2;
	map<string, double> aux;
	for (auto it = map_clusters.begin(); it != map_clusters.end(); ++it) {
		auto itt = tabla_distancias_cluster.find(it->first);
		if (id > it->first) {
			itt->second.insert(make_pair(id, dist/2));
		}
		else if (id < it->first) {
			aux.insert(make_pair(it->first, dist/2));
		}
			
	}
	tabla_distancias_cluster.insert(make_pair(id, aux));
    elimina_especie_clusters(c1);
    elimina_especie_clusters(c2);
}
