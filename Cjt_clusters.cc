  
#include "Cjt_clusters.hh"


Cjt_clusters::Cjt_clusters() {
    map_clusters = map<string,Cluster>();
    tabla_distancias_cluster = map<string,map<string,double>>();
}


void Cjt_clusters::inicialitza_clusters(Cjt_especies& conjunt,const bool ve_de_func) {

    map_clusters.clear();
    tabla_distancias_cluster.clear();
    conjunt.inicio(); // iterador de conjunt es fica a la primera posiciรณ
         while (not conjunt.final()) {
             string x;
             conjunt.actual(x); // 
             Cluster clust(x);
             map_clusters.insert(make_pair(x, clust));
             conjunt.avanza();

        }
    tabla_dist_clust(conjunt);
    if (ve_de_func) imprime_tabla_distancias();
}



void Cjt_clusters::imprime_arbol_filogenetico(Cjt_especies& conjunt) {
    bool fals = false;
    inicialitza_clusters(conjunt,fals);

    if (map_clusters.size() != 0) {
    while (map_clusters.size() > 1) {
        ejecuta_paso_wpgma(fals);
    }
    map<string,Cluster>::const_iterator it = map_clusters.begin();
    it->second.escriure();
    }
    else cout << "ERROR: El conjunto de clusters es vacio." << endl;


}

void Cjt_clusters::tabla_dist_clust(const Cjt_especies& conjunt) {
    for (map<string,Cluster>::const_iterator it = map_clusters.begin(); it != map_clusters.end(); ++it) {
        map<string, double> aux;
        for (map<string,Cluster>::const_iterator it2 = it; it2 != map_clusters.end(); ++it2) {
            if (it->first != it2->first) { // fem aquest if ja que els iterador començen a la mateixa posició.
            double x = conjunt.calcular_distancia(it->first, it2->first);
            aux.insert(make_pair(it2->first, x));
            }
        }
        tabla_distancias_cluster.insert(make_pair(it->first, aux));
    }
}


void Cjt_clusters::imprime_tabla_distancias() const {
	for(map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.begin(); it != tabla_distancias_cluster.end(); ++it) {
		cout << it->first << ":";
		for (map<string,double>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
				cout << " " << it2->first << " (" << it2->second << ")"; 
		}
		cout << endl;
	}
}

void Cjt_clusters::imprime_cluster(string id) const {
    map<string,Cluster>::const_iterator it = map_clusters.find(id);
    if (it == map_clusters.end()) cout << "ERROR: El cluster " << id << " no existe." << endl;
    else{
        it->second.escriure();
    }    
}

void Cjt_clusters::ejecuta_paso_wpgma(const bool& a) {
    if (map_clusters.size() > 1) {
    pair<string,string> pair_dist = min_dist(); //pair amb els dos clusters a menor distancia.
    afegeix_especie_clusters(pair_dist);
    elimina_especie_clusters(pair_dist.first);
    elimina_especie_clusters(pair_dist.second);    
    if (a) imprime_tabla_distancias();
    }
    else cout << "ERROR: num_clusters <= 1" << endl;
}
 



void Cjt_clusters::elimina_especie_clusters(const string& id) {
    map<string, Cluster>::const_iterator peix = map_clusters.find(id);
	map_clusters.erase(peix);
	map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.find(id);
	for (map<string,map<string,double>>::const_iterator it2 = tabla_distancias_cluster.begin(); it2 != it; ++it2) {
			it2->second.erase(it2->second.find(id));
		}
	tabla_distancias_cluster.erase(it);

}

void Cjt_clusters::afegeix_especie_clusters(const pair<string,string>& dist) {
    string fus = dist.first + dist.second;
    map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.begin();
    while (it != tabla_distancias_cluster.end() and it->first < fus) {
        tabla_distancias_cluster[it->first][fus] = (tabla_distancias_cluster[it->first][dist.first] + tabla_distancias_cluster[min(it->first,dist.second)][max(it->first,dist.second)])/2;
        ++it;
    }
    while (it != tabla_distancias_cluster.end()) {
        tabla_distancias_cluster[fus][it->first] = (tabla_distancias_cluster[dist.first][it->first] + tabla_distancias_cluster[min(it->first,dist.second)][max(it->first,dist.second)])/2;
        ++it;
    }
    map<string,Cluster>::const_iterator a = map_clusters.find(dist.first);
    map<string,Cluster>::const_iterator b = map_clusters.find(dist.second);
    Cluster c(a->second,b->second,dist_clust(dist.first,dist.second));
    map_clusters.insert(make_pair(fus,c));


}

pair<string,string> Cjt_clusters::min_dist() const {
    double distancia = 101;
    pair<string,string> dists;
    for (map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.begin(); it != tabla_distancias_cluster.end(); ++it) {
        for (map<string,map<string,double>>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                if (it2->second < distancia ){
                distancia = it2->second;
                dists.first = it->first;
                dists.second = it2->first;
                }
            }

        }

    return dists;

}

double Cjt_clusters::dist_clust(const string& id, const string& id2) const {
    map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.find(id);
    map<string,double>::const_iterator it2 = it->second.find(id2);
    if (it == tabla_distancias_cluster.end() or it2 == it->second.end()) return -1;
    return it2->second;
}