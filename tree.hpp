#ifndef TREE_HPP
#define TREE_HPP
#include "node.hpp"
#include <fstream>

/*****Nombre***************************************
 * Tree
 *****Descripción**********************************
 * Clase que representa un estructura jerarquica
 * tipo arbol
 *****Atributos************************************
 * aContID
 * apRaiz
 * apNodoSeleccionado
 *****Métodos**************************************
 * Tree()
 * Root(char* pNombre)
 * Select (int id)
 * SelectAux(Node* pNodo, int id)
 * Child (char *name)
 * Child (char *name, char *content)
 * Balancear()
 * EliminarNodo()
 * ViewNode ()
 * ViewTree()
 * VisualizarSubArbol(Node* nodo,char* tab)
 * convertirChar(int numero)
 * largo(char* pName)
 * guardar(char* pfilename)
 **************************************************/
class Tree {
    private:
        int aContID;
        Node* apRaiz;
        Node* apNodoSeleccionado;
        Node* apSubArbol;
    public:
        /*****Nombre***************************************
         * Tree()
         *****Descripción**********************************
        * Metodo constructor de la clase
        *****Retorno**************************************
        * 
        *****Entradas*************************************
        * 
        **************************************************/
        Tree(){
            aContID = 100;
            apRaiz = nullptr;
            apNodoSeleccionado = nullptr;
            apSubArbol  = nullptr;
        }

        /*****Nombre***************************************
         * Root()
         *****Descripción**********************************
        * Meotodo para ingresar una nueva raiz al arbol
        *****Retorno**************************************
        * El nuevo identificador de la nueva raiz del arbol
        *****Entradas*************************************
        * char* pNombre
        **************************************************/
        int Root(char* pNombre){
            Node* node = new Node(pNombre,aContID);
            if (apRaiz == nullptr){
                apRaiz = node;
                apNodoSeleccionado = apRaiz;
            }else{
                node->setHijoPrimero(apRaiz);
                apRaiz->setPadre(node);
                node->setCantHijos();
                apRaiz = node;
            }
            aContID++;
            return apRaiz->getID();
        }

        /*****Nombre***************************************
         * Select()
         *****Descripción**********************************
        * Metodo para elegir un nuevo nodo seleccionado
        *****Retorno**************************************
        * un valor booleano que determina si se pudo hacer la
        * operacion
        *****Entradas*************************************
        * int id
        **************************************************/
        bool Select (int id){
            if (apNodoSeleccionado != nullptr){
                int cont =0;
                Node *temp = apRaiz->getHijoPrimero();
                if (apRaiz == nullptr){
                    return false;
                } else{
                    if (id == apRaiz->getID()){
                        apNodoSeleccionado = apRaiz;
                        return true;
                    }
                }
                while (cont < apRaiz->getCantHijos()){  
                    apSubArbol = temp;
                    bool encontrado = SelectAux(temp,id);
                    if (!encontrado){
                        cont++;
                        temp = temp->getSigHermano();
                    }else{
                        return true;
                    }
                }
                return false;
            }else{
                return false;
            }
                    
        }

