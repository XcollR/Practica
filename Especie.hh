/** @file Especie.hh
	@author Xavier Coll Ribas
	@brief Especificació de la classe Especie.
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;


/** @class Especie 
    @brief Representa una espècie.

	Ofereix la posibilitat de calcular la distància entre
	dues espècies, consultar el gen, i escriure el gen.
	Donat que hem d'establir un paràmetre k, tenim la necessitat
	de crear una constructora d'espècie buida per poder introduir la k.

	\invariant Una espècie sempre tindrà el gen de longitud >= k.
	La k serà sempre de longitud > 0.

*/

class Especie {
	
private: 

	/** @brief És el gen de la espècie. */
	string gen; 

  	/** @brief Tamany que indica el tamany dels paquets per separar el gen de la espècie (kmeros). */
	static int k_num; 

  	/** @brief Estructura de dades on guardem els k-meros de la espècie. */
	map<string, int> k_meros; 
	
/**
 * 	@brief Calcula els kmeros d'una espècie a partir del seu gen. 
 * 	\pre El paràmetre implícit és un string amb longitud >= k.
 * 	\post S'ha calculat els k-meros i s'han guardat.
*/
	void kmer(); 
	
	
public: 
	
	// Constructores
		
/**
 * 	@brief Crea una espècie sense identificador ni gen.
 *  \pre Cert.
	\post El resultat es una espècie sense identificador, gen i kmeros.
	
*/
	Especie();
/**
 * 	@brief Crea una espècie amb el gen i l'identificador indicat.
 * 	\pre Cert.
	\post El resultat es una espècie amb identificador, gen i kmeros.
	
*/
	Especie(const string& gen1);

/**
 * 	@brief Introdueix el paràmetre k com a static per calcular els k-meros.
 * 	\pre Hi ha una k al canal d'entrada.
 * 	\post S'ha establert la k per calcular els kmeros.
*/

	static void set_parametro(const int& k_dato);



	// Consultores

/** 
 * 	@brief Retorna el gen de la espècie.
 * 	\pre El parametre implícit té gen.
	\post El resultat és el gen del paràmetre implícit.
	\return string
*/
	string consultar_gen() const;

/** 
 * 	@brief Retorna un double amb la distància entre la espècie del paràmetre implícit i la que ha entrat al paràmetre explícit.
 * 	\pre Les dues espècies existeixen.
	\post El resultat és la distància entre les dues espècies.
	\return double. Distancia genètica entre les dues espècies.
*/	

	double distancia(const Especie& esp) const;

		// Lectura i Escriptura

	
/** @brief Escriu la espècie del paràmetre implícit.
 * 	\pre Cert
	\post S'han escrit els atributs del parametre implícit al canal estandard de sortida.
*/

	void escriure() const;
	
};

#endif

