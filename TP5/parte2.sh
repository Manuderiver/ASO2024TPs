apiKEY="2aa68ad99f2648c9906160348242106"

read -p "Ingrese una ciudad para saber su clima actual: " ciudad_ini
ciudad_ingresada=$(echo $ciudad_ini | tr ' ' '%20') # Cambiamos espacios a %20 para que nos funcione bien la URL

url="http://api.weatherapi.com/v1/current.json?key=$apiKEY&q=$ciudad_ingresada&aqi=no"

curl --request GET "$url" > respuesta.json

# Cambiamos los %20 de vuelta a espacios para mostrar en consola
ciudad_ingresada=$(echo $ciudad_ini | tr '%20' ' ')

# Conseguimos la temperatura de la respuesta JSON
clima=$(jq -r '.current.temp_c' respuesta.json)

# Y le mostramos el clima que buscaba el usuario
echo "El clima actual de $ciudad_ingresada es: $clima°C"