        /*****Nombre***************************************
        * SelectAux()
        *****Descripción**********************************
        * metodo que se encarga de buscar un nodo
        *****Retorno**************************************
        * Valor booleano dependiendo del resultado
        *****Entradas*************************************
        * Node* nodo
        * int id
        **************************************************/
        bool SelectAux(Node* pNodo, int id){
            if (pNodo->getID() == id){
                apNodoSeleccionado = pNodo;
                return true;
            }else{
                Node* temp = pNodo->getHijoPrimero();
                if (temp == nullptr){
                    return false;
                } else {
                    while (temp != apSubArbol){
                        while (temp != nullptr){
                            if(temp->getID() == id){
                                apNodoSeleccionado =  temp;
                                return true;
                            }else{
                                if (temp->getHijoPrimero() == nullptr){
                                    break;
                                }else{
                                    temp = temp->getHijoPrimero();
                                }
                            }
                        }
                        if (temp->getSigHermano() != nullptr){
                            temp = temp->getSigHermano();
                            while (temp != nullptr){
                                if (temp->getID() == id){
                                    apNodoSeleccionado = temp;
                                    return true;
                                }else{
                                    if(temp->getHijoPrimero() != nullptr){
                                        temp = temp->getHijoPrimero();
                                        SelectAux(temp,id);
                                    }else if(temp->getSigHermano() == nullptr){
                                        temp = temp->getPadre();
                                        break;
                                    }else{
                                        temp = temp->getSigHermano();
                                    }
                                }
                            }
                        }
                        while (temp != nullptr){
                            if (temp->getID() == id){
                                apNodoSeleccionado = temp;
                                return true;
                            }else{
                                if (temp->getSigHermano() != nullptr){
                                    temp = temp->getSigHermano();
                                    if (temp->getID() == id){
                                        apNodoSeleccionado = temp;
                                        return true;
                                    }else if (temp->getHijoPrimero() != nullptr){
                                        temp = temp->getHijoPrimero();
                                        SelectAux(temp,id);
                                    }
                                }
                                if (temp->getSigHermano() == nullptr){
                                    temp = temp->getPadre();
                                }else{
                                    temp = temp->getSigHermano();
                                }
                                if (temp == apSubArbol){
                                    break;
                                } 
                            }
                        }
                    }
                    return false;
                }
            }
        }
    
        /*****Nombre***************************************
         * Child()
         *****Descripción**********************************
        * metodo para ingresar un hijo al nodo seleccionado
        *****Retorno**************************************
        * el identificador del nuevo nodo hijo del nodo
        * seleccionado
        *****Entradas*************************************
        * char* pname
        **************************************************/
        int Child (char *pName){
            if (apNodoSeleccionado != nullptr){
                Node *nodo = new Node(pName, aContID++);
                if (apNodoSeleccionado->getHijoPrimero() == nullptr){
                    apNodoSeleccionado->setHijoPrimero(nodo);

                }else{
                    Node *temp = apNodoSeleccionado->getHijoPrimero();
                    while (temp->getSigHermano() != nullptr){
                        temp = temp->getSigHermano();
                    }
                    nodo->setAntHermano(temp);
                    temp->setSigHermano(nodo);
                }
                nodo->setPadre(apNodoSeleccionado);
                apNodoSeleccionado->setCantHijos();
                return nodo->getID();
            }else{
                return -1;
            }
            
        }

        /*****Nombre***************************************
         * Child()
         *****Descripción**********************************
        * metodo para ingresar un hijo al nodo seleccionado
        * con un contenido
        *****Retorno**************************************
        * el identificador del nuevo nodo hijo del nodo
        * seleccionado
        *****Entradas*************************************
        * char *name
        * char *content
        **************************************************/
        int Child (char *pName, char *pContent){
            if (apNodoSeleccionado != nullptr){
                Node *nodo = new Node(pName, aContID++);
                nodo->setContenido(pContent);
                if (apNodoSeleccionado->getHijoPrimero() == nullptr){
                    apNodoSeleccionado->setHijoPrimero(nodo);
                }else{
                    Node *temp = apNodoSeleccionado->getHijoPrimero();
                    while (temp->getSigHermano() != nullptr){
                        temp = temp->getSigHermano();
                    }
                    nodo->setAntHermano(temp);
                    temp->setSigHermano(nodo);
                }
                nodo->setPadre(apNodoSeleccionado);
                apNodoSeleccionado->setCantHijos();
                return nodo->getID();
            }else{
                return -1;
            }
            
        }

