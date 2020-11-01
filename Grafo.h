#ifndef GRAFO_H
#define GRAFO_H
#include<list>	
#include<string>
#include<bits/stdc++.h>
#include "Parseador.h"
 
class Grafo{
    std::list<std::list<Parseador*>> *adyacentes; 
    bool esCiclico;
    bool instruccionSinUsar;
    void agregarNodoAdyacente(Parseador* nodo);
    void agregarAdyacenteEtiqueta(Parseador* nodo);
    std::list<Parseador*> obtenerNodosAdyacentes(Parseador* nodo);
    bool nodoEstaEnLista(Parseador *nodo, std::list<Parseador*> lista);
    void detectarCiclos(Parseador *nodo, 
        std::list<Parseador*> *visitados, std::list<Parseador*> *stack);
    void agregarListaAdy(Parseador *nodo);
    void agregarNodoConEtiqueta(Parseador *nodo);
    void agregarAdyacentesNodo(Parseador *nodo, Parseador *nodo_ant);
    Parseador* buscarNodoConEtiqueta(std::string etiqueta);
    int obtenerEtiquetasNodo(Parseador *nodo_ant);
    bool instruccionRepetida(Parseador* nodo);
    
public: 
    Grafo();
    void agregarNodo(Parseador *nodo);
    void DFS();
    void destruirGrafo();
    void ultimoNodo();
    bool tieneCliclos();
    bool tieneInstruccionesSinUsar();
    ~Grafo();
};

#endif