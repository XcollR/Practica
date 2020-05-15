/** @file Cjt_especies.cc
 * 	@brief Còdig de la classe Cjt_especies.
 */

#include "Cjt_especies.hh"
#include "Especie.hh"

// Constructores

// Mètode constructor d'especie. Posem el mapa d'especies i el nested map de la taula
// de distàncies com a dos mapes buits.
Cjt_especies::Cjt_especies() {
	Cjt_especies::cjt_especies = map<string, Especie> ();
	Cjt_especies::taula_distancies = map<string,map<string,double>>();
}



// Modificadores

// Entren dos paràmetres explícits. El primer paràmetre és la clau
// del mapa. El valor d'aquesta clau serà una especie la qual es genera
// amb la constructora d'especie mitjançant un gen. A més, aquesta especie
// s'introdueix a la taula de distancies mitjançant el mètode afegeix
// especie tabla dist.
void Cjt_especies::crea_especie(string id,string gen) {
			Especie e(gen);
			Cjt_especies::cjt_especies.insert(make_pair(id,e));
			afegeix_especie_tabla_dist(id);
}

// Consultores


// S'elimina la espècie indicada pel paràmetre explícit.
// Es busca la espècie mitjaçant un iterador del mapa d'especies
// i s'elimina la espècie indicada.
// Observació: Aquesta funció no comprova si existeix una espècie 
// o no, per tant, s'ha de fer compravació prèvia amb la funció
// Cjt_especie::existe_especie(id).
void Cjt_especies::elimina_especie(string id) {
		map<string, Especie>::const_iterator it = Cjt_especies::cjt_especies.find(id);
		Cjt_especies::cjt_especies.erase(it);
		Cjt_especies::elimina_especie_tabla_dist(id);     
}

// Es consulta si existeix la espècie dins el map d'especies.
// Es busca la especie mitjançant un iterador. En el cas que
// l'iterador apuntes al final de mapa, la especie no existeix 
// i es retorna false, en cas contrari retorna true.
bool Cjt_especies::existeix_especie(string id)  const{
	map<string, Especie>::const_iterator it = Cjt_especies::cjt_especies.find(id);
	if (it != Cjt_especies::cjt_especies.end()) return true;
	return false;
}

// Retorna la distància entre dues especies.
// Es fan comprovación abans de consultar-les. En el cas
// que no existeixin les dues espècies es retorna un -1.
// Si no existeix només la primera espècie retorna un -2.
// Si no existeix només la segona espècie retorna un -3.
// En cas que les dues especies existeixin, és fan unes comprovacions:
// 		Com el map només calcula les distàncies necessaries ja que 
// 		Distancia (a,b) = Distancia (b,a), el map ordena les distancies
// 		per ordre alfabètic amb la seva clau. Per tant hem de tenir en 
// 		compte que si es consulta distancia c a. No podem consultar de 
//		primeres. Per tant, amb dos iteradors mirem si apuntent al final,
//		En el cas que passés, cambien d'ordre els iteradors i aquests
//		accedeixen a la posició on hi ha la distància demanada.
//Observació: Aquesta funció no calcula les distàncies, sinó consulta
//el mapa de distàncies.

double Cjt_especies::calcular_distancia(const string& id, const string& id2) const {
	if (not Cjt_especies::existeix_especie(id) and not Cjt_especies::existeix_especie(id2)) return -1; 
	else if (not Cjt_especies::existeix_especie(id)) return -2;
	else if (not Cjt_especies::existeix_especie(id2)) return -3;
	else {
			map<string,map<string,double>>::const_iterator it = Cjt_especies::taula_distancies.find(id);
			map<string,double>::const_iterator it2 = it->second.find(id2);
			if (it2 == it->second.end()) {
				it = Cjt_especies::taula_distancies.find(id2);
				it2 = it->second.find(id);
				return it2->second;
			}
			return it2->second;
		}
}


// Es consulta el gen d'una especie mitjançant una 
// funció de la classe Especie i un iterador.
// Observació: S'ha de comprovar prèviament que aquesta especie existeix.
void Cjt_especies::obtener_gen(string id) const {
	map<string, Especie>::const_iterator it = Cjt_especies::cjt_especies.find(id);
	cout << it->second.consultar_gen() << endl;
	
}

// Es fa comprovacions si l'iterador de l'àmbit
// privat apunta al final del conjunt d'especies.
// Retorna cert si apunta al final, en cas contrari
// retorna fals.
bool Cjt_especies::final() {
	return it == Cjt_especies::cjt_especies.end();

}

// Es posiciona l'iterador de l'ambit
// privat apuntant a la primera posició 
// del mapa d'especies.
void Cjt_especies::inicio() {
	it = Cjt_especies::cjt_especies.begin();
}

