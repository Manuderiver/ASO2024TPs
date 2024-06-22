#!/bin/bash
echo "-- BIENVENIDOS A LA CALCULADORA DEL TP5 --"

while true; 
do
    echo "Por favor digite un numero, la operacion y luego el siguiente numero"
    read -p "Ingrese el primer numero: " numero1

    echo "Que operacion desea realizar?"
    echo "[ + ]||[ - ]"
    echo "[ * ]||[ / ]"
    read -p "Ingrese la operacion: " opcion

    read -p "Ahora ingrese el segundo numero: " numero2

    case $opcion in
        +)
            echo "RESULTADO--> $(( numero1 + numero2 ))"
        ;;
        -)
            echo "RESULTADO--> $(( numero1 - numero2 ))"
        ;;
        \*)
            echo "RESULTADO--> $(( numero1 * numero2 ))"
        ;;
        /)
            if [ $numero2 -ne 0 ]; 
                then
                    echo "RESULTADO--> $(( numero1 / numero2 ))"
                else
                    echo "ERROR: La division por cero no es permitida"
            fi
        ;;
        *)
            echo "Operacion invalida"
        ;;
    esac

    read -p "Quiere realizar otra operacion? (s/n): " opcion
    if [[ $opcion != "s" && $opcion != "S" ]]; 
        then
            echo "Saliste de la calculadora virtual."
        break
    fi
done