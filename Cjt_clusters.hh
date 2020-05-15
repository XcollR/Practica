/**
 *  @mainpage <b>Descripció de la pràctica</b>
 *  <b>Què és un arbre filogenètic?</b>
 * 
 * 	En la biologia evolutiva, antropologia, lingüística i moltes altres disciplines científiques un
 *  dels problemes principals que s'aborden és la construcció d'arbres filogenètics, diagrames
 *  que representen de manera esquemàtica les relacions evolutives entre un conjunt de N
 *  entitats (en biologia evolutiva se sol parlar d'espècies, tot i que sovint no es tracti
 *  d'espècies sinó de famílies o ordres). L'arbre filogenètic es construeix en base 
 *  a les similituds i diferències en les característiques físiques o genètiques de les N entitats.
 *  En un arbre filogenètic arrelat cada node amb descendents representa l'ancestre
 *  comú més recent dels seus descendents, i és usual que la longitud de les arestes / branques de l'
 *  arbre sigui proporcional a el temps transcorregut entre les entitats representades. els nodes
 *  interns són entitats hipotètiques, ja que no poden ser directament observades, només les N
 *  entitats de les fulles de l'arbre són les que coneixem.
 *  La construcció de l'arbre filogenètic que millor explica les dades observades, optimitzant
 *  un cert criteri, és un problema computacionalment difícil, en el sentit que el cost
 *  dels càlculs necessaris creix exponencialment amb N. A més molts altres problemes
 *  compliquen l'obtenció d'arbres filogenètics que reflecteixin la història evolutiva amb precisió:
 *  dades sobre les entitats inexactes, hibridacions, evolució convergent,. . .
 *  Per aquesta raó s'han desenvolupat nombrosos mètodes aproximats que generen arbres
 *  filogenètics de manera eficient i que s'aproximen molt bé a l'arbre òptim en la majoria
 *  de casos, però no sempre. En aquesta pràctica el nostre objectiu serà construir un programa i
 *  els mòduls necessaris per a construir l'arbre filogenètic per a un conjunt de N espècies
 *  utilitzant un d'aquests mètodes aproximats: el mètode conegut com WPGMA (Weighted
 *  pair group with arithmetic mean).
 *  
 * 	Aquest document hi trobarem les diverses classes
 *  utilitzades per poder executar bé el program.cc. Hi tenim
 *  4 classes:
 * 
 *      -Especie: Representa una especie amb el seu gen.
 * 
 *      -Cjt_especies: Representa un conjunt d'especies, amb identificador i especie.
 * 
 *      -Cluster: Representa un cluster d'un arbre binari.
 * 
 *      -Cjt_clusters: Representa un conjunt de clusters amb identificador.
 * 
 *  Amb aquestes classes podrem crear un conjunt d'especies, i fer diverses operacions amb elles, ja
 *  sigui eliminar especies, consultar distàncies, imprimir una taula de distàncies entre especies...
 *  Amb la classe Cjt_cluster i cluster, podrem anar creant un arbre binari on aquest serà el resultat
 *  d'aplicar l'algorisme WPGMA.
 * 
 *  <b>La descripció del programa principal d'aquesta pràctica és la següent</b>:
 *  Donat un conjunt d'especies, hem programat un conjunt de funcions per anar modificant el
 *  conjunt i anar creant l'arbre filogenetic.
 */

/** @file Cjt_clusters.hh
	@author Xavier Coll Ribas
	@brief Especificació de la classe Cjt_clusters.
*/

#ifndef CJT_CLUSTERS_HH
#define CJT_CLUSTERS_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include "BinTree.hh"
#endif
#include "Cluster.hh"
using namespace std;

/**	@class Cjt_clusters
 *	@brief Representa un conjunt de clusters.

 * 	Ofereix la possibilitat d'ajuntar clusters per tal d'anar 
 * 	creant l'arbre filogenètic. També pots demanar imprimir un 
 * 	cluster determinat si existeix i imprimir l'arbre resultant.
 * 	També ofereix una taula de distancies entre clusters. Els clusters
 * 	es generen mitjançant la sincronització amb un conjunt d'especies 
 * 	i es compleix amb la funció inicializa_clusters.
 */

