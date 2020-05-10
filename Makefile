OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: Cjt_especies.o program.o Especie.o Cjt_clusters.o Cluster.o
	g++ $(OPCIONS) -o program.exe Cjt_especies.o program.o Especie.o Cjt_clusters.o Cluster.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_clusters.o: Cjt_clusters.cc Cjt_clusters.hh 
	g++ $(OPCIONS) -c Cjt_clusters.cc 

Cluster.o: Cluster.cc Cluster.hh 
	g++ $(OPCIONS) -c Cluster.cc

Cjt_especies.o: Cjt_especies.hh Cjt_especies.cc
	g++ $(OPCIONS) -c Cjt_especies.cc

Especie.o: Especie.cc Especie.hh 
	g++ $(OPCIONS) -c Especie.cc 
	
	
practica.tar: Makefile Cjt_especies.hh Cjt_especies.cc Especie.hh Especie.cc program.cc 
	tar -cvf practica.tar Cjt_especies.hh Cjt_especies.cc Especie.hh Especie.cc program.cc Makefile 
	
	
practica_final.tar: Makefile Cjt_especies.hh Cjt_especies.cc Especie.hh Especie.cc Cluster.cc Cluster.hh Cjt_especies.hh Cjt_especies.cc BinTree.hh program.cc 
	tar -cvf practica.tar *.cc *.hh Makefile 
	
clean: 
	del -f *.o *.gch *.exe *.txt
