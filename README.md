# PY02-Estructuras-de-datos-Constructor-de-XML
Construir una librería de funciones que se pueda agregar a otros programas para confeccionar estructuras y archivos basados en XML bien formados.

## Implementación

<p>La librería debe construirse con los siguientes lineamientos:</p>
<ol>
 <li>Se creará una clase llamada XMLDocument, la cual será un controlador de la creación de las estructuras y los archivos XML, que podrá ser incluida en cualquier otro programa por medio de un archivo de encabezado. Esta debe colocarse en un archivo llamado XMLDocument.hpp</li>
 <li>La librería no debe hacer ningún tipo de impresión en pantalla, ni debe solicitar información de teclado. Únicamente debe trabajar con los parámetros de las funciones públicas de la clase.</li>
 <li>Esta librería debe permitir realizar las siguientes acciones:
 <ul>
 <li>Insertar un nuevo nodo raíz: recibe el nombre de la etiqueta raíz nueva que se va a utilizar y lo convierte en la nueva raíz del XML. Si antes de insertar el nodo raíz el árbol se encontraba vacío, este nodo se selecciona automáticamente. Retorna el ID asignado al nuevo nodo creado.</li>
 <li>Seleccionar un nodo del documento: por medio del ID asignado por parte de la estructura de control del XML se indica este nodo como el activo para las funciones de esta lista que trabajen sobre el nodo seleccionado. Al estar la estructura vacía, no debe haber nodo seleccionado, al ingresar el primer nodo se puede elegir entre seleccionarlo automáticamente o que la estructura permanezca sin nodo seleccionado.</li>
 <li>Agregar un nodo hijo al nodo seleccionado: tiene dos variantes, en la primera recibe el nombre de un nuevo nodo hijo que debe agregarse bajo el nodo que se encuentre seleccionado actualmente y en la segunda recibe adicionalmente contenido para el nodo. Se aceptan nodos hijos con nombres repetidos. En ambos casos se debe retornar el ID asignado al nuevo nodo que se inserta.</li>
 <li>Editar atributos o contenido de un nodo actual: los atributos se agregan como pares llave-valor, por lo que se reciben estos parámetros mientras que el contenido es únicamente el valor de lo que se agrega. Estos se pueden ejecutar en modo de agregado, adjunto, sobre escritura o borrado. No puede existir atributos con llaves repetidas y cada nodo tiene únicamente un contenido.</li>
 <li>Modificar el modo de visualización del contenido del nodo seleccionado: El contenido se puede desplegar ya sea antes o después de los nodos hijos del nodo que corresponde, por lo que esta función tiene como efecto cambiar entre uno y otro modo.</li>
 <li>Configurar el nodo seleccionado como raíz de un subárbol balanceado: únicamente se realiza si no tiene hijos y tiene contenido diferente de vacío en el momento de la configuración, se indica en la estructura que a partir de este punto se debe manejar un subárbol balanceado. Todos los hijos que se agreguen en esta subestructura deben ser consecuentemente balanceados a partir de este punto durante los procesos de inserción y borrado, sin modificar la estructura superior al nodo raíz. Las inserciones en un subárbol balanceado se pueden hacer únicamente a partir de la raíz del mismo y será balanceado utilizando el contenido del nodo que se está insertando. No se permiten modificaciones a los contenidos de los nodos dentro de esta subestructura.</li>
 <li>Eliminar el nodo seleccionado: se puede solicitar el borrado de un nodo, lo cual lo elimina de la estructura. Si el nodo no es balanceado, se borra el subárbol completo que se encuentra a partir de este nodo. Para los nodos balanceados, únicamente se elimina el nodo y se rebalancea el árbol restante.</li>
 <li>Visualizar subárbol: retorna la información jerárquica del árbol que tiene como raíz el nodo actualmente seleccionado, los nodos deben poder identificarse, pero no deben visualizarse completos todos sus atributos.</li>
 <li>Visualizar nodo seleccionado: muestra los valores asociados al nodo que se encuentra actualmente seleccionado directamente, deben ser claras todas las partes del nodo, sin tener que seguir los enlaces a sus hijos.</li>
 <li>Previsualizar XML: retorna la cadena de caracteres que contiene el XML correspondiente a la configuración actual de la estructura.</li>
 <li>Guardar el árbol en un archivo: recibe el nombre de un archivo en donde se desea guardar el XML resultante.</li>
 </ul>
 <li>En todos los casos que no se especifica un valor de retorno, se utilizan valores booleanos para indicar el éxito o el fallo en el proceso solicitado. Si los retornos están especificados, deben retornarse valores que se puedan reconocer como error en caso que sucedan circunstancias que eviten el proceso solicitado.</li>
 </li>
 <li>Las operaciones de edición de atributos o contenidos, se pueden ejecutar en uno de cuatro modos: agregar, adjuntar, sobreescribir o borrar. Agregar y adjuntar mantienen el texto previo pero agregan el texto recibido por parámetro al inicio o final, respectivamente. Sobreescribir reemplaza el texto anterior con el nuevo. Borrar elimina todas las instancias del texto que se recibe por parámetro en el contenido actual del nodo, si el parámetro tiene el texto vacío borra todo el texto.</li>
<li>Para realizar pruebas, puede incluir un archivo principal cpp con algunas llamadas de funciones dentro de la librería o que pueda manipular llamadas a esta por medio de un menú, teniendo en cuenta que esto no es parte del programa por construir y que no será parte de la evaluación del proyecto.</li>
<li>Debe respetarse la siguiente plantilla general de los contenidos públicos que deben encontrarse en el archivo XMLDocument.hpp</li>
<li>Puede agregar tantos elementos privados en el archivo de la librería solicitada además de crear otros archivos de encabezado, de implementación y de recursos según considere necesario.</li>
</ol>

## Plantilla de XMLDocument.hpp

```

class XMLDocument {
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
	int   Root (char *name);
	bool  Select (int id);
	int   Child (char *name);
	int   Child (char *name, char *content);
	bool  EditAttribute (char *key, char *value, int mode);
	bool  EditContent (char *content, int mode);
	bool  SwitchContentPosition ();
	bool  SetBalanced ();
	bool  Delete ();
	char* ViewTree ();
	char* ViewNode ();
	char* ViewXML ();
	bool  Save (char *filename);
}

```
