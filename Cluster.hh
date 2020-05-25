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
    @brief Representa un clúster.	

	Ofereix les opcions d'imprimir l'arbre del clúster amb les
	distancies respecte als seus fills.
	També l'opció de crear un clúster a partir de la fusió
	de dos altres.

	\invariant Els clústers contenen una única espècie o bé estàn formats
	per altres clústers. Així mateix, un clúster és assimilable a un
	arbre binari on té espècies a les fulles. 
*/

class Cluster {

private:


/** @brief Estructura de dades d'un clúster.  */
	BinTree< pair<string, double> > cluster; 

/** @brief Funció recursiva cridada per la funcio escriure() per tal de 
 * 	poder fer la escriptura recursiva d'un clúster.
 * 	\pre Cert.
 * 	\post Escriu a en preordre tal com indicat a la pràctica.
 * 	\param BinTree. Arbre binàri del clúster.
 */
  	static void inm_escriure(const BinTree<pair<string,double>>& a);


public:


	// Constructores

/**
 * 	@brief Crea un clúster a partir d'una espècie. 
 *	\pre Cert.
	\post El resultat és un clúster de la espècie demanada.
	\param String. Un identificador del clúster.
*/	
	
	Cluster(const string& id);

/**
 * 	@brief Crea un clúster a partir de la fusió de dos altres. 
 *	\pre Els dos clústers existeixen i no són buits.
	\post El resultat és un clúster amb la fusió dels dos altres.
	\param Cluster. Dos objectes de tipus clúster.
*/	
	
	Cluster(const Cluster clus1, const Cluster Clus2, const double& dist);
	
	// Consultores

	// Modificadores

	// Lectura i Escriptura
		
/**
 * 	@brief Escriu el clúster que entra pel paràmetre implícit. 
 *	\pre Cert.
	\post S'ha escrit el clúster.
*/	
		
	void escriure() const;


};

#endif