#ifndef NODE_HPP
#define NODE_HPP
#include "atribute.hpp"


/*****Nombre***************************************
 * Node
 *****Descripción**********************************
 * Clase del objeto Nodo que conforman el arbol
 *****Atributos************************************
 * char* apNombre;
 * char* apContenido;
 * int aID;
 * int aCantHijos;
 * bool aContentBefore;
 * bool aBalanceado;
 * Node* apPadre;
 * Node* apHijoPrimero;
 * Node* apSigHermano;
 * Node* apAntHermano;
 * Atribute* apPrimerAtributo;
 *****Métodos**************************************
 * Node(char* pNombre, int ID)
 * addAtribute(char *pKey, char *pValue)
 * appAtribute(char *pKey, char *pValue)
 * delAtribute(char *pKey, char *pValue)
 * ovrAtribute(char *pKey, char *pValue)
 * guardarAtributo(char *pKey, char *pValue)
 * mostrarAtributos(char* pRes)
 * buscarAtributo(char* pKey)
 * compare (char *pS1, char *pS2)
 * largo(char* pName)
 * addContent(char* pContent)
 * ovrContent(char* pContent)
 * appContent(char* pContent)
 * delContent(char* pContent)
 **************************************************/
class Node{
    private:
        char* apNombre;
        char* apContenido;
        int aID;
        int aCantHijos;
        bool aContentBefore;
        bool aBalanceado;
        Node* apPadre;
        Node* apHijoPrimero;
        Node* apSigHermano;
        Node* apAntHermano;
        Atribute* apPrimerAtributo;

    public:

        /*****Nombre***************************************
        * Node
         *****Descripción**********************************
        * Metodo constructor de la clase Node
        *****Retorno**************************************
        * 
        *****Entradas*************************************
        * char* pNombre
        * int ID
        **************************************************/
        Node(char* pNombre, int ID){ 
            apNombre = pNombre;
            aID = ID;
            aCantHijos = 0;
            aContentBefore = true;
            aBalanceado = false;
            apContenido = (char*)"";
            apPadre = nullptr;
            apHijoPrimero = nullptr;
            apSigHermano = nullptr;
            apAntHermano = nullptr;
            apPrimerAtributo = nullptr;
        }

        /*****Nombre***************************************
         * addAtribute
         *****Descripción**********************************
        * agrega informacion al principio del valor de un atributo
        *****Retorno**************************************
        * true si se guarda la informacion, false si no existe el atributo
        * y se crea en este caso
        *****Entradas*************************************
        * char *pKey
        * char pValue
        **************************************************/
        bool addAtribute(char *pKey, char *pValue){
            Atribute* atributo = buscarAtributo(pKey);
            if (atributo != nullptr){
                return atributo->addAtribute(pValue);
            } else {
                guardarAtributo(pKey, pValue);
                return false;
            }
            
        }

        /*****Nombre***************************************
         * appAtribute
         *****Descripción**********************************
        * agrega informacion al final del valor de un atributo
        *****Retorno**************************************
        * true si se guarda la informacion, false si no existe el atributo
        * y se crea en este caso
        *****Entradas*************************************
        * char *pKey
        * char *pValue
        **************************************************/
        bool appAtribute(char *pKey, char *pValue){
            Atribute* atributo = buscarAtributo(pKey);
            if (atributo != nullptr){
                return atributo->appAtribute(pValue);
            } else {
                guardarAtributo(pKey, pValue);
                return false;
            }
        }

        /*****Nombre***************************************
        * delAtribute
         *****Descripción**********************************
        * Elimina los datos que se almacena en el valor del
        * atributo
        *****Retorno**************************************
        * true si existe el nodo y false si no existe
        *****Entradas*************************************
        * char *pKey
        * char *pValue
        **************************************************/
        bool delAtribute(char *pKey, char *pValue){
            Atribute* atributo = buscarAtributo(pKey);
            if (atributo != nullptr){
                return atributo->delAtribute(pValue);
            } else {
                return false;
            }
        }

        /*****Nombre***************************************
        * ovrAtribute
         *****Descripción**********************************
        * Sobreescribe el valor del atributo
        *****Retorno**************************************
        * true si existe el nodo y false si no existe
        *****Entradas*************************************
        * char *pKey
        * char *pValue
        **************************************************/
        bool ovrAtribute(char *pKey, char *pValue){
            Atribute* atributo = buscarAtributo(pKey);
            if (atributo != nullptr){
                return atributo->ovrAtribute(pValue);
            } else {
                return false;
            }
        }

