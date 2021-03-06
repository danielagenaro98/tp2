#include "Parseador.h"

Parseador::Parseador(){
	this->nodo = new Nodo();
}

Nodo* Parseador::parsear_linea(std::string linea){
	std::string str = "";
	if(linea.compare(str) == 0){
		this->nodo->agregarInstrucciones(linea);
		this->nodo->setEtiqueta(false);
	}else{
		std::string resultado = buscar_etiqueta(linea);
		parsear_instrucciones(resultado);
	}
	return this->nodo;
}

std::string Parseador::buscar_etiqueta(std::string linea){
    size_t pos = 0;
    std::string instrucciones;

	if ((pos = linea.find(':')) != std::string::npos){
    	std::string token = linea.substr(0, pos);
    	this->nodo->agregarEtiqueta(token);
    	this->nodo->setEtiqueta(true);
    	instrucciones = linea.substr(pos+1, linea.length());
	}else{
		this->nodo->setEtiqueta(false);
    	instrucciones = linea;
	}
	return instrucciones;
}

void Parseador::buscar_etiquetas_jmp(const std::string &delimitador, 
	const std::string &linea){
	size_t pos = 0;
	std::string aux = linea;
	std::list<std::string> lista;

	while ((pos = aux.find(delimitador)) != std::string::npos){
		aux.erase(0, pos + 1);
		aux = trim(aux);
		lista.push_back(aux);
	}
	this->nodo->agregarEtiquetasJmp(lista);
}

void Parseador::parsear_instrucciones(std::string linea){
	linea = trim(linea);

	if(linea.at(0) != 'j'){
		this->nodo->agregarInstrucciones(linea);
		return;
	}
	if((linea.find(",")) != std::string::npos){ 
		buscar_etiquetas_jmp(",", linea);
	}else{
		buscar_etiquetas_jmp(" ", linea);
	}
	this->nodo->agregarInstrucciones(linea);
}

std::string Parseador::trim(const std::string &str){
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first){
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
