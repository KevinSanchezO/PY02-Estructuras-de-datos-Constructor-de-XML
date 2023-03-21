#ifndef XMLDOCUMENT_HPP
#define XMLDOCUMENT_HPP
#include "tree.hpp"
#include "node.hpp"
#include "atribute.hpp"

/*****Nombre***************************************
 * XMLDocument
 *****Descripción**********************************
 * Plantilla para crear, modificar y guardar una
 * estructura jerarquica en un archivo XML
 *****Atributos************************************
 * Tree *arbol
 *****Métodos**************************************
 * Root (char *pName)
 * Select (int id)
 * Child (char *pName)
 * Child (char *pName, char *pContent)
 * EditAttribute (char *pKey, char *pValue, int mode)
 * EditContent (char *pContent, int mode)
 * SwitchContentPosition ()
 * SetBalanced ()
 * Delete ()
 * ViewTree ()
 * ViewNode ()
 * ViewXML ()
 * Save (char *pFilename)
 **************************************************/
class XMLDocument{
private:
	Tree *arbol = new Tree();

public:
    // Function operating modes, use the constant names and not the values in the code
	const int ADD = 100;	// Mode addition, adds the value to the beginning of the set
                                // as allowed by the specific function (with or without repetition)
	const int OVR = 200;	// Mode overwrite, if it already exists, replaces the value, if not, just add it.
	const int APD = 300;	// Mode append, appends the value to the end of the set as
                                // allowed by the specific function (with or without repetition)
	const int DEL = 400;	// Mode delete, if the value exists, it is deleted instead
	
	// Node content location type
	const int BEG = 10;		// Content is displayed before children of node, just after the opening tag.
	const int END = 20;		// Content is displayed after children of node, just before the closing tag.

	// Public functions

	/*****Nombre***************************************
	* Root
	 *****Descripción**********************************
	* agregar una raiz
	*****Retorno**************************************
	* el id de la raiz
	*****Entradas*************************************
	* char* pName
	**************************************************/
	int   Root (char *pName){
		int res = arbol->Root(pName);
		return res;
	}

	/*****Nombre***************************************
	 * Select
	 *****Descripción**********************************
	* Permite cambiar el nodo seleccionado
	*****Retorno**************************************
	* un bool dependiendo si se pudo seleccionar el
	* nodo
	*****Entradas*************************************
	* int id
	**************************************************/
	bool  Select (int id){
		bool res = arbol->Select(id);
		return res;
	}

	/*****Nombre***************************************
	* Child 
	 *****Descripción**********************************
	* agrega un hijo al nodo seleccionado
	*****Retorno**************************************
	* el id del nuevo hijo del nodo seleccionado
	*****Entradas*************************************
	* char* pName
	**************************************************/
	int   Child (char *pName){
		int res = arbol->Child(pName);
		return res;
	}

	/*****Nombre***************************************
	* Child
	 *****Descripción**********************************
	* agrega un hijo al nodo seleccionado con el contenido
	*****Retorno**************************************
	* el id del nuevo hijo del nodo seleccionado
	*****Entradas*************************************
	* char* pName
	* char* pContent
	**************************************************/
	int   Child (char* pName, char* pContent){
		int res = arbol->Child(pName, pContent);
		return res;
	}

	/*****Nombre***************************************
	*  EditAttribute
	 *****Descripción**********************************
	* Permite editar un atributo con el modo deseado
	*****Retorno**************************************
	* un bool dependiendo si se pudo realizar la operacion
	*****Entradas*************************************
	* char* pKey
	* char* pValue
	* int mode
	**************************************************/	
	bool  EditAttribute (char *pKey, char *pValue, int mode){
		if (arbol->getSeleccionado() != nullptr){
			Node* pNodo = arbol->getSeleccionado();
			if (mode == ADD){
				return pNodo->addAtribute(pKey, pValue);
			} else if (mode == OVR){
				return pNodo->ovrAtribute(pKey, pValue);
			} else if (mode == APD){
				return pNodo->appAtribute(pKey, pValue);
			} else if (mode == DEL){
				return pNodo->delAtribute(pKey, pValue);
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	/*****Nombre***************************************
	* EditContent
	 *****Descripción**********************************
	* permite editar el contenido del nodo seleccionado
	*****Retorno**************************************
	* un bool dependiendo si se pudo realizar la operacion
	*****Entradas*************************************
	* char* pContent
	* int mode
	**************************************************/
	bool  EditContent (char *pContent, int mode){
		if (arbol->getSeleccionado() != nullptr){
			Node* pNodo = arbol->getSeleccionado();
			if (mode == ADD){
				return pNodo->addContent(pContent);
			} else if (mode == OVR){
				return pNodo->ovrContent(pContent);
			} else if (mode == APD){	
				return pNodo->appContent(pContent);
			} else if (mode == DEL){
				return pNodo->delContent(pContent);
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	/*****Nombre***************************************
	* SwitchContentPosition
	 *****Descripción**********************************
	* Cambia la forma en donde se muestra el contenido
	*****Retorno**************************************
	* un bool dependiendo si pudo hacer la operacion
	*****Entradas*************************************
	* 
	**************************************************/
	bool  SwitchContentPosition (){
		if(arbol->getSeleccionado() != nullptr){
			arbol->getSeleccionado()->setContBefore();
			return true;
		}else{
			return false;
		}
	}

	/*****Nombre***************************************
	 * setBalanced
	 *****Descripción**********************************
	* cambia el modo de balance del nodo seleccionado
	*****Retorno**************************************
	* un bool dependiendo si pudo hacer la operacion
	*****Entradas*************************************
	* 
	**************************************************/
	bool  SetBalanced (){
		bool res = arbol->Balancear();
		return res;
	}

	/*****Nombre***************************************
	 * Delete
	 *****Descripción**********************************
	* borra al nodo seleccionado de la estructura
	*****Retorno**************************************
	* un bool dependiendo de si se pudo hacer la operacion
	*****Entradas*************************************
	* 
	**************************************************/	
	bool  Delete (){
		bool res = arbol->EliminarNodo();
		return res;
	} 
	
	/*****Nombre***************************************
	 * ViewTre
	 *****Descripción**********************************
	* Muestra la estructura jerarquica del nodo
	* seleccionado
	*****Retorno**************************************
	* un char* con toda la estructura jerarquica
	*****Entradas*************************************
	* 
	**************************************************/	
	char* ViewTree (){
		char* res = arbol->ViewTree();
		return res;
	}

	/*****Nombre***************************************
	 * ViewNode
	 *****Descripción**********************************
	* Muestra los datos del nodo seleccionado
	*****Retorno**************************************
	* un char* con los datos del nodo seleccionado
	*****Entradas*************************************
	* 
	**************************************************/
	char* ViewNode (){
		char* res = arbol->ViewNode();
		return res;
	}

	/*****Nombre***************************************
	* ViewXML 
	 *****Descripción**********************************
	* permite previsualizar el documento XML
	*****Retorno**************************************
	* un char* con la previsualizacion del documeto XML
	*****Entradas*************************************
	* 
	**************************************************/
	char* ViewXML (){
		char* res = arbol->PrevisualizarXML();
		return res;
	}

	/*****Nombre***************************************
	* Save 
	 *****Descripción**********************************
	* guarda la estructura jerarquica en un archivo XML
	*****Retorno**************************************
	* un bool dependiendo de si se pudo hacer la operacion
	*****Entradas*************************************
	* char* pFilename
	**************************************************/
	bool  Save (char* pFilename){
		bool res = arbol->guardar(pFilename);
		return res;
	}	
};

#endif