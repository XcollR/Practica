/** @file Cjt_clusters.hh
	@author Xavier Coll Ribas
	@brief Especificació de la classe <em>Cjt_clusters</em>
*/

#ifndef CJT_CLUSTERS_HH
#define CJT_CLUSTER_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include "BinTree.hh"
#endif
#include "Cluster.hh"
using namespace std;

/** @brief <em>Crea un conjunt de clusters</em> */
class Cjt_clusters {

private: 
/**	
 * 	@param Mapa on es guarden els clusters resultants. La clau es un string i la dada un Cluster
*/
	map<string, Cluster> map_clusters;
/**	
 * 	@param Mapa on es guarden les distancies entre clusters. És un nested map.
*/	
	map<string, map<string, double> > tabla_distancias_cluster; 
	
	void tabla_dist_clust(const Cjt_especies& conjunt); // funcion para calcular las distancias entre clusters
	
	void actualizar_tabla_clusters(); // actualiza la tabla despues de cada paso wpgma

	void imprime_tabla_distancias() const;

	pair<string,string> min_dist();

	double dist_clust(const string& id, const string& id2) const;

	bool ja_fet;



	
public:

/**	@brief Imprimeix el cluster indicat.
 * 
 * 	@brief <b>Precondició: </b>Existeix el cluster indicat.
 * 
 * 	@brief <b>Postcondició: </b>S'ha imprès el cluster indicat.
 * 
 * 	@param string id
 */
	void imprime_cluster(string id) const;
	
/** @brief Inicialitza els clusters del conjunt.
 * 
 * 	\pre Existeix un conjunt d'especies.
 * 
 * 	\post Els clusters s'han inicialitzat.
 * 
 */
	void inicialitza_clusters(Cjt_especies& conjunt, const bool ve_de_func);

/** @brief Fusiona els clusters que estan a menor distància
 * 
 * 	@brief <b>Precondició: </b>Cert.	
 * 
 * 	@brief <b>Postcondició: </b>S'ha fusionat els clusters i s'imprimeix la taula de distàncies.
 */
	void ejecuta_paso_wpgma(const bool& a);
	
/** @brief Imprimeix l'arbre filogenètic.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
 * 	@brief <b>Postcondició: </b>S'ha imprès l'arbre filogenètic pel canal standart de sortida.
 */
	void imprime_arbol_filogenetico(Cjt_especies& conjunt);

	void elimina_especie_clusters(const string& id);

	void afegeix_especie_clusters(const pair<string,string>& dist); // Recalcular taula distancies si s'afegeix un element.

	void ejecuta_paso_wpgm_sense_imprimir();




	
};

#endif
