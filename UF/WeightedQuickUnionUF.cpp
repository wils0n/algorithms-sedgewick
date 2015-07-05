#include <iostream>

using namespace std;

#define MAX 10005

int parent[ MAX ]; // padre del i-esimo nodo
int size[ MAX ];   // size[i] numero de objetos en el subarbol con raiz i
int count;         // numero de componentes

void init( int n ){
	for (int i = 0; i < n ; ++i){
		parent[ i ] = i; // inicialmente el padre de cada vertice es el mismo vertice
		size [ i ] = 1;  // inicialmente la cantidad de objetos de cada nodo es 1 (el mismo)
	}
	count = n; 			 // inicialmente la cantidad de componentes es el total de nodos (ya que todos estan inicialmente independientes)
}

// Metodo para encontrar la raiz del nodo actual p
int Find( int p ){
	while( p != parent[p])
		p = parent[p];
	return p;

}

// Metodo que une 2  compoenentes usando la cantidad de nodos
// El padre de ambas componentes será el de mayor tamanho (el que tenga mas nodos)
void Union(int p, int q){
	int rootP = Find(p);
	int rootQ = Find(q);

	if (rootP == rootQ) return;

	if(size[rootP] < size[rootQ]){
		parent[rootP] = rootQ;
		size[rootQ] += size[rootP];
	}else{
		parent[rootQ] = rootP;
		size[rootP] += size[rootQ];
	}
	count--;
}

bool connected (int p, int q){
	return Find(p) == Find(q);
}
int main(){
	int N, E, p, q;
	cin>>N>>E;
	init(N);
	while(E--){
		cin>>p>>q;
		Union(p, q);
	}
	cout<<count<<" componentes"<<endl;
}





















