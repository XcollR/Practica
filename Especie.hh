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

/**
 * 	@param String. És el gen de la espècie.
*/
	string gen; 
/**
 * 	@param Static @param int. El tamany de la k per separar els gens en els k-meros.
*/
	static int k_num; 
/**
 * 	@param Mapa. Mapa on es guarden els k-meros de la espècie.
*/
	map<string, int> k_meros; 
	
/**
 * 	@brief Calcula els kmeros d'una espècie a partir del seu gen. 
 * 
 * 	@brief <b>Precondició: </b>El paràmetre implícit és un string amb longitud >= k.
 * 
 * 	@brief <b>Postcondició: </b>S'ha calculat els k-meros i s'han guardat.
*/
	void kmer(); 
	
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

	double distancia(const Especie& esp) const;

		// Lectura i Escriptura

	
/** @brief Escriu la espècie del paràmetre implícit.
 * 
 * 	@brief <b>Precondició: </b>Cert
 
	@brief <b>Postcondició </b>S'han escrit els atributs del parametre implicit al canal estandard de sortida.
*/

	void escriure() const;
	
};

#endif
