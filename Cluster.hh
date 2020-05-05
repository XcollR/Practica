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


/** @brief <em>Crea un cluster</em> */
class Cluster {

private:

	BinTree< pair<string, double> > cluster; // 

	string identificador;
	
	void distancia_entre_clusters(const Cluster& clus1, const Cluster& clus2);

		
public:
		// Constructores
/**
 * 	@brief Crea un cluster buit. 
 * 
 *	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat és un cluster buit.
*/	
	Cluster();

/**
 * 	@brief Crea un cluster a partir d'una espècie. 
 * 
 *	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat és un cluster de la especie demanada.
*/	
	
	Cluster(const string& id);
/**
 * 	@brief Crea un cluster a partir de la fusió de dos altres. 
 * 
 *	@brief <b>Precondició: </b>Els dos clusters existeixen i no són buits.
 * 
	@brief <b>Postcondició: </b>El resultat és un cluster amb la fusió dels dos altres.
*/	
	
	Cluster(const Cluster clus1, const Cluster Clus2, const double& dist);
	
		// Consultores

/**
 * 	@brief Consulta el subarbre del cluster, amb els fills dret i esquerra. 
 * 
 *	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>S'ha consultat el subarbre.
*/	
	void sub_arbre_cluster(const Cluster& clus1);
	
		// Lectura i Escriptura
		
/**
 * 	@brief Escriu un cluster. 
 * 
 *	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>S'ha escrit el cluster.
*/	
		
	void escriure() const;

  	void inm_escriure(const BinTree<pair<string,double>>& a) const;



	

};


#endif