        /*****Nombre***************************************
         * guardarAtributo
         *****Descripción**********************************
        * agrega un atributo al nodo
        *****Retorno**************************************
        * 
        *****Entradas*************************************
        * char *pKey
        * char *pValue
        **************************************************/
        void guardarAtributo(char *pKey, char *pValue){
            Atribute* nuevo = new Atribute(pKey, pValue);
            if (apPrimerAtributo == nullptr){
                apPrimerAtributo = nuevo;
            } else {
                Atribute *temp = apPrimerAtributo;
                while (temp->getSig() != nullptr){
                    temp = temp->getSig();
                }
                temp->setSig(nuevo);
            }
        }

        /*****Nombre***************************************
        * mostrarAtributos
         *****Descripción**********************************
        * muestra los atributos del nodo
        *****Retorno**************************************
        * un char con la informacion de los atributos del nodo
        *****Entradas*************************************
        * char* pRes
        **************************************************/
        char* mostrarAtributos(char* pRes){
            Atribute* temp = apPrimerAtributo;
            while (temp != nullptr){
                pRes = unirChar(pRes,(char*)"[key: ");
                pRes = unirChar(pRes,temp->getKey());
                pRes = unirChar(pRes,(char*)" ,valor: ");
                pRes = unirChar(pRes,temp->getValue());
                pRes = unirChar(pRes,(char*)"] ");
                temp = temp->getSig();
            }
            return pRes;
        }

        /*****Nombre***************************************
        * buscarAtributo
         *****Descripción**********************************
        * verifica la existencia de un atributo en el nodo
        *****Retorno**************************************
        * un objeto tipo Atribute si existo y nullptr si no
        *****Entradas*************************************
        * char* pKey
        **************************************************/
       Atribute* buscarAtributo(char* pKey){
           Atribute *temp = apPrimerAtributo;
           while (temp != nullptr){
               if (compare(pKey, temp->getKey())){
                   return temp;
               }
               temp = temp->getSig();
           }
           return temp;
       }

        /*****Nombre***************************************
        * compare
         *****Descripción**********************************
        * Compara dos char*
        *****Retorno**************************************
        * true si ambos char* son iguales, false si no
        *****Entradas*************************************
        * char* pS1
        * char* pS2
        **************************************************/
       bool compare (char* pS1, char* pS2){
           int i = 0;
           while (pS1[i] != '\0' || pS2[i] != '\0'){
               if (pS1[i] != pS2[i]){
                   break;
               }
               i++;
            }
            if (pS1[i] == '\0' && pS2[i] == '\0'){
                return true;
            }
            return false;
       }

        /*****Nombre***************************************
        * largo
         *****Descripción**********************************
        * determina la cantidad de elementos en un char*
        *****Retorno**************************************
        * la cantidad de elementos en un char*
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
         * addContent
         *****Descripción**********************************
        * agrega informacion al principio del contenido
         * del nodo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pContent
        **************************************************/
       bool addContent(char* pContent){
           apContenido = unirChar(pContent,apContenido);
           return true;
       }

        /*****Nombre***************************************
         * ovrContent
         *****Descripción**********************************
        * sobreescribe la informacion del contenido del nodo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pContent
        **************************************************/
       bool ovrContent(char* pContent){
           apContenido = pContent;
           return true;
       }

        /*****Nombre***************************************
         * appContent
         *****Descripción**********************************
        * agrega informacion al final del contenido
         * del nodo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pContent
        **************************************************/
       bool appContent(char* pContent){
           apContenido = unirChar(apContenido, pContent);
           return true;
       }

        /*****Nombre***************************************
         * delContent
         *****Descripción**********************************
        * borra la informacion almacenada en el contenido
        * del nodo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pContent
        **************************************************/
        bool delContent(char* pContent){
            char* valor = unirChar(apContenido,(char*)"");
            int largoValor = largo(valor);
            int largoBorrar = largo(pContent);
            if (largoBorrar > largoValor){
                return false;
            }
            char* temp = (char*)malloc(largoValor - largoBorrar);
            char* temp2 = valor;
            for (int pos = 0; pos < (largoValor - largoBorrar); pos++){
                if (pos > largoValor - largoBorrar){
                    return false;
                }
                if(temp2[pos] == pContent[0]){
                    bool bandera = prubIs(temp2,pos,pContent,largoBorrar);
                    if (bandera){
                        int y = 0;
                        for (int i = 0; (largoValor - largoBorrar)+1 > i; i++){
                            if (i == pos){
                                if (i + largoBorrar >= largoValor){
                                    return false;
                                }else{
                                    temp[i] = valor[y + largoBorrar];
                                    y = y+largoBorrar+1;
                                }
                            }else{
                                temp[i] = valor[y];
                                y++;
                            }
                         apContenido = temp;   
                        }return true;
                    }
                }
            }
        return false;
       }

       bool prubIs(char* pTemp, int pos, char* pBorrar, int largoBorrar){
           for(int i = 0; largoBorrar > i; i++){
               if (pTemp[pos] != pBorrar[i]){
                   return false;
               }
               pos++;
           }
           return true;
       }

