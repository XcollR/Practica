#include "Cjt_especies.hh"
#include "Especie.hh"

Cjt_especies::Cjt_especies() {
	num_especies = 0;
	cjt_especies = map<string, Especie> ();
}



double Cjt_especies::calcular_distancia(const string& id, const string& id2) const {
	if (not existeix_especie(id) and not existeix_especie(id2)) {
		return -1;
		}
			else if (not existeix_especie(id)) {
		return -2;
		}
			else if (not existeix_especie(id2)) {
		return -3;
		}
		else {
			auto it = cjt_especies.find(id);
			auto it2 = cjt_especies.find(id2);
			return (it->second.distancia(it2->second));
			
		}
}



void Cjt_especies::lee_cjt_especies() {
	cjt_especies.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string id, gen;
		cin >> id >> gen;
		crea_especie(id,gen);
	}
	cout << endl;
	calcular_taula_distancies();
	
}

void Cjt_especies::crea_especie(string id,string gen) {
		map<string, Especie>::const_iterator it = cjt_especies.find(id);
		if (it != cjt_especies.end()) {
			cout << "ERROR: La especie " << id << " ya existe." << endl;
		}
		else {
			Especie e(gen);
			cjt_especies.insert(make_pair(id,e));
			++num_especies;
		}
	calcular_taula_distancies();
}
void Cjt_especies::imprime_cjt_especies() const {
	for (map<string,Especie>::const_iterator it = cjt_especies.begin(); it != cjt_especies.end(); ++it) {
		cout << it->first << " ";
		it->second.escriure();
	}
	cout << endl;
}

void Cjt_especies::obtener_gen(string id) const {
	if (existeix_especie(id)) {
		map<string, Especie>::const_iterator it = cjt_especies.find(id);
		cout << it->second.consultar_gen() << endl;
	}
	else cout << "ERROR: La especie " << id << " no existe." << endl;
	
	cout << endl;
}

bool Cjt_especies::existeix_especie(string id)  const{
	map<string, Especie>::const_iterator it = cjt_especies.find(id);
	if (it != cjt_especies.end()) return true;
	return false;
}


void Cjt_especies::elimina_especie(string id) {
	if (not existeix_especie(id)) cout << "ERROR: La especie " << id << " no existe." << endl;
	else {
		map<string, Especie>::const_iterator it = cjt_especies.find(id);
		cjt_especies.erase(it);
	}
	calcular_taula_distancies();
	cout << endl;
}
	
void Cjt_especies::calcular_taula_distancies() {	
	taula_distancies.clear();
	for (auto it = cjt_especies.begin(); it != cjt_especies.end(); ++it) {
		map<string, double> dist;
		for (auto it2 = it; it2 != cjt_especies.end(); ++it2) {
			if (it->first != it2->first) {
				double x = calcular_distancia(it->first, it2->first);
				dist.insert(make_pair(it2->first,x));
			}
		}
		taula_distancies.insert(make_pair(it->first, dist));
		}	
}
		
	

		
void Cjt_especies::tabla_distancias() const {
	for (auto it2 = taula_distancies.begin(); it2 != taula_distancies.end(); ++it2) {
		cout << it2->first << ": ";
		for (auto it3 = it2; it3 != taula_distancies.end(); ++it3) {
		if (it2->first != it3->first) {
			const auto it = taula_distancies.find(it2->first);
			const auto ti = it->second.find(it3->first);
			cout << it3-> first << " (" << ti->second << ") ";			
			}
		}
		cout << endl;
	}
}

	



