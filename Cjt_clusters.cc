/** @file Cjt_clusters.cc
 * 	@brief Còdig de la classe Cjt_clusters.
*/

    //invariant El conjunt de clusters sempre estarà ordenat
	//alfabèticament i aquest no té mida màxima ni mínima. La taula
	//de distàncies entre clusters també està ordenada alfabèticament
	//amb els identificadors dels clusters.



#include "Cjt_clusters.hh"



// Constructores


Cjt_clusters::Cjt_clusters() {
    //Es crea el mapa de clusters i el de distancies buit.
    map_clusters = map<string,Cluster>();
    tabla_distancias_cluster = map<string,map<string,double>>();
}


// Consultores


double Cjt_clusters::dist_clust(const string& id, const string& id2) const{
    //Funció per consultar les distancies dins el mapa de 
    //distancies de clusters.
    		map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.find(id);
			map<string,double>::const_iterator it2 = it->second.find(id2);
			return it2->second;
}


pair<string,string> Cjt_clusters::min_dist() const {
    //Es busca els clusters a menor distancia i 
    //es retorna en una pair els dos clusters.
    double distancia = 101;
    pair<string,string> dists;
    for (map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.begin(); it != tabla_distancias_cluster.end(); ++it) {
        for (map<string,double>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                if (it2->second < distancia ){
                distancia = it2->second;
                dists.first = it->first;
                dists.second = it2->first;
                }
            }

        }
    return dists;

}

// Modificadores


void Cjt_clusters::inicialitza_clusters(Cjt_especies& conjunt,const bool ve_de_func) {
    //Establim els iteradors del conjunt d'especies per tal de poder fer el bucle
    //A cada iteració es modifica una string, agafant la id de una especie i es
    //crea un cluster a partir de la string i la introdueix al mapa de clusters.
    map_clusters.clear();
    tabla_distancias_cluster.clear();
    conjunt.inicio(); // Iterador del conjunt d'especies que apunta a la primera posició.
         while (not conjunt.final()) { //comprova que l'iterador no apunta al final
             string x;
             conjunt.actual(x); // La string x agafa el valor del iterador.
             Cluster clust(x);
             map_clusters.insert(make_pair(x, clust));
             conjunt.avanza(); //Avança posició del iterador.

        }
    //Es crea la taula de distancies a partir del conjunt.
    tabla_dist_clust(conjunt);
    if (ve_de_func) imprime_tabla_distancias();
}


void Cjt_clusters::ejecuta_paso_wpgma(const bool& a) {
    //S'executa el pas wpgma sempre i quan el tamany
    //del mapa de clusters sigui > 1.
    if (map_clusters.size() > 1) {
    pair<string,string> pair_dist = min_dist(); //pair amb els dos clusters a menor distancia.
    afegeix_especie_clusters(pair_dist); //Es fica els dos clusters i es fusionen en un nou cluster.
    elimina_especie_clusters(pair_dist.first); //S'elimina el cluster.
    elimina_especie_clusters(pair_dist.second); //S'elimina el cluster.
    if (a) imprime_tabla_distancias();
    }
    else cout << "ERROR: num_clusters <= 1" << endl;
}
 

//  Lectura i escriptura


void Cjt_clusters::imprime_cluster(string id) const {
    //Es posa un iterador apuntant al cluster indicat
    //Si no apunta al final, s'imprimeix, sino surt un missatge d'error.
    map<string,Cluster>::const_iterator it = map_clusters.find(id);
    if (it == map_clusters.end()) cout << "ERROR: El cluster " << id << " no existe." << endl;
    else{
        it->second.escriure();
    }    
}


void Cjt_clusters::imprime_tabla_distancias() const {
	//Inv: És situa un iterador apuntant a la primera posició del
	//mapa de distancies. Avançarà una posició fins que el punter apunti al final.
	//A cada iteració s'impreix un identificador de especie i s'executa un segon bucle.
	for(map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.begin(); it != tabla_distancias_cluster.end(); ++it) {
		cout << it->first << ":";
    	//Inv: És situa un iterador apuntant a la primera posició del
		//map interior del map de distancies d'especies. Avançarà una posició fins que el punter apunti al final.
		//A cada iteració s'impreix un identificador d'especie del map interior i la distancia respecte les dues especies.
		for (map<string,double>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
				cout << " " << it2->first << " (" << it2->second << ")"; 
		}
		cout << endl;
	}
}


void Cjt_clusters::imprime_arbol_filogenetico(Cjt_especies& conjunt) {
    //el bool serveix per imprimir cada cop que executem el pas wpgma.
    //fem un bucle fins que només quedi un element al mapa de clusters
    bool fals = false;
    inicialitza_clusters(conjunt,fals);

    if (map_clusters.size() != 0) {
    while (map_clusters.size() > 1) {
        ejecuta_paso_wpgma(fals);
    }
    map<string,Cluster>::const_iterator it = map_clusters.begin();
    it->second.escriure(); //escriu el cluster resultant.
    }
    else cout << "ERROR: El conjunto de clusters es vacio." << endl;

}

// Mètodes privats


void Cjt_clusters::tabla_dist_clust(const Cjt_especies& conjunt) {
    //Consulta mitjançant el conjunt de especies les distancies entre elles per 
    //passar-les al conjunt de clusters.
    for (map<string,Cluster>::const_iterator it = map_clusters.begin(); it != map_clusters.end(); ++it) {
        map<string, double> aux;
        for (map<string,Cluster>::const_iterator it2 = it; it2 != map_clusters.end(); ++it2) {
            if (it->first != it2->first) { //Comprova que el iterador sigui diferent al segon iterador.
            double x = conjunt.calcular_distancia(it->first, it2->first);
            aux.insert(make_pair(it2->first, x));
            }
        }
        tabla_distancias_cluster.insert(make_pair(it->first, aux));
    }
}


void Cjt_clusters::afegeix_especie_clusters(const pair<string,string>& dist) {
    //Aquí es modifica les distancies dels clusters fent servir
    //la formula de WPGMA.
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



void Cjt_clusters::elimina_especie_clusters(const string& id) {
    //Es posiciona un iterador apuntant a la posició de l'id demanat. El nom de l'iterador era per donar humor al còdig.
    map<string, Cluster>::const_iterator it_peix = map_clusters.find(id);
	map_clusters.erase(it_peix);
    //Es posiciona un iterador apuntant a la posició de l'id demanat. 
	map<string,map<string,double>>::const_iterator it = tabla_distancias_cluster.find(id);
    //Es posiciona un iterador apuntant a la primera posició del mapa de distancies.
	//Inv: Farà tantes iteracions fins que l'iterador sigui igual al primer que hem buscat. Així ens
	//estalviem bucles innecessaris. Aquest bucle elimina la especie demanada del map interior.
	for (map<string,map<string,double>>::iterator it2 = tabla_distancias_cluster.begin(); it2 != it; ++it2) {
			it2->second.erase(it2->second.find(id));
		}
	//Eliminem la especie del mapa gran de la taula de distancies.
	tabla_distancias_cluster.erase(it);

}



