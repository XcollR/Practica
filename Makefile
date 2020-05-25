OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: Cjt_especies.o program.o Especie.o Cjt_clusters.o Cluster.o
	g++ $(OPCIONS) -o program.exe Cjt_especies.o program.o Especie.o Cjt_clusters.o Cluster.o

program.o: program.cc Cjt_especies.hh Especie.hh Cjt_clusters.hh Cluster.hh Especie.hh
	g++ -c program.cc $(OPCIONS) 

Cjt_clusters.o: Cjt_clusters.cc Cjt_clusters.hh Cluster.hh Cjt_especies.cc Especie.hh 
	g++ -c Cjt_clusters.cc $(OPCIONS) 

Cluster.o: Cluster.cc Cluster.hh Cjt_especies.hh
	g++ -c Cluster.cc $(OPCIONS) 

Cjt_especies.o:  Cjt_especies.cc Cjt_especies.hh Especie.hh
	g++ -c Cjt_especies.cc $(OPCIONS) 

Especie.o: Especie.cc Especie.hh 
	g++ -c Especie.cc $(OPCIONS)
	
	
practica.tar: Makefile Cjt_especies.hh Cjt_especies.cc Especie.hh Especie.cc Cluster.cc Cluster.hh Cjt_clusters.hh Cjt_clusters.cc program.cc html.zip
	tar -cvf practica.tar Makefile Cjt_especies.hh Cjt_especies.cc Especie.hh Especie.cc Cluster.cc Cluster.hh Cjt_clusters.hh Cjt_clusters.cc program.cc html.zip
	
clean: 
	del -f *.o *.gch *.exe *.txt
