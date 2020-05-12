/** @author Xavier Coll Ribas
 * 	@brief El main del programa
 * 	@file program.cc
 */

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
#include "Cjt_clusters.hh"
#include "Cjt_especies.hh"
using namespace std;


/** @brief El main del programa */
int main() {
	int k; // k del kmer;
	cin >> k;
	
	Cjt_especies conjunt;
	Cjt_clusters cjt_clusters;
	Especie especie;
	especie.set_parametro(k);
	
	string opcio;
	cin >> opcio;

	while (opcio != "fin") {
		string id, id2, gen;
	
		if (opcio == "crea_especie") {
			cin >> id >> gen;
			cout << "# " << opcio << " " << id << " " << gen << endl;
			if (conjunt.existeix_especie(id)) cout << "ERROR: La especie " << id << " ya existe." << endl;
			else {
			conjunt.crea_especie(id,gen);
			}
			cout << endl;
		}
		
		else if (opcio == "obtener_gen") {
			cin >> id;
			cout << "# " << opcio << " " << id << endl;
			if (conjunt.existeix_especie(id)) conjunt.obtener_gen(id);
			else cout << "ERROR: La especie " << id << " no existe." << endl;
			cout << endl;

		}
		else if (opcio == "distancia") {
			cin >> id >> id2;
			cout << "# " << opcio << " " << id << " " << id2 << endl;
			if (conjunt.calcular_distancia(id,id2) == -1) 	cout << "ERROR: La especie " << id << " y la especie " << id2 << " no existen." << endl;
			else if (conjunt.calcular_distancia(id,id2) == -2) 	cout << "ERROR: La especie " << id << " no existe." << endl;
			else if (conjunt.calcular_distancia(id,id2) == -3)	cout << "ERROR: La especie " << id2 << " no existe." << endl;
			else cout << conjunt.calcular_distancia(id,id2) << endl;
			
			cout << endl;
		}
		else if (opcio == "elimina_especie") {
			cin >> id;
			cout << "# " << opcio << " " << id << endl;
			if (not conjunt.existeix_especie(id)) cout << "ERROR: La especie " << id << " no existe." << endl;
			else conjunt.elimina_especie(id);
			cout << endl;
		}
		else if (opcio == "existe_especie") {
			cin >> id;
			cout << "# " << opcio << " " << id <<endl;
			if (conjunt.existeix_especie(id)) cout << "SI" << endl;
			else cout << "NO" << endl;
			cout << endl;
		}
		else if (opcio == "lee_cjt_especies") {
			cout << "# " << opcio <<  endl;
			conjunt.lee_cjt_especies();
			cout << endl;
		}
		else if (opcio == "imprime_cjt_especies") {
			cout << "# " << opcio << endl;
			conjunt.imprime_cjt_especies();
		cout << endl;
		}
		else if (opcio == "tabla_distancias") {
			cout << "# " << opcio << endl;
			conjunt.tabla_distancias();
			cout << endl;
		}
		else if (opcio == "inicializa_clusters") {
			cout << "# " << opcio << endl;
			bool a = true;
			cjt_clusters.inicialitza_clusters(conjunt, a);
			cout << endl;
		}
		else if (opcio == "ejecuta_paso_wpgma") {
			cout << "# " << opcio << endl;
			bool a = true;
			cjt_clusters.ejecuta_paso_wpgma(a);
			cout << endl;
		}
		else if (opcio == "imprime_cluster") {

			cin >> id;
			cout << "# " << opcio << " " << id << endl;
			cjt_clusters.imprime_cluster(id);
			cout << endl;
		}
		else if (opcio == "imprime_arbol_filogenetico") {
			cout << "# " << opcio << endl;
			cjt_clusters.imprime_arbol_filogenetico(conjunt);
			cout << endl;
			
		}
	cin >> opcio;
	}

}
