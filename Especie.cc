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
	auto i = k_meros.begin();
	auto k = esp.k_meros.begin();
	double unio = 0, interseccio = 0;
	while (i != k_meros.end() and k != esp.k_meros.end()) {
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
	while (i != k_meros.end()) {
		unio += i->second;
		++i;
	}
	while (k != esp.k_meros.end()) {
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
		auto it = k_meros.find(aux);
		if (it == k_meros.end()) k_meros.insert(make_pair(aux, 1));
		else k_meros[aux] = it-> second +1;
	}
} 


// Lectura i escriptura

void Especie::escriure() const {
	cout << gen << endl;
}

	







	
	
	
	
	
	
	

