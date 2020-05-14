/** @file Especie.cc
 * 	@brief Còdig de la classe Especie.
 */
#include "Especie.hh"


// Constructores

int Especie::k_num;


Especie::Especie() {
	gen = ' ';
	k_meros = map<string, int> ();
}


Especie::Especie(string gen1) {
	gen = gen1;
	kmer();
}


void Especie::set_parametro(const int& k_dato) {
  Especie::k_num = k_dato;
}

void Especie::kmer() {
	// Inv: El recorregut que fa aquest bucle for mai
	// farà més iteracions que el tamany del gen - k + 1.
	// A cada iteració es crea un string auxiliar on s'aniran actualitzan els caracters un per un.
	for (int i = 0; i < gen.size() - k_num + 1; ++i) {
		string aux;
	// Inv: El recorregut que fa aquest segon bucle mai superarà
	// les k iteracions. Hem igualat la j a la i, per anar avançant cada
	// cop una posició i el bucle farà menys de k_num + i iteracions.
		for (int j = i; j < k_num + i; ++j) { 
			aux += gen[j];
		}
		// En el mapa de k-meros busquem el kmero que acabem de crear
		// en la anterior interació. Si aquest no existia s'afegeix al mapa.
		// La clau del mapa és el kmer generat i el valor que se l'assigna és el número
		// de vegades que es repeteix, al ser el primer cop, es posa un 1. En cas que el 
		// kmer ja existis anteriorment, es busca la clau i s'incrementa en 1 el valor.
		map<string,int>::const_iterator it = k_meros.find(aux);
		if (it == k_meros.end()) k_meros.insert(make_pair(aux, 1));
		else k_meros[aux] = it-> second +1;
	}
} 


// Consultores


string Especie::consultar_gen() const{
	return gen;
}

double Especie::distancia(const Especie& esp) const {
	// Invariant: Situem dos iterador constants al inici dels dos maps de k_meros
	// Unio i Intersecció és la cuantitat de elements que compleixen la 
	// condició de que siguin unió o intersecció.
	// Els elements visitats tenen la clau més petita que els altres.
	// El bucle acaba quan un dels dos iteradors apunta al final, mai poden acabar els dos alhora.

	map<string,int>::const_iterator i = k_meros.begin(), k = esp.k_meros.begin();
	double unio = 0, interseccio = 0;
	while (i != k_meros.end() and k != esp.k_meros.end()) { // Bucle While general per comparar i anar fent la interseccio/unió dels kmeros.
		if (i->first == k->first) {
			interseccio += min(i->second,k->second);
			unio +=  max(i->second, k->second);
			++i;
			++k;			
		}
		else if (i->first < k->first) {
			unio += i->second;
			++i;
		}
		else {
			unio += k->second;
			++k;
		}
	}
	// Si el iterador i, el del primer mapa de k-meros no ha acabat el recorregut
	// entra en aquest bucle.
	// Inv: Els elements de i estan ordenats segons la clau en ordre ascendent.
	while (i != k_meros.end()) {
		unio += i->second;
		++i;
	} 
	// Si el iterador k, el del segon mapa de k-meros no ha acabat el recorregut
	// entra en aquest bucle.
	// Inv: Els elements de k estan ordenats segons la clau en ordre ascendent.
	while (k != esp.k_meros.end()) { 
		unio += k->second;
		++k;
	}
	return (((1-(interseccio/unio))*100));	
}


// Modificadores



// Lectura i escriptura

void Especie::escriure() const {
	cout << gen << endl;
}

	







	
	
	
	
	
	
	

