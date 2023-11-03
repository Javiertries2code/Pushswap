#!/bin/bash
# Este es un script para compilar y ejecutar un programa C con argumentos

# Nombre del programa de salida
OUTPUT_PROGRAM="push"

# Lista de archivos fuente
SOURCE_FILES=("push.c" "pa.c" "pb.c" "ra.c" "rb.c" "rr.c" "rra.c" "rrb.c" "rrr.c" "sa_sb.c" "handlers.c" "ss.c")


# Opciones de compilación
CFLAGS="-Wall -Wextra -Werror"

# Compilación
gcc $CFLAGS -o $OUTPUT_PROGRAM "${SOURCE_FILES[@]}"

# Verifica si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutando el programa..."

    # Argumentos que se pasarán al programa compilado
    PROGRAM_ARGS="$@"

    ./${OUTPUT_PROGRAM} $PROGRAM_ARGS  # Ejecuta el programa con argumentos
else
    echo "Error de compilación. No se pudo ejecutar el programa."
fi

