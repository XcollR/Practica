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

/** @author Xavier Coll Ribas
 * 	@brief El main del programa
 * 	@file program.cc
 */

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
#include "Cjt_clusters.hh"
using namespace std;


/** @brief El main del programa */

int main() {
	// int k > 0
	int k; 
	cin >> k;
	
	Cjt_especies conjunt; // Iniciem un conjunt d'especies buit.
	Cjt_clusters cjt_clusters; // Iniciem un conjunt de clusters buit.
	Especie especie; // Iniciem una espècie buida. Només la farem servir per introduir el paràmetre k.
	especie.set_parametro(k);
	
	string opcio; // String per anar escollint les opcions del programa.
	cin >> opcio;

	// El programa acaba quan la string opcio == fin.
	while (opcio != "fin") {
		string id, id2, gen; // Declarem aquests string que són els que necessitarem 
							 // majoritariament al nostre programa.

		if (opcio == "crea_especie") {
			cin >> id >> gen; // El identificador de la especie amb el seu gen.
			cout << "# " << opcio << " " << id << " " << gen << endl;
			if (conjunt.existeix_especie(id)) cout << "ERROR: La especie " << id << " ya existe." << endl; // En cas que la especie ja existeixi dins el conjunt salta un missatge d'error.
			else {
			conjunt.crea_especie(id,gen);
			}
			cout << endl;
		}
		
		else if (opcio == "obtener_gen") {
			cin >> id; // El identificador de la especie que es vol consultar el gen.
			cout << "# " << opcio << " " << id << endl;
			if (conjunt.existeix_especie(id)) conjunt.obtener_gen(id);
			else cout << "ERROR: La especie " << id << " no existe." << endl; // En cas que la especie no existeix dins el conjunt, salta un missatge d'error.
			cout << endl;

		}
		else if (opcio == "distancia") {
			cin >> id >> id2; // Els dos identificadors de les especies les quals es vol consultar la distància.
			cout << "# " << opcio << " " << id << " " << id2 << endl;
			// Depenent el que ens retorni la funció calcular distància, tindrà un 
			// significat diferent. Consultar la documentació per més detalls.
			if (conjunt.calcular_distancia(id,id2) == -1) 	cout << "ERROR: La especie " << id << " y la especie " << id2 << " no existen." << endl;
			else if (conjunt.calcular_distancia(id,id2) == -2) 	cout << "ERROR: La especie " << id << " no existe." << endl;
			else if (conjunt.calcular_distancia(id,id2) == -3)	cout << "ERROR: La especie " << id2 << " no existe." << endl;
			else cout << conjunt.calcular_distancia(id,id2) << endl;
			
			cout << endl;
		}
		else if (opcio == "elimina_especie") {
			cin >> id; // El identificador de la especie la qual es vol eliminar.
			cout << "# " << opcio << " " << id << endl;
			if (not conjunt.existeix_especie(id)) cout << "ERROR: La especie " << id << " no existe." << endl; // Si la especie no existeix dins el conjunt, salta un missatge d'error.
			else conjunt.elimina_especie(id);
			cout << endl;
		}
		else if (opcio == "existe_especie") {
			cin >> id; // El identificador de la especie la qual es vol consultar si existeix.
			cout << "# " << opcio << " " << id <<endl;
			if (conjunt.existeix_especie(id)) cout << "SI" << endl;
			else cout << "NO" << endl;
			cout << endl;
		}
		else if (opcio == "lee_cjt_especies") {
			// Funció que llegeix les especies que hi haurà al conjunt.
			cout << "# " << opcio <<  endl;
			conjunt.lee_cjt_especies();
			cout << endl;
		}
		else if (opcio == "imprime_cjt_especies") {
			// Funció que imprimeix les especies que hi ha al conjunt.
			// En cas de no haver cap especie, no dona cap missatge d'error.
			cout << "# " << opcio << endl;
			conjunt.imprime_cjt_especies();
			cout << endl;
		}
		else if (opcio == "tabla_distancias") {
			// Funció que imprimeix la taula de distancies entre les especies que hi ha al conjunt.
			// En cas de no haver cap especie, no dona cap missatge d'error.
			cout << "# " << opcio << endl;
			conjunt.tabla_distancias();
			cout << endl;
		}
		else if (opcio == "inicializa_clusters") {
			cout << "# " << opcio << endl;
			// Declarem el booleà a = true, ja que així ens assegurem que cada vegada que cridem
			// la funció inicialitza clusters ens imprimeixi la taula de distancies entre clusters.
			bool a = true;
			cjt_clusters.inicialitza_clusters(conjunt, a);
			cout << endl;
		}
		else if (opcio == "ejecuta_paso_wpgma") {
			cout << "# " << opcio << endl;
			// Declarem el booleà a = true, ja que així ens assegurem que cada vegada que cridem
			// la funció inicialitza clusters ens imprimeixi la taula de distancies entre clusters.
			bool a = true;
			cjt_clusters.ejecuta_paso_wpgma(a);
			cout << endl;
		}
		else if (opcio == "imprime_cluster") {
			cin >> id; // El identificador del cluster el qual es vol imprimir.
			cout << "# " << opcio << " " << id << endl;
			cjt_clusters.imprime_cluster(id);
			cout << endl;
		}
		else if (opcio == "imprime_arbol_filogenetico") {
			// Donat un conjunt de especies, s'imprimeix 
			// l'arbre filogenètic resultant.
			cout << "# " << opcio << endl;
			cjt_clusters.imprime_arbol_filogenetico(conjunt);
			cout << endl;
			
		}
	cin >> opcio;
	}

}

