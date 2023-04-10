Estructura de directorios
=========================
Referencia sobre la estructura empleada.

``bin``
-------
*binaries*

Archivos ejecutables finales. Absolutamente todo lo que se necesite para
ejecutar el archivo .exe necesario deberá encontrarse aquí en el momento de
la ejecución, pero este directorio se genera automáticamente a partir de la
configuración del proyecto. Por ello no se suben a GitHub.

``docs``
--------
*documentation*

Archivos que no intervienen en el funcionamiento del proyecto, pero sirven
para organizar y entender el trabajo de todos los miembros. Por ejemplo,
este. También otros esquemas y demás que puedan ser de utilidad.

``libraries``
-------------
Código y librerías de fuentes externas se incluyen aquí.
 * ``dlls``
   Librerías de compilación dinámica ``.dll`` que se copiarán a ``bin/``
 * ``include``
   Las cabeceras que deben ser conocidas por el compilador (``.h`` o ``.hpp``)
 * ``libs``
   Librerías de compilación estática ``.lib``

``src``
-------
*source*

Todos los archivos de código fuente del proyecto. Se trabaja principalmente
aquí. Archivos .c, .cpp, .h, .hpp que pueden estar o no organizados en
subdirectorios.

``res``
-------
*resources*

Recursos no relacionados a la programación que intervienen en la ejecución del
juego. Imágenes, audio, modelos 3D, lo que sea.
