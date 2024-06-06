# OBJETIVO DE ESTE PROYECTO
El objetivo de este proyecto ***get_next_line*** es crear una función a la que se le pasa un File Descriptor (fd) del que leer, y si todo va bien, devuelve la línea leída.


En caso de fallo o lectura terminada, devuelve NULL.

IMPORTANTE: Se va a devolver cada una de las líneas leídas seguidas de un salto de línea ('\n'), excepto si ha llegado al final del archivo. Si después del último salto de línea no existe nada más, esa línea la debe devolver como NULL, no como línea vacía.


Conocimientos previos que es preferible tener para comprender el ejercicio:
-
- Una **variable estática** es aquella que no necesita ser inicializada, y es capaz de mantener el contenido que tenía en cada nueva llamada.
- El descriptor o **fd** es un número entero que apunta a un archivo que está abierto y desde donde se pueden leer bytes.
- Para obtener el fd se usa la función **OPEN**, que devuelve un número entero, o -1 en caso de error. Existen varias banderas con la forma de apertura:
   ```
    --> O_RDONLY. Modo lectura. Es el que usaré en este caso
    --> O_WRONLY. Modo escritura
    --> O_RDWR. Modo lectura y escritura
   ```
- Para leer se utiliza la función **READ**, que lee de un fd previamente abierto.
  ```
  Su prototipo es: read(int fd, void *buf, size_t BUFFER_SIZE)
  ```
  donde *buf es un puntero donde se almacena lo que se va leyendo, y BUFFER_SIZE indica la cantidad de bytes que se van leyendo cada vez.

## Funcionamiento de mi función:
- El BUFFER_SIZE va a ir variando, debo probar varias tamaños para comprobar el funcionamiento. Y debo definirlo en el archivo .h

  
- Creo un bucle while que me va a ir leyendo los bytes que me indique BUFFER_SIZE hasta que encuentre un salto de línea. Pero ***OJO***, lo más seguro es que el salto de línea me quede entre varios caracteres debido a que leo según me indique BUFFER_SIZE
- Por tanto necesito una función (*one_line*) que me vaya recorriendo hasta que encuentre el salto de línea, y lo almacene en un puntero. Este puntero es lo que va a ir devolviendo mi función en cada llamada.
- También necesito una función (*beggining_next_line*) que me almacene todo lo leído detrás del salto de línea, para indicarle que ahí es donde tiene que empezar a leer la siguiente vez que se llame a la función. Esto se almacena en la variable **estática**.
- En el main es donde se va a utilizar la función OPEN y también CLOSE

Una de las claves principales para tener éxito en este ejercicio es saber controlar los **leaks de memoria**, que son errores que ocurren cuando un proceso gestiona mal la memoria, es decir, cuando se reserva memoria sin liberarla.

Existe una parte **BONUS**, que consiste en ser capaz de gestionar varios fd a la vez. Para ello establezco un array de punteros del mayor tamaño posible (FD_SETSIZE)
