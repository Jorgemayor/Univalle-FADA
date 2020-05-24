# Estructuración de las entradas

La primera línea consiste en tres enteros, 1 <= N <= 3\*M\*K, el número de animales; 1 <= M <= 60, el número de espectáculos; y  1 <= K <= N, el número de escenas por espectáculo, seguido de n líneas con una cadena de caracteres S (incluye mayúculas y minúsculas) separada por un espacio de un entero 1 <= G <= N, equivalente a su grandeza. Está garantizado que la grandeza de cada animal es diferente.

Posteriormente se tiene un párrafo, con (m-1)k líneas, correspondiente a la apertura, en cada una hay 3 cadenas de caracteres iguales a algunas de las n cadenas citadas anteriormente, cada una de estas líneas corresponde a una escena de la apertura. Cabe aclarar que todas las n cadenas (animales) deben ser usadas en al menos una escena de la apertura.

Luego se tienen (m-1) párrafos con k líneas, que corresponden a las partes posteriores a la apertura. Las líneas de estas partes son extraídas de las líneas de la apertura, todas las líneas de la apertura deben ser usadas como mínimo una vez en estos párrafos.
