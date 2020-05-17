/** @file Cluster.hh
 * 	@author Xavier Coll Ribas
 * 	@brief Especificació de la classe Cluster.
 */
#ifndef CLUSTER_HH
#define CLUSTER_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include "BinTree.hh"
#endif
#include "Cjt_especies.hh"
using namespace std;

/** @class Cluster
    @brief Representa un cluster d'un arbre binari

	Ofereix les opcions d'imprimir l'arbre del cluster amb les
	distancies respecte als seus fills.
	També l'opció de crear un cluster a partir de la fusió
	de dos altres.

	\invariant Els clusters contenen una única espècie o bé estàn formats
	per altres clusters. Així mateix, un cluster és assimilable a un
	arbre binari on té espècies a les fulles. 
*/

class Cluster {

private:


/** @brief Arbre binari format per pairs */
	BinTree< pair<string, double> > cluster; 

/** @brief Funció recursiva cridada per la funcio escriure() per tal de 
 * 	poder fer la escriptura recursiva de l'arbre del cluster.
 * 	\pre L'arbre el qual es vol escriure no té el node principal buit. Aquesta funció escriura
 * 	fins que és trobi un node buit. En cas que els nodes esquerre i dreta siguin buits, no escriurà la
 * 	distancià respecte als seus fills degut a no en té.
 * 	\post S'ha escrit l'arbre binàri amb les condicions indicades abans.
 * 	\param BinTree. Arbre binàri del cluster.
 */
  	void inm_escriure(const BinTree<pair<string,double>>& a) const;


public:


	// Constructores

/**
 * 	@brief Crea un cluster a partir d'una espècie. 
 *	\pre Cert.
	\post El resultat és un cluster de la especie demanada.
	\param String. Un identificador del cluster.
*/	
	
	Cluster(const string& id);

/**
 * 	@brief Crea un cluster a partir de la fusió de dos altres. 
 *	\pre Els dos clusters existeixen i no són buits.
	\post El resultat és un cluster amb la fusió dels dos altres.
	\param Cluster. Dos objectes de tipus Cluster.
*/	
	
	Cluster(const Cluster clus1, const Cluster Clus2, const double& dist);
	
	// Consultores

	// Modificadores

	// Lectura i Escriptura
		
/**
 * 	@brief Escriu el cluster que entra pel paràmetre implícit. 
 *	\pre Cert.
	\post S'ha escrit el cluster.
*/	
		
	void escriure() const;


};

#endif