
/** @file Cjt_clusters.hh
	@author Xavier Coll Ribas
	@brief Especificació de la classe Cjt_clusters.

*/

#ifndef CJT_CLUSTERS_HH
#define CJT_CLUSTERS_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include "BinTree.hh"
#endif
#include "Cluster.hh"
using namespace std;

/**	@class Cjt_clusters
 *	@brief Representa un conjunt de clústers.

 * 	Ofereix la possibilitat d'ajuntar clústers per tal d'anar 
 * 	creant l'arbre filogenètic. També pots demanar imprimir un 
 * 	clúster determinat si existeix i imprimir l'arbre resultant.
 * 	També ofereix una taula de distancies entre clústers. Els clústers
 * 	es generen mitjançant la sincronització amb un conjunt d'especies 
 * 	i es compleix amb la funció inicializa_clústers.
 * 
 * 	\invariant El conjunt de clústers tindrà un identificador
 * 	que serà el mateix que el d'una especie i sempre estarà ordenat
	alfabèticament, aquest no té mida màxima ni mínima. La taula
	de distànciesentre clústers té els mateixos identificadors que 
	els d'especie i també està ordenada alfabèticament.
 */

class Cjt_clusters {

private: 
/**	
 * 	@brief Estructura de dades on es guarden els clústers resultants. Conté un identificador i un clúster.
*/
	map<string, Cluster> map_clusters;
/**	
 * 	@brief Estructura de dades on guardem les distancies entre clústers.
*/	
	map<string, map<string, double> > tabla_distancias_cluster; 

/**	@brief Passa les distàncies entre espècies a la taula de distàncies entre clústers.
 * 	\pre Cert.
 * 	\post S'ha passat totes les distancies entre especies al conjunt de clústers.
 * 	\param Cjt_especies Entra un objecte del tipus conjunt especies.
 */	
	void tabla_dist_clust(const Cjt_especies& conjunt); 


/** @brief Afegeix la fusió dels dos clústers al conjunt de clústers i a la taula de distàncies.
 * 	\pre El pair no és buit.	
 * 	\post S'ha fusionat els clústers.
 */
	void afegeix_especie_clusters(const pair<string,string>& dist);

/** @brief Elimina la especie indicada del conjunt de clústers i de la taula de distàncies.
 * 	\pre El clúster a eliminar existeix.	
 * 	\post S'ha eliminat el clúster del conjunt de clústers i de la taula de distancies.
 */

	void elimina_especie_clusters(const string& id);


	
public:


	// Constructores

/**
 * 	@brief Crea un conjunt de clústers buit. 
 *	\pre Cert.
	\post El resultat és un conjunt de clústers buit.
*/
	Cjt_clusters();

	// Consultores

/**	@brief Busca la distància entre els clústers demanats.
 * 	\pre Els dos clústers demanats existeixen.
 * 	\post S'ha retornat la distància entre els clústers.
 * 	\param string Entren per referència constant dos string amb
 * 	els identificadors dels clústers.
 * 	\return Retorna un double amb la distància que els separa
 * 	genèticament. Retorna -1 si algun dels dos clústers no existeix.
 */
	double dist_clust(const string& id, const string& id2) const;


/**	@brief Calcula la distància mínima entre clústers.
 * 	\pre Cert.
 * 	\post S'ha calculat la distancia mínima entre els clústers del conjunt.
 * 	\return Retorna un pair. Els dos elements són de tipu string, retorna els
 * 	identificadors de clústers a menor distancia.
 */	
	pair<string,string> min_dist() const;


	// Modificadores

/** @brief Inicialitza els clústers del conjunt.
 * 	\pre Existeix un conjunt d'especies.
 * 	\post Els clústers s'han inicialitzat i estan dins del conjunt de clústers
 * 	ordenats alfabèticament.
 *  \param Cjt_especies Entra un conjunt d'especies per referència.
 * 	\param Bool El booleà té una gran importància, si bool = true imprimirà
 * 	la taula de distàncies entre clústers, en cas que bool = fals, la funció no imprimirà res.
 */
	void inicialitza_clusters(Cjt_especies& conjunt, const bool ve_de_func);


/** @brief Fusiona els clústers que estan a menor distància
 * 	\pre La mida del conjunt de clústers és més gran que 1.	
 * 	\post S'ha fusionat els clústers i s'ha actualitzat la taula de distàncies.
 * 	\param bool. Si el bool = true, s'imprimeix la taula de 
 * 	distancies entre clústers resultant. 
 */
	void ejecuta_paso_wpgma(const bool& a);


	// Lectura i escriptura
	
/**	@brief Imprimeix el clúster indicat.
 * 	\pre Existeix el clúster indicat.
 * 	\post S'ha imprès el clúster indicat.
 * 	\param string id
 */
	void imprime_cluster(string id) const;
	

/**	@brief Imprimeix la taula de distàncies entre clústers.
 * 	\pre Cert.
 * 	\post S'ha imprès totes les distàncies entre clústers.
 */		
	void imprime_tabla_distancias() const;
	
/** @brief Imprimeix l'arbre filogenètic dels clústers resultants.
 * 	\pre Cert.
 * 	\post S'ha imprès l'arbre filogenètic de clústers pel canal standart de sortida.
 */
	void imprime_arbol_filogenetico(Cjt_especies& conjunt);

	
};

#endif
