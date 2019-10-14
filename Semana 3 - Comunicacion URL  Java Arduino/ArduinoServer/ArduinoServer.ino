
//importa las librerias necesarias
#include <SPI.h>
#include <Ethernet.h>

//define los pines de los potenciometros
int poten1 = A0;
int poten2 = A1;
int level1;
int level2;

//se introducen las direcciones mac y ip


byte mac[] = { 0x90, 0xA2, 0xDA, 0x11, 0x1C, 0x00 };
IPAddress ip{ 192, 168, 0, 177 };
EthernetServer puerto(80);

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  puerto.begin();

  //notifica la ubicacion del servidor
  Serial.print("El servidor está en ");
  Serial.println(Ethernet.localIP());
}

void loop() {

  //escucha a los navegadores o clientes
  EthernetClient cliente = puerto.available();


  if (cliente) {

    Serial.println("Nuevo cliente conectado");

    //Una solicitud http cuya linea esta en blanco
    bool mensajeVacio = true;
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        Serial.write(c);

        // Si la linea en la solicitud http esta en blanco y el cliente esta disponible se puede enviar una respuesta
        if (c == '\n' && mensajeVacio) {
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println("Connnection: close");
          cliente.println();
          cliente.println("<!DOCTYPE HTML>");
          cliente.println("<html>");
          // Agregar una etiqueta meta que recargue la pagina cada segundo
          cliente.println("<meta http-equiv=\"refresh\" content=\".01\">");
         

          //Obtener las lecturas del sensor e imprimir el resultado
          // La lectura de la temperatura o de la humedad tarda aproximadamente 250 milisegundos en el sensor
          level1 = analogRead(poten1);
          level2 = analogRead(poten2);

          //Escribimos en la página los valores de temperatura y humedad que hemos leído previamente
          cliente.print("Nivel 1: ");
          cliente.print(level1);
          cliente.print(", Nivel 2: ");
          cliente.println(level2);


          //Termina lectura del sensor
          cliente.println("</html>");
          break;
        }
        if (c == '\n') {
          //Linea en blanco
          mensajeVacio = true;
        }
        else if (c != '\r') {
          //Si hay un caracter en la linea en blanco
          mensajeVacio = false;
        }
      }
    }
    //Darle al navegador web tiempo para recibir los datos
    delay(1); //Tiene un retardo de 1000 ms = 1s para repetir el ciclo void loop.
    //Se cierra la conexion
    cliente.stop();
    Serial.println("La comunicación ha acabado");


  }//cierra la condición de que exista un cliente






}
