/** @file Cjt_especies.cc
 * 	@brief Còdig de la classe Cjt_especies
 */

#include "Cjt_especies.hh"
#include "Especie.hh"

Cjt_especies::Cjt_especies() {
	cjt_especies = map<string, Especie> ();
}



double Cjt_especies::calcular_distancia(const string& id, const string& id2) const {
	if (not existeix_especie(id) and not existeix_especie(id2)) return -1; 
	else if (not existeix_especie(id)) return -2;
	else if (not existeix_especie(id2)) return -3;
	else {
			auto it = taula_distancies.find(id);
			auto it2 = it->second.find(id2);
			if (it2 == it->second.end()) {
				it = taula_distancies.find(id2);
				it2 = it->second.find(id);
				return it2->second;
			}
			return it2->second;
		}
}


void Cjt_especies::lee_cjt_especies() {
	taula_distancies.clear();
	cjt_especies.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string id, gen;
		cin >> id >> gen;
		crea_especie(id,gen);
	}
}

void Cjt_especies::crea_especie(string id,string gen) {
			Especie e(gen);
			cjt_especies.insert(make_pair(id,e));
			afegeix_especie_tabla_dist(id);
}
void Cjt_especies::imprime_cjt_especies() const {
	for (map<string,Especie>::const_iterator it = cjt_especies.begin(); it != cjt_especies.end(); ++it) {
		cout << it->first << " ";
		it->second.escriure();
	}
}

void Cjt_especies::obtener_gen(string id) const {
	map<string, Especie>::const_iterator it = cjt_especies.find(id);
	cout << it->second.consultar_gen() << endl;
	
}

bool Cjt_especies::existeix_especie(string id)  const{
	map<string, Especie>::const_iterator it = cjt_especies.find(id);
	if (it != cjt_especies.end()) return true;
	return false;
}


void Cjt_especies::elimina_especie(string id) {
		map<string, Especie>::const_iterator it = cjt_especies.find(id);
		cjt_especies.erase(it);
		elimina_especie_tabla_dist(id);     
}

		
void Cjt_especies::tabla_distancias() const {
	for(map<string,map<string,double>>::const_iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it) {
		cout << it->first << ":";
		for (map<string,double>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
				cout << " " << it2->first << " (" << it2->second << ")"; 
		}
		cout << endl;
	}
}

void Cjt_especies::elimina_especie_tabla_dist(const string& id) {
	auto it = taula_distancies.find(id);
	for (auto it2 = taula_distancies.begin(); it2 != it; ++it2) {
			it2->second.erase(it2->second.find(id));
		}
			taula_distancies.erase(it);
}

void Cjt_especies::afegeix_especie_tabla_dist(const string& id) {
	auto esp = cjt_especies.find(id);
	map<string, double> aux;
	for (auto it = cjt_especies.begin(); it != cjt_especies.end(); ++it) {
		auto itt = taula_distancies.find(it->first);
		double x = it->second.distancia(esp->second);
		if (id > it->first) {
			itt->second.insert(make_pair(id, x));
		}
		else if (id < it->first) {
			aux.insert(make_pair(it->first, x));
		}
			
	}
	taula_distancies.insert(make_pair(id, aux));

}


void Cjt_especies::inicio() {
	it = cjt_especies.begin();
}

bool Cjt_especies::final() {
	return it == cjt_especies.end();

}

void Cjt_especies::actual(string& act) {
	act = it->first;
}

void Cjt_especies::avanza() {
	if (not final()){
				++it;

	}
}