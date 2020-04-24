/** @file Especie.hh
	@author Xavier Coll Ribas
	@brief Especificació de la classe <em>Especie</em>
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;


/** @brief <em>Crea una espècie</em> */

class Especie {
	
private: 
		
	string gen; // gen de la espècie.

	static int k_num; //k per fer els k-meros.

	map<string, int> k_meros; // k-meros de la especie.
	
	map<string,int> return_k_meros() const; // retorn el map de k-meros.

	map<string, int> kmer(const string& gen, const int& k_num); //funció kmer
	
	double cardinal(const map<string, int>& map1); // Retorna el cardinal d'un conjunt


public: 
	
		// Constructores
		
/**
 * 	@brief Crea una especie sense identificador ni gen.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat es una especie sense identificador, gen i kmeros.
	
*/

	Especie();
/**
 * 	@brief Crea una especie amb el gen i l'identificador indicat.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat es una especie amb identificador, gen i kmeros.
	
*/
	Especie(string gen1);
/**
 * 	@brief Introdueix el paràmetre k com a static per calcular els kmeros.
 * 
 * 	@brief <b>Precondició: </b>Hi ha una k al canal d'entrada.
 * 
 * 	@brief <b>Postcondició: </b>S'ha establert la k per calcular els kmeros.
*/

	static void set_parametro(const int& k_dato);
	
	
		// Consultores


	
/** 
 * 	@brief Retorna el gen de la espècie.

 * 	@brief <b>Precondició: </b>El parametre implicit te gen.
 * 
	@brief <b>Postcondició: </b>El resultat es el gen del parametre implicit 
	
	@return string
*/
	string consultar_gen() const;

/** 
 * 	@brief Retorna un double amb la distancia entre la espècie del paràmetre implícit i la que ha entrat per la funció.

 * 	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat és la distancia entre les dues espècies.
	
	@return double
*/	

	double distancia(const Especie& esp);

		// Lectura i Escriptura

	
/** @brief Escriu la espècie del paràmetre implícit.
 * 
 * 	@brief <b>Precondició: </b>Cert
 
	@brief <b>Postcondició </b>S'han escrit els atributs del parametre implicit al canal estandard de sortida.
*/

	void escriure() const;
	
};

#endif
