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


// Consultores


string Especie::consultar_gen() const{
	return gen;
}

double Especie::distancia(const Especie& esp) const {
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
	while (i != k_meros.end()) { // Segon bucle while per si el primer ha acabat i no hem fet el recorregut sencer.
		unio += i->second;
		++i;
	} 
	while (k != esp.k_meros.end()) { //Segon bucle while per si el primer ha acabat i no hem fet el recorregut sencer.
		unio += k->second;
		++k;
	}
	return (((1-(interseccio/unio))*100));	
}


// Modificadores

void Especie::kmer() {
	for (int i = 0; i < gen.size() - k_num + 1; ++i) {
		string aux;
		for (int j = i; j < k_num + i; ++j) {
			aux += gen[j];
		}
		map<string,int>::const_iterator it = k_meros.find(aux);
		if (it == k_meros.end()) k_meros.insert(make_pair(aux, 1));
		else k_meros[aux] = it-> second +1;
	}
} 


// Lectura i escriptura

void Especie::escriure() const {
	cout << gen << endl;
}

	







	
	
	
	
	
	
	