class Cjt_clusters {

private: 
/**	
 * 	@brief Mapa on es guarden els clusters resultants. La clau es un string i la dada un Cluster
*/
	map<string, Cluster> map_clusters;
/**	
 * 	@brief Nested map on es guarden les distancies entre clusters. És un nested map.
*/	
	map<string, map<string, double> > tabla_distancias_cluster; 

/**	@brief Imprimeix el cluster indicat.
 * 	\pre Cert.
 * 	\post S'ha passat totes les distancies entre especies al conjunt de clusters.
 * 	\param Cjt_especies Entra un objecte del tipus conjunt especies.
 */	
	void tabla_dist_clust(const Cjt_especies& conjunt); // funcion para calcular las distancias entre clusters



/** @brief Afegeix la fusió dels dos clusters al mapa de clusters i a la taula de distancies.
 * 	\pre El pair no és buit.	
 * 	\post S'ha fusionat els clusters.
 */
	void afegeix_especie_clusters(const pair<string,string>& dist);

/** @brief Elimina la especie indicada del conjunt del mapa de clusters i de la taula de distàncies.
 * 	\pre La especie a eliminar existeix.	
 * 	\post S'ha eliminat la especie del mapa de clusters i la taula de distancies.
 */

	void elimina_especie_clusters(const string& id);


	
public:


	// Constructores

/**
 * 	@brief Crea un conjunt de clusters buit. 
 *	\pre Cert.
	\post El resultat és un conjunt de clusters buit.
*/
	Cjt_clusters();

	// Consultores

/**	@brief Busca la distància entre els clusters demanats.
 * 	\pre Els dos clusters demanats existeixen.
 * 	\post S'ha retornat la distància entre els clusters.
 * 	\param string Entren per referència constant dos string amb
 * 	els identificadors dels clusters.
 * 	\return Retorna un double amb la distància que els separa
 * 	genèticament. Retorna -1 si algun dels dos clusters no existeix.
 */
	double dist_clust(const string& id, const string& id2) const;


/**	@brief Calcula la distancia mínima entre Clusters.
 * 	\pre Cert.
 * 	\post S'ha calculat la distancia entre dos clusters.
 * 	\return Retorna un pair. Els dos elements són de tipu string, retorna els
 * 	identificadors de clusters a menor distancia.
 */	
	pair<string,string> min_dist() const;


	// Modificadores


/** @brief Fusiona els clusters que estan a menor distància
 * 	\pre Cert.	
 * 	\post S'ha fusionat els clusters. 
 * 	\param bool. Si el bool = true, s'imprimeix la taula de 
 * 	distancies entre clusters resultant. 
 */
	void ejecuta_paso_wpgma(const bool& a);


	// Lectura i escriptura
	
/**	@brief Imprimeix el cluster indicat.
 * 	\pre Existeix el cluster indicat.
 * 	\post S'ha imprès el cluster indicat.
 * 	\param string id
 */
	void imprime_cluster(string id) const;
	
/** @brief Inicialitza els clusters del conjunt.
 * 	\pre Existeix un conjunt d'especies.
 * 	\post Els clusters s'han inicialitzat.
 *  \param Cjt_especies Entra un conjunt d'especies per referència.
 * 	\param Bool El booleà té una gran importància, si bool = true imprimirà
 * 	la taula de distàncies entre clusters, en cas que bool = fals, la funció no imprimirà res.
 */
	void inicialitza_clusters(Cjt_especies& conjunt, const bool ve_de_func);

/**	@brief Imprimeix la taula de distàncies entre clusters.
 * 	\pre Cert.
 * 	\post S'ha imprès totes les distàncies entre clusters.
 */		
	void imprime_tabla_distancias() const;
	
/** @brief Imprimeix l'arbre filogenètic.
 * 	\pre Cert.
 * 	\post S'ha imprès l'arbre filogenètic pel canal standart de sortida.
 */
	void imprime_arbol_filogenetico(Cjt_especies& conjunt);







	
};

#endif
