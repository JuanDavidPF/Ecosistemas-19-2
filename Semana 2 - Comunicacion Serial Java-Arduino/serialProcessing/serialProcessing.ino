import processing.serial.*;

Serial puerto;
int ledsVirtuales = 0;
int ledsReales=0;
int sliderNivel;
int sliderY, sliderX, sliderAncho, sliderAlto;
boolean sliderCogido = false;


void setup() {

  size(500, 500);

  sliderY=50;
  sliderX=150;
  sliderAncho=80;
  sliderAlto=40;

  puerto= new Serial(this, Serial.list()[1], 9600);

  puerto.bufferUntil('\n');
}



public void draw() {


  background(255);

  //leds virtuales
  strokeWeight(5);

  //leds encendidos
  for (int i = 0; i<4; i++) {
    fill(255, 50, 50);
    ellipse(350, i*120+70, 70, 70);
  }

  //leds apagados
  fill(80, 0, 0);
  for (int i = 0; i<ledsVirtuales/255; i++) {
    ellipse(350, i*120+70, 70, 70);
  }

  //slider

  strokeWeight(10);
  line(150, 50, 150, 450  );
  rectMode(CENTER);
  strokeWeight(2);
  rect(sliderX, sliderY, sliderAncho, sliderAlto);


  if (sliderCogido)sliderY=mouseY;
  //slider corrector
  if (sliderY<50) sliderY=50;
  if (sliderY>450) sliderY=450;

  sliderNivel=int(map(sliderY, 50, 450, 4, 0));
}

public void serialEvent(Serial p) {
  String potencia=p.readStringUntil(10);
  String ledsString=trim(potencia);
  ledsVirtuales=Integer.parseInt(ledsString);
  puerto.write(sliderNivel);
}


public void mousePressed() {

  if (mouseX>sliderX-sliderAncho && mouseX<sliderX+sliderAncho && mouseY>sliderY-sliderAlto&& mouseY<sliderY+sliderAlto) {

    sliderCogido=true;
  }
}

public void mouseReleased() {
  sliderCogido=false;
}