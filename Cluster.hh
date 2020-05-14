/** @file Cluster.hh
 * 	@author Xavier Coll Ribas
 * 	@brief Especificació de la classe <em>Cluster</em>
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
    @brief Representa un cluster d'un arbre binari, un node
	aquest pot tenir "fills".
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
	\param String. Un identificador pel cluster.
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

	
	// Lectura i Escriptura
		
/**
 * 	@brief Escriu l'arbre binari del cluster del parametre implícit. 
 *	\pre Cert.
	\post S'ha escrit l'arbre binàri.
*/	
		
	void escriure() const;


};


#endif