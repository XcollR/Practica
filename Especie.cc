#include "Especie.hh"


int Especie::k_num;


Especie::Especie() {
	gen = ' ';
	k_meros = map<string, int> ();
}

Especie::Especie(string gen1) {
	gen = gen1;
	k_meros = kmer(gen, k_num);
}

void Especie::set_parametro(const int& k_dato) {
  Especie::k_num = k_dato;
}

void Especie::escriure() const {
	cout << gen << endl;
}

	
string Especie::consultar_gen() const{
	return gen;
}


map<string, int> Especie::kmer(const string& gen, const int& k_num) {
	map<string, int> res;
	int k = k_num;
	for (int i = 0; i < gen.size() - k+ 1; ++i) {
		string aux;
		for (int j = i; j < k + i; ++j) {
			aux += gen[j];
		}
		auto it = res.find(aux);
		if (it == res.end()) res.insert(make_pair(aux, 1));
		else res[aux] = it-> second +1;
	}
	
	return res;
} 

map<string,int> Especie::return_k_meros() const {
	return k_meros;
}

double Especie::distancia(const Especie& esp) {
		map<string, int> map1 = k_meros;
		map<string, int> map2 = esp.return_k_meros();
		map<string, int> map3;
		double contador = 0;
		double contador2 = 0;
		for (auto it = map1.begin(); it != map1.end(); ++it) {
			auto it2 = map2.find(it->first);
			if (it2 != map2.end()) {
				if (it -> second < it2 -> second) contador += it->second;
				else contador += it2->second;
			}
		}
		
		double a = cardinal(map1);
		double b = cardinal(map2);
		contador2 = (a+b)-contador;
		return ((1-(contador/contador2))*100);
}


double Especie::cardinal(const map<string, int>& map1) {
	
	int card2 = 0;
	for (auto a = map1.begin(); a != map1.end(); ++a) {
		card2 += a->second;
	}
	return card2;
}
