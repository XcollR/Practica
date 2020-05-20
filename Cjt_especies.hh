/** @file Cjt_especies.hh
 * 	@author Xavier Coll Ribas
 * 	@brief Especificació de la classe Cjt_especies.
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


/** @class Cjt_especies
 *  @brief Representa un conjunt d'espècies ordenades alfabèticament.
 * 
 * 	Ofereix la possibilitat de calcular distàncies entre diferents espècies
 * 	i modificar el conjunt, ja sigui creant noves espècies o eliminant. Es pot 
 * 	consultar el gen d'una espècie i si una espècie existeix.També
 * 	inclou la possibilitat d'imprimir una taula de distancies entre espècies.
 * 
 * 	\invariant El conjunt d'espècies sempre estarà ordenat alfabèticament per un identificador d'espècie,
 * 	no té mida màxima ni mida mínima. La taula de distàncies també 
 * 	tindrà el mateix identificador que la espècie i sempre s'imprimirà en ordre
 * 	alfabètic. Quan es llegeix un conjunt d'espècies, es declarà la mida amb una,
 * 	una variable n >= 0.
 */
 
class Cjt_especies {
	
private:

	
/** 
 * 	@brief Estructura de dades on guardem les espècies del conjunt d'espècies.
*/
	map<string,Especie> cjt_especies; 
/** 
 * 	@brief Estructura de dades on guardem les distancies entre les espècies.
*/			
	map<string, map<string,double> > taula_distancies; 

/**	
 * 	@brief Actualitza la taula de distàncies si s'elimina una espècie.
	\pre La espècie la qual es vol eliminar existeix dins la taula de distàncies.
	\post S'ha actualitzat la taula.
*/
	void elimina_especie_tabla_dist(const string& id); 

/**	
 * 	@brief Actualitza la taula de distàncies si s'afegeix una espècie.
	\pre La espècie la qual es vol afegir existeix no existeix dins la taula de distàncies.
	\post S'ha actualitzat la taula.
*/
	void afegeix_especie_tabla_dist(const string& id); 
	
/**
 * 	@brief Iterator. Iterador del mapa d'espècies.
*/
	map<string, Especie>::const_iterator it;

	
public:


	// Constructores
	

/**
 * 	@brief Crea un conjunt d'espècies buit. 
 *	\pre Cert.
	\post El resultat és un conjunt d'espècies buit i ordenat alfabèticament.
*/
	
	Cjt_especies();

	
	// Modificadores

/**	
 * 	@brief Crea una espècie i la introdueix al conjunt.
	\pre No existeix cap espècie amb el mateix identificador.
	\post S'ha creat una espècie i s'ha introduit al conjunt d'espècies. Aquest es manté ordenat.
*/
	
	void crea_especie(const string& id,const string& gen);



/** @brief Elimina la espècie indicada del conjunt d'espècies del paràmetre implícit.
 * 	\pre Cert.
 * 	\post La espècie s'ha eliminat del conjunt d'espècies.
 * 	@param string id
 */
 
	void elimina_especie(const string& id);	

	
	// Consultores
	

	
/**	@brief Consulta si existeix la espècie indicada al conjunt d'espècies.
 * 	\pre El id és un string vàlid.
 * 	\post El resultat indica si existèix la espècie dins el conjunt d'espècies.
 * 	\param string id
 * 	\return bool
 */
  
	bool existeix_especie(const string& id) const;	

/** @brief Consulta la distàncie entre dues espècies.
 * 	\pre Les dues espècies existeixen al conjunt.
 * 	\post Et retorna la distància entre dues espècies.
 * 	Excepcions: Si retorna -1 vol dir que les dues espècies no existèixen dins el conjunt d'espècies.
 *				Si retorna -2 vol dir que la espècie id no existeix dins el conjunt d'espècies.
  *				Si retorna -3 vol dir que la espècie id2 no existeix dins el conjunt d'espècies.

 * 	\param string id1
 * 	\param string id2
 * 	\return double
 */	
	double calcular_distancia(const string& id, const string& id2) const;

/** 
 * @brief Consulta el gen de la espècie demanada.
 * \pre La espècie existeix al conjunt d'espècies.
   \post S'ha mostrat el gen de la espècie.
   \param string
   \return string
  */
	void obtener_gen(const string& id) const;
	
	
	/** @brief Consulta si és el final del conjunt d'espècies del paràmetre implícit.
 * 	\pre Cert.
 * 	\post S'ha indicat si és el final del conjunt.
 * 	\return bool cert si apunta al final del conjunt, en cas contrari, fals.
 */

bool final();

/** @brief Apuntem al primer element del conjunt d'espècies del paràmetre implícit.
 * 	\pre Cert.
 * 	\post S'ha apuntat al primer element del conjunt.
 */
void inicio();

/** @brief El paràmetre explícit passa a tenir la informació del element apuntat en aquell moment.
 * 	\pre Cert.
 * 	\post El paràmetre explícit passa a tenir la informació del element apuntat en aquell moment.
 * 
 */
void actual(string& act);

/** @brief S'avança una espècie del conjunt.
 * 	\pre Cert.
 * 	\post Si no estem al final del conjunt, avancem una espècie.
 * 
 */
void avanza();
	

	// Lectura i Escriptura


/** @brief Lectura d'un conjunt d'espècies.
 	\pre Estan preparats al canal estandar d'entrada
	 un enter i les dades dels elements que llegirem.
	\post El paràmetre implícit conté un conjunt d'espècies llegits pel canal estàndar.	
 */
	void lee_cjt_especies();
	
/** @brief Escriptura del conjunt d'espècies.
  	\pre Cert.
	\post S'ha escrit pel canal estàndar de sortida les espècies
	del paràmetre implícit.
*/
	void imprime_cjt_especies() const;

/** @brief Escriu una taula de les distàncies entre espècies.
 * 	\pre Cert.
 * 	\post S'ha imprès la taula de distàncies.
 */

	void tabla_distancias()const;
	


};

#endif
