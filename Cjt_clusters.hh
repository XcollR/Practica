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
	
	map<string, Cluster> map_clusters; // mapa amb id de cluster i el cluster;
	
	map<string, map<string, double> > tabla_distancias_cluster; // tabla distancias entre clusters
	
	void tabla_dist_clust(const Cjt_especies& conjunt); // funcion para calcular las distancias entre clusters
	
	void actualizar_tabla_clusters(); // actualiza la tabla despues de cada paso wpgma

	void imprime_tabla_distancias() const;

	double min_dist();




	
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
 * 	@brief <b>Precondició: </b>Existeix un conjunt d'especies.
 * 
 * 	@brief <b>Postcondició: </b>Els clusters s'han inicialitzat.
 * 
 */
	void inicialitza_clusters(Cjt_especies& conjunt);

/** @brief Fusiona els clusters que estan a menor distància
 * 
 * 	@brief <b>Precondició: </b>Cert.	
 * 
 * 	@brief <b>Postcondició: </b>S'ha fusionat els clusters i s'imprimeix la taula de distàncies.
 */
	void ejecuta_paso_wpgm();
	
/** @brief Imprimeix l'arbre filogenètic.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
 * 	@brief <b>Postcondició: </b>S'ha imprès l'arbre filogenètic pel canal standart de sortida.
 */
	void imprime_arbol_filogenetico() const;

	void elimina_especie_clusters(const string& id);

	void afegeix_especie_clusters(const string& c1, const string& c2, const double& dist); // Recalcular taula distancies si s'afegeix un element.


	
};

#endif
