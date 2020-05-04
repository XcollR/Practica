/** @file Cjt_especies.hh
 * 	@author Xavier Coll Ribas
 * 	@brief Especificació de la classe <em>Cjt_especies</em>
*/


#ifndef CONJ_ESP_HH
#define CONJ_ESP_HH
#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <string>
#endif
#include "Especie.hh"
using namespace std;


/** @brief <em>Crea un conjunt d'especies. </em>
 */
 
class Cjt_especies {
	
private:
	// Tipus de mòdul: dades
	// Descripció del tipus: representa un conjunt d'especies ordenades per ordre alfabètic.
	

	map<string,Especie> cjt_especies; //vector on es guarda les espècies;
		
	int num_especies; // el num d'especies que tenim
			
	map<string, map<string,double> > taula_distancies; // map multidimensional on hi ha les distancies entre especies;
	
	void elimina_especie_tabla_dist(const string& id); // Recalcular taula distancies si s'elimina un element.

	void afegeix_especie_tabla_dist(const string& id); // Recalcular taula distancies si s'afegeix un element.
	
	map<string, Especie>::const_iterator it;
public:


	// Constructores
	

/**
 * 	@brief Crea un conjunt d'espècies buit. 
 * 
 *	@brief <b>Precondició: </b>Cert.
 * 
	@brief <b>Postcondició: </b>El resultat és un conjunt d'especies buit.
*/
	
	Cjt_especies();

	
	// Modificadores

/**	
 * 	@brief Crea una espècie i la introdueix al conjunt.
 * 
	@brief <b>Precondició: </b>No existeix cap espècie amb el mateix identificador.
	
	@brief <b>Postcondició: </b>S'ha creat una espècie.
*/
	

	void crea_especie(string id, string gen);



/** @brief Elimina la espècie indicada del conjunt d'espècies.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
 * 	@brief <b>Postcondició: </b>La espècie s'ha eliminat del paràmetre implícit.
 * 
 * 	@param string id
 */
 
	void elimina_especie(string id);	

	
	// Consultores
	

	
/**	@brief Consulta si existeix la espècie indicada.
 * 
 * 	@brief <b>Precondició </b>El id és un string vàlid.
 * 
 * 	@brief <b>Postcondició: </b>El resultat indica si existèix la espècie dins el conjunt d'espècies.
 * 
 * 	@param string id
 * 
 * 	@return bool
 */
  
	bool existeix_especie(string id) const;	

/** @brief Consulta la distàncie entre dues espècies.
 * 
 * 	@brief <b>Precondició: </b>Les dues espècies existeixen al conjunt.
 * 
 * 	@brief <b>Postcondició: </b>Et retorna la distància entre dues espècies
 * 
 * 	@param string id1
 * 
 * 	@param string id2
 * 
 * 	@return double
 */	
	double calcular_distancia(const string& id, const string& id2) const; //funció per calcular la distancia entre dues espècies

/** 
 * @brief Consulta el gen de la espècie demanada
 * 
 * @brief <b>Precondició: </b>La espècie existeix al conjunt d'espècies.

   @brief <b>Postcondició: </b>S'ha mostrat el gen de la espècie.
   
   @param string
   
   @return string
  */
	void obtener_gen(string id) const;
	
	// Lectura i Escriptura

/** @brief Escriu una taula de les distàncies entre espècies.
 * 
 * 	@brief <b>Precondició: </b>Cert.
 * 
 * 	@brief <b>Postcondició: </b>S'ha imprès la taula de distàncies.
 * 
 */

	void tabla_distancias()const;
	
/** @brief Lectura d'un conjunt d'espècies.
 * 
 	@brief <b>Precondició: </b>Estan preparats al canal estandar d'entrada
	 * un enter i les dades dels elements que llegirem.
	 * 
	@brief <b>Postcondició: </b>El paràmetre implícit conté un conjunt d'especies llegits pel canal estàndar.	
 */
	void lee_cjt_especies();
	
/** @brief Escriptura del conjunt d'espècies.
 * 	
  	@brief <b>Precondició: </b>Cert.
 *  
	@brief <b>Postcondició: </b>S'ha escrit pel canal estàndar de sortida les espècies
	 * del paràmetre implícit.
*/
	void imprime_cjt_especies() const;
	
int size()const;

bool final();

void inicio();

void actual(string& act);

void avanza();
	

};




#endif

