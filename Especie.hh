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
 * 	\pre El paràmetre implícit és un string amb longitud >= k.
 * 
 * 	\post S'ha calculat els k-meros i s'han guardat.
*/
	void kmer(); 
	
public: 
	
	// Constructores
		
/**
 * 	@brief Crea una especie sense identificador ni gen.
 * 
 *  \pre Cert.
 * 
	\post El resultat es una especie sense identificador, gen i kmeros.
	
*/

	Especie();
/**
 * 	@brief Crea una especie amb el gen i l'identificador indicat.
 * 
 * 	\pre Cert.
 * 
	\post El resultat es una especie amb identificador, gen i kmeros.
	
*/
	Especie(string gen1);

/**
 * 	@brief Introdueix el paràmetre k com a static per calcular els kmeros.
 * 
 * 	\pre Hi ha una k al canal d'entrada.
 * 
 * 	\post S'ha establert la k per calcular els kmeros.
*/

	static void set_parametro(const int& k_dato);



	// Consultores


	
/** 
 * 	@brief Retorna el gen de la espècie.

 * 	\pre El parametre implicit te gen.
 * 
	\post El resultat es el gen del parametre implicit 
	
	@return string
*/
	string consultar_gen() const;

/** 
 * 	@brief Retorna un double amb la distancia entre la espècie del paràmetre implícit i la que ha entrat per la funció.

 * 	\pre Cert.
 * 
	\post El resultat és la distancia entre les dues espècies.
	
	@return double
*/	

	double distancia(const Especie& esp) const;

		// Lectura i Escriptura

	
/** @brief Escriu la espècie del paràmetre implícit.
 * 
 * 	\pre Cert
 
	\post S'han escrit els atributs del parametre implicit al canal estandard de sortida.
*/

	void escriure() const;
	
};

#endif