       /*****Nombre***************************************
        * PrevisualizarXMLAux
        *****Descripción**********************************
        * Se encarga de previsualizar el arbol como un xml
        *****Retorno**************************************
        * Retorna la cadena de caracteres con la
        * previsualizacion del arbol en xml
        *****Entradas*************************************
        * char* pTab
        * char* pArbol
        **************************************************/
        char* PrevisualizarXMLAux(char* pTab, char* pArbol){
            char *tabulacion = pTab;
            pArbol = unirChar(pTab, pArbol);
            pArbol = unirChar(pArbol, (char*)"< ");
            pArbol = unirChar(pArbol, apNombre);
            pArbol = unirChar(pArbol, (char*)" > ");
            pArbol = unirChar(pArbol, PreviewAtributos());

            if((apHijoPrimero != nullptr) || (apPrimerAtributo != nullptr) || (apContenido != nullptr)){
                pTab=unirChar(pTab, (char*)"\t");
                if (aContentBefore == true && apContenido!=(char*)""){
                    pArbol = unirChar(pArbol, (char*)"\n");
                    pArbol = unirChar(pArbol, pTab );
                    pArbol = unirChar(pArbol, (char*)"Contenido:");
                    pArbol = unirChar(pArbol, apContenido);
                }
                Node* pHijo = nullptr;
                pArbol = unirChar(pArbol, (char*)"\n");
                if(apHijoPrimero!=nullptr){
                    for (pHijo = apHijoPrimero; pHijo!= nullptr; pHijo = pHijo->getSigHermano()){
                        pArbol = unirChar(pArbol,pHijo->PrevisualizarXMLAux(pTab,(char*)""));
                    }
                }
                if (aContentBefore == false && apContenido!=(char*)""){
                    pArbol = unirChar(pArbol, pTab );
                    pArbol = unirChar(pArbol, (char*)"Contenido:");
                    pArbol = unirChar(pArbol, apContenido);
                    pArbol = unirChar(pArbol,(char*)"\n");
                    pTab=unirChar(pTab, (char*)"\t");
                }
                pTab = tabulacion;
                pArbol = unirChar(pArbol, pTab );
            }
            pTab = tabulacion;
            pArbol = unirChar(pArbol, (char*)" </ ");
            pArbol = unirChar(pArbol, apNombre);
            pArbol = unirChar(pArbol, (char*)" > ");

            pArbol = unirChar(pArbol,(char*)"\n");
            return pArbol;
        }
    

        /*****Nombre***************************************
        * PreviewAtributos
        *****Descripción**********************************
        * RSe encarga de recorrer toodos los atributos 
        * de un nodo
        *****Retorno**************************************
        * Retorna todos los atributos de un nodo
        *****Entradas*************************************
        * No hay 
        **************************************************/

        char* PreviewAtributos(){
            Atribute* pAtributo = nullptr;
            char *pAtributos = new char();
            bool entro = false;
            if(apPrimerAtributo!=nullptr){
                pAtributos = unirChar(pAtributos, (char*)" Atributos: ");

                entro = true;
                for (pAtributo = apPrimerAtributo; pAtributo != nullptr; pAtributo = pAtributo->getSig()){
                    pAtributos = unirChar(pAtributos, (char*)" ");
                    pAtributos = unirChar(pAtributos, pAtributo->getKey());
                    pAtributos = unirChar(pAtributos, (char*)" = ");
                    pAtributos = unirChar(pAtributos, pAtributo->getValue());
                }
            } 
            return pAtributos;
        }

        int getCantHijos(){
            return aCantHijos;
        }

        char* getContenido(){
            return apContenido;
        }

        char* getNombre(){
            return apNombre;
        }

        int getID(){
            return aID;
        }

        Node* getPadre(){
            return apPadre;
        }

        Node* getSigHermano(){
            return apSigHermano;
        }

        Node* getHijoPrimero(){
            return apHijoPrimero;
        }

        bool getContBefore(){
            return aContentBefore;
        }

        bool getBalanceado(){
            return aBalanceado;
        }

        Node* getAntHermano(){
            return apAntHermano;
        }

        void setCantHijos(){
            aCantHijos++;
        }

        void setContenido(char *pContenido){
            apContenido = pContenido;
        }

        void setNombre(char* pNombre){
            apNombre = pNombre;
        }

        void setID(int ID){
            aID = ID;
        }

        void setPadre(Node* pPadre){
            apPadre = pPadre;
        }

        void setSigHermano(Node* pHermano){
            apSigHermano = pHermano;
        }

        void setAntHermano(Node* pHermano){
            apAntHermano = pHermano;
        }

        void setHijoPrimero(Node* pHijo){
            apHijoPrimero = pHijo;
        }

        void setContBefore(){
            if (aContentBefore == true){
                aContentBefore = false;
            }else{
                aContentBefore = true;
            }
        }
        void setBalanceado(){
            aBalanceado = true;
        }
};
#endif