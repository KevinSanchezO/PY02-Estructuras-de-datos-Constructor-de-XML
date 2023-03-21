#ifndef ATRIBUTE_HPP
#define ATRIBUTE_HPP

/*****Nombre***************************************
 * Atribute
 *****Descripción**********************************
 * Clase del objeto Atribute que se agregaran a los
 * nodos 
 *****Atributos************************************
 * char* apKey;
 * char* apValue;
 * Atribute* apSig;
 *****Métodos**************************************
 * Atribute (char* pKey, char* pValue)
* unirChar(char* pA, char* pB)
 * addAtribute(char* pAddValue)
 * appAtribute(char* pAppValue)
 * ovrAtribute(char* pOvrValue)
 * delAtribute(char* pDelValue)
 * prubIs(char* temp, int pos, char* borrar, int largoBorrar)
 * largo(char* pName)
 **************************************************/
class Atribute{
    private:
        char* apKey;
        char* apValue;
        Atribute* apSig;
    public:
        /*****Nombre***************************************
         * Atribute
         *****Descripción**********************************
        * metodo constructor de la clase Atribute
        *****Retorno**************************************
        * 
        *****Entradas*************************************
        * char* pKey
        * char* pValue
        **************************************************/
        Atribute(char* pKey, char* pValue){
            apKey = pKey;
            apValue = pValue;
            apSig = nullptr;
        }

        /*****Nombre***************************************
         * unirChar
         *****Descripción**********************************
        * une dos char*
        *****Retorno**************************************
        * la union de dos char*
        *****Entradas*************************************
        * char* pa
        * char* pb
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
         * addAtribute
         *****Descripción**********************************
        * agrega informacion al principio del valor de un atributo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pAddValue
        **************************************************/
        bool addAtribute(char* pAddValue){
            apValue = unirChar(pAddValue, apValue);
            return true;
        }

        /*****Nombre***************************************
         * appAtribute
         *****Descripción**********************************
        * agrega informacion al final del valor de un atributo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char* pAppValue
        **************************************************/
       bool appAtribute(char* pAppValue){
            apValue = unirChar(apValue, pAppValue);
            return true;
        }

        /*****Nombre***************************************
        * ovrAtribute
         *****Descripción**********************************
        * Sobreescribe el valor del atributo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char *pOvrValue
        **************************************************/
       bool ovrAtribute(char* pOvrValue){
           apValue = pOvrValue;
           return true;
       }

        /*****Nombre***************************************
        * delAtribute
         *****Descripción**********************************
        * Elimina los datos que se almacena en el valor del
        * atributo
        *****Retorno**************************************
        * bool de como se realizo la operacion
        *****Entradas*************************************
        * char *pDelValue
        **************************************************/
       bool delAtribute(char* pDelValue){
            char* valor = unirChar(apValue,(char*)"");
            int largoValor = largo(valor);
            int largoBorrar = largo(pDelValue);
            if (largoBorrar > largoValor){
                return false;
            }
            char* temp = (char*)malloc(largoValor - largoBorrar);
            char* temp2 = valor;
            for (int pos = 0; pos < (largoValor - largoBorrar); pos++){
                if (pos > largoValor - largoBorrar){
                    return false;
                }
                if(temp2[pos] == pDelValue[0]){
                    bool bandera = prubIs(temp2,pos,pDelValue,largoBorrar);
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
                         apValue = temp;   
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

        char* getKey(){
            return apKey;
        }

        char* getValue(){
            return apValue;
        }

        Atribute* getSig(){
            return apSig;
        }

        void setSig(Atribute* pSig){
            apSig = pSig;
        }
};

#endif