// Es modifica el string del paràmetre 
// explícit i se li adjudica el string
// al qual apunta el iterador.
void Cjt_especies::actual(string& act) {
	act = it->first;
}

// Es posiciona l'iterador de l'ambit
// privat apuntant a una posició més endavant 
// de la qua apuntava l'iterador abans.
// Observació: S'avançarà l'iterador sempre
// i quan l'iterador no estigui apuntant al final.

void Cjt_especies::avanza() {
	if (not final()){
				++Cjt_especies::it;

	}
}


// Lectura i escriptura


void Cjt_especies::lee_cjt_especies() {
	//La condició de si es llegeix un nou conjunt
	//d'especies es que es descarta el contingut previ.
	//Per tant fem clear dels dos mapes.
	Cjt_especies::taula_distancies.clear();
	Cjt_especies::cjt_especies.clear();
	//int que indica el nombre d'especies que es volen afegir.
	int n;
	cin >> n;
	//Inv: el bucle for mai farà més de n iteracions. 
	//A cada iteració farà una crida a la funció crea especie.
	for (int i = 0; i < n; ++i) {
		string id, gen;
		cin >> id >> gen;
		Cjt_especies::crea_especie(id,gen);
	}
}


void Cjt_especies::imprime_cjt_especies() const {
	//Inv: És situa un iterador apuntant a la primera posició del
	//mapa d'especies. Avançarà una iteració fins que el punter apunti al final.
	//A cada iteració s'impreix una especie.
	for (map<string,Especie>::const_iterator it = Cjt_especies::cjt_especies.begin(); it != Cjt_especies::cjt_especies.end(); ++it) {
		cout << it->first << " ";
		it->second.escriure();
	}
}


void Cjt_especies::tabla_distancias() const {
	//Inv: És situa un iterador apuntant a la primera posició del
	//mapa de distancies. Avançarà una posició fins que el punter apunti al final.
	//A cada iteració s'impreix un identificador de especie i s'executa un segon bucle.
	for(map<string,map<string,double>>::const_iterator it = Cjt_especies::taula_distancies.begin(); it != Cjt_especies::taula_distancies.end(); ++it) {
		cout << it->first << ":";
		//Inv: És situa un iterador apuntant a la primera posició del
		//map interior del map de distancies d'especies. Avançarà una posició fins que el punter apunti al final.
		//A cada iteració s'impreix un identificador d'especie del map interior i la distancia respecte les dues especies.
		for (map<string,double>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
				cout << " " << it2->first << " (" << it2->second << ")"; 
		}
		cout << endl;
	}
}

// Mètodes privats

void Cjt_especies::elimina_especie_tabla_dist(const string& id) {
	//Es posiciona un iterador apuntant a la posició de l'id demanat.
	map<string,map<string,double>>::const_iterator it = Cjt_especies::taula_distancies.find(id);
	//Es posiciona un iterador apuntant a la primera posició del mapa de distancies.
	//Inv: Farà tantes iteracions fins que l'iterador sigui igual al primer que hem buscat. Així ens
	//estalviem bucles innecessaris. Aquest bucle elimina la especie demanada del map interior.
	for (map<string,map<string,double>>::iterator it2 = Cjt_especies::taula_distancies.begin(); it2 != it; ++it2) {
			it2->second.erase(it2->second.find(id));
		}
	//Eliminem la especie del mapa gran de la taula de distancies.
	Cjt_especies::taula_distancies.erase(it);
}



void Cjt_especies::afegeix_especie_tabla_dist(const string& id) {
	//Es posiciona un iterador apuntant a la taula d'especies, a la posició on esta el id demanat.
	map<string,Especie>::const_iterator esp = Cjt_especies::cjt_especies.find(id);
	//Es crea un map auxiliar on s'aniran ficant les distancies.
	map<string, double> aux;
	//Inv: Recorregut del mapa, de principi a final. 
	for (map<string,Especie>::const_iterator it = Cjt_especies::cjt_especies.begin(); it != Cjt_especies::cjt_especies.end(); ++it) {
		map<string,map<string,double>>::iterator itt = Cjt_especies::taula_distancies.find(it->first);
		//Calcula la distancia entre dues especies, la que entra pel parametre explícit
		//i la que apunta el iterador.
		double x = it->second.distancia(esp->second);
		//If per fer les operacions si el identificador està a la part baixa
		// i per tant només es fica una distancia al map interior.
		if (id > it->first) {
			itt->second.insert(make_pair(id, x));
		}
		//If per fer les operacions si l'identificador està a la part alta i s'ha
		//de crear un nou map amb totes les altres especies.
		else if (id < it->first) {
			aux.insert(make_pair(it->first, x));
		}
			
	}
	//Finalment insertem el mapa a la taula de distancies.
	Cjt_especies::taula_distancies.insert(make_pair(id, aux));

}


