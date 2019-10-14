
String[] potenciometros;

public void setup() {
  size(700, 700);
}

public void draw() {
  background(0);
  //genera un string de la url y la asigna a variables
  potenciometros = loadStrings("http://192.168.0.177/");   
  potenciometros = potenciometros[3].split(",");
  potenciometros[0]=potenciometros[0].substring(9);
  potenciometros[1]=potenciometros[1].substring(10);  
  int nivel2= int(potenciometros[1]);
  int nivel1= int(potenciometros[0]);   

  nivel1=int(map(nivel1, 0, 1023, 0, 500));
  nivel2=int(map(nivel2, 0, 1023, 0, 500));

  //barras de nivel base
  textSize(30);
  fill(255);
  text("Potenciometro 1", 100, 140);
  text("Potenciometro 2", 100, 390);
  rect(100, 150, 500, 100);
  rect(100, 400, 500, 100);

  //barras de nivel variable
  fill(0, 255, 0);
  rect(100, 150, nivel1, 100);
  fill(255, 0, 0);
  rect(100, 400, nivel2, 100);
}