        /*****Nombre***************************************
         *Balancear()
         *****Descripción**********************************
        * metodo para configurar el nodo seleccionado 
        * en balanceado
        *****Retorno**************************************
        * Retorna true si se pudo dar la configuracion y 
        * retorna false si no se pudo dar la configuracion
        *****Entradas*************************************
        * No tiene
        **************************************************/
        bool Balancear(){
            if (apNodoSeleccionado->getHijoPrimero() == nullptr){
                if (apNodoSeleccionado->getContenido()!= (char *) ""){
                    apNodoSeleccionado->setBalanceado();
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }

        /*****Nombre***************************************
         * EliminarNodo()
         *****Descripción**********************************
        * Metodo para eliminar un nodo con las siguientes restricciones:
        * Si el nodo es balanceado se elimina el nodo y se rebalancea
        * Si el nodo no es balanceado se elimina todo el subarbol
        *****Retorno**************************************
        * Retorna true si la eliminacion se dio con exito
        * Retorna false si la eliminacion no se dio con exito
        *****Entradas*************************************
        * No tiene
        **************************************************/
        bool EliminarNodo(){
            if (apNodoSeleccionado == apRaiz){
                apRaiz->setHijoPrimero(nullptr);
                apNodoSeleccionado = nullptr;
                return true;
            }
            if (apNodoSeleccionado!= nullptr){
                if (apNodoSeleccionado->getBalanceado() == false){
                    Node* tempAnt = apNodoSeleccionado->getAntHermano();
                    Node* tempSig = apNodoSeleccionado->getSigHermano();
                    Node* tempPadre = apNodoSeleccionado->getPadre();
                    if (tempPadre->getHijoPrimero() != apNodoSeleccionado){
                        apNodoSeleccionado->setPadre(nullptr);
                        apNodoSeleccionado->setHijoPrimero(nullptr);
                        tempAnt->setSigHermano(tempSig);
                        apNodoSeleccionado = apRaiz;
                        return true; 
                    }else{
                        tempPadre->setHijoPrimero(tempSig);
                        tempSig->setPadre(tempPadre);
                        tempSig->setAntHermano(nullptr);
                        apNodoSeleccionado = apRaiz;
                        return true;
                    }
                                  
                }else{
                    return false; //Aqui va la eliminacion cuando el subarbol es balanceado
                }
            }else{
                return false;
            }
        }

        /*****Nombre***************************************
         * ViewNode
         *****Descripción**********************************
        * Muestra los datos del nodo
        *****Retorno**************************************
        * un char* con todos los datos del nodo
        *****Entradas*************************************
        * 
        **************************************************/
        char* ViewNode (){
            char* res = (char*)"";
            res = unirChar(res,(char*)"nombre: ");
            res = unirChar(res,apNodoSeleccionado->getNombre());
            res = unirChar(res,(char*)", ");
            res = unirChar(res,(char*)"id: ");
            res = unirChar(res,convertirChar(apNodoSeleccionado->getID()));
            res = unirChar(res,(char*)", ");
            res = unirChar(res,(char*)"contenido: ");
            res = unirChar(res,apNodoSeleccionado->getContenido());
            res = unirChar(res,(char*)", atributos: ");
            res = apNodoSeleccionado->mostrarAtributos(res);
            return res;
        }

        /*****Nombre***************************************
         * ViewTree
         *****Descripción**********************************
        * Muestra la estructura jerarquica del arbol
        *****Retorno**************************************
        * un char* con la estructura jerarquica del arbol
        *****Entradas*************************************
        * 
        **************************************************/
        char* ViewTree(){
            return VisualizarSubArbol(apNodoSeleccionado,(char*)"");
	
        }
        /*****Nombre***************************************
         * VisualizarSubArbol
         *****Descripción**********************************
        * muestra la estructura jerarquica de un subarbol
        *****Retorno**************************************
        * un char* con la estructura jerarquica de un subarbol
        *****Entradas*************************************
        * Node* pNodo
        * char* pTab
        **************************************************/
        char* VisualizarSubArbol(Node* pNodo,char* pTab){
            char *arbol = new char[1]();
            char *tabulacion = pTab;
            arbol[0] = ' ';
            arbol = unirChar(arbol,pTab);
            arbol = unirChar(arbol,convertirChar(pNodo->getID()));
            if(pNodo->getHijoPrimero()!=nullptr){
			    pTab=unirChar(pTab, (char*)"    ");
                for (Node* pHijo = pNodo->getHijoPrimero(); pHijo!= nullptr; pHijo = pHijo->getSigHermano()){
					arbol = unirChar(arbol,(char*)"\n");
					arbol = unirChar(arbol,VisualizarSubArbol(pHijo, pTab));
				}
			}
		    pTab = tabulacion;
		    return arbol;
        }

        /*****Nombre***************************************
         * PrevisualizarXML
         *****Descripción**********************************
        * Se encarga de verificar que la raiz no sea nula
        * para proceder a realizar a previsualizar en XML
        *****Retorno**************************************
        * Retorna el resultado de la funcion auxiliar
        *****Entradas*************************************
        * No tiene
        **************************************************/
        char* PrevisualizarXML(){
           char *arbol = new char[1]();
           if (apRaiz == nullptr){
		       return nullptr;
		   }
           arbol = unirChar(arbol,(char*)"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
           arbol = unirChar(arbol,(char*)"\n");
		   return apRaiz->PrevisualizarXMLAux((char*)"",arbol); 
        }
        
        /*****Nombre***************************************
         * convertirChar
         *****Descripción**********************************
        * convierte un entero a char
        *****Retorno**************************************
        * el numero entero convertido a char*
        *****Entradas*************************************
        * int numero
        **************************************************/
        char* convertirChar(int numero) {
            int temporal;
            temporal=0;
            int contador = 0;
            while(numero != 0){
                temporal =(temporal*10)+(numero%10);
                numero = numero/10;
                contador++;
            }
            char* respuesta;
            respuesta = new char[contador]();
            for (int i = 0; i < contador; i++){
                respuesta[i] = ((temporal%10)+48);
                temporal = temporal/10; 
            }
            return respuesta;
	    }

        /*****Nombre***************************************
         * largo
         *****Descripción**********************************
        * determina la cantidad de elementos en un char*
        *****Retorno**************************************
        * el largo de un char*
        *****Entradas*************************************
        * char* pName
        **************************************************/
        int largo(char* pName){
            int res = 0;
            while (pName[res] != '\0'){
                res++;
            }
            return res;
        }

        /*****Nombre***************************************
         * unirChar
         *****Descripción**********************************
        * une dos char*
        *****Retorno**************************************
        * la union de dos char*
        *****Entradas*************************************
        * char* pA
        * char* pB
        **************************************************/
        char* unirChar(char* pA, char* pB){
           int largo1 = largo(pA);
           int largo2 = largo(pB);
           int total = largo1 + largo2;
           char *cadena = new char[total + 1];
           for (int i = 0; i < total; i++){
               if (i < largo1){
                   cadena[i] = pA[i];
               } else {
                   cadena[i] = pB[i - largo1];
               }
           }
           return cadena;
       }
        /*****Nombre***************************************
        * guardar
        *****Descripción**********************************
        * Se encarga de guardar el arbol como un xml
        * en un archivo
        *****Retorno**************************************
        * Retorna un valor booleano true si se logro guardar
        * yy false si no se logro guardar
        *****Entradas*************************************
        * char* pFilename
        **************************************************/
       bool guardar(char* pFilename){
           FILE *pFile;
           pFile = fopen(pFilename, "w");
           fprintf(pFile, "%s\n",PrevisualizarXML());	
           fclose(pFile);
           return true;
       }

        Node* getRaiz(){
            return apRaiz;
        }

        Node* getSeleccionado(){
            return apNodoSeleccionado;
        }

        void setRaiz(Node* pRaiz){
            apRaiz = pRaiz;
        }

        void setSeleccionado(Node* pSeleccionado){
            apNodoSeleccionado = pSeleccionado;
        }
};
#endif