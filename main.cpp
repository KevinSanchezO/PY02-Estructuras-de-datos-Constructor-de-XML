#include <iostream>
#include "XMLDocument.hpp"

XMLDocument *a = new XMLDocument();

void guardar(){
    char *filename;
    filename = (char*) malloc(100*sizeof(char));
    std::cout << "Nombre del archivo: ";
    std::cin >> filename;
    bool pp = a->Save(filename);
    std::cout<<pp<<std::endl;
}


void balanceo(){
    bool pp = a->SwitchContentPosition();
    std::cout<<pp<<std::endl;
}


void switchCont(){
    bool pp = a->SwitchContentPosition();
    std::cout<<pp<<std::endl;
}


void mirarXML(){
    char* arbol;
    arbol = a->ViewXML ();
    std::cout<<arbol<<std::endl;
}

void visualizarSubArbol(){
    char* node;
    node = a->ViewTree();
    std::cout<<node<<std::endl;
}


void visualizarNode(){
    char* node;
    node = a->ViewNode();
    std::cout<<node<<std::endl;
}


void deleter(){
    bool q;
    q = a->Delete();
    std::cout<<q<<std::endl;
}


void editcontent(){
    char *content;
    content = (char*) malloc(100*sizeof(char));

    int p;
    bool q;  

    std::cout << "Contenido del nodo: ";
    std::cin >> content;

    std::cout << "Modo: ";
    std::cin >> p;

    q = a->EditContent(content, p);
    std::cout<<q<<std::endl;
}


void editatributo(){
    char *nombre;
    nombre = (char*) malloc(100*sizeof(char));

    char *content;
    content = (char*) malloc(100*sizeof(char));

    int p;
    bool q;   

    std::cout << "Key del atributo: ";
    std::cin >> nombre;
                
    std::cout << "Value para el atributo: ";
    std::cin >> content;

    std::cout << "modo: ";
    std::cin >> p;

    q = a->EditAttribute(nombre, content, p);
    std::cout<<q<<std::endl;
}


void seleccionar(){
    int p;
    bool q;

    std::cout << "Id del nodo: ";
    std::cin >> p;
    q = a->Select(p);
    std::cout<<q<<std::endl;
}


void hijoo(){
    char *nombre;
    nombre = (char*) malloc(100*sizeof(char));
    int p;

    char *content;
    content = (char*) malloc(100*sizeof(char));

    std::cout << "Nombre del nuevo nodo: ";
    std::cin >> nombre;

    std::cout << "Nombre del contenido: ";
    std::cin >> content;
    p = a->Child(nombre, content);
    std::cout<<p<<std::endl;
    
}


void hijo(){
    char *nombre;
    nombre = (char*) malloc(100*sizeof(char));
    int p;

    std::cout << "Nombre del nuevo nodo: ";
    std::cin >> nombre;
    p = a->Child(nombre);
    std::cout<<p<<std::endl;
}


void raiz (){
    char *nombre;
    nombre = (char*) malloc(100*sizeof(char));
    int p;

    std::cout << "Nombre de la nueva raiz: ";
    std::cin >> nombre;
    p = a->Root(nombre);
    std::cout<<p<<std::endl;
}


int main(){
    bool stop = false;
    int option = ' ';
    do{
        std::cout << "[1.Raiz|2.Hijo|3.Hijo content|4.Seleccionar|5.AtributoEdit|6.ContentEdit|7.EliminarNodo|8.ViewNode|9.VisualizarSubArbol|10.VisualizarXML|11.SwitchCont|12.Balanceo|13.Guardar]: ";
		std::cin >> option;

        switch (option) {
            case 0:
                stop = true;
                break;
            case 1:
                raiz();
                break;
            case 2:
                hijo();
                break;
            case 3:
                hijoo();
                break;
            case 4:
                seleccionar();
                break;
            case 5:
                editatributo();
                break;
            case 6:
                editcontent();
                break;
            case 7:
                deleter();
                break;
            case 8:
                visualizarNode();
                break;
            case 9:
                visualizarSubArbol();
                break;
            case 10:
                mirarXML();
                break;
            case 11:
                switchCont();
                break;
            case 12:
                balanceo();
                break;
            case 13:
                guardar();
                break;
            default:
                std::cout<< "Opción inválida." << std::endl;
                break;
        }
    }while (!stop);
}