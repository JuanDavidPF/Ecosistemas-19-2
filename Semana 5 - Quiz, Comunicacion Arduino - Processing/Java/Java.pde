import processing.serial.*;

int x, y, tamano;
int led1, led2, led3, led4;

Serial puerto;
boolean cogida;

void setup() {

  size(600, 600);
  puerto= new Serial(this, Serial.list()[0], 9600 );
  x=width/2;
  y=height/2;
  tamano=100;
}


void draw() {

  background(255);
  strokeWeight(5 );
  fill( 255);
  rect(0, 0, width/2, height/2);
  text("1", 255, 255);
  rect(width/2, 0, width/2, height/2);
  rect(0, height/2, width/2, height/2);
  rect(width/2, height/2, width/2, height/2);

  fill(0);

  textAlign(CENTER);
  textSize(50);
  text("1", 150, 150);
  text("2", 450, 150);
  text("3", 150, 450);
  text("4", 450, 450);
  fill(0, 0, 255);

  ellipse(x, y, tamano, tamano);



  if (cogida) {

    x=mouseX;
    y=mouseY;
  }


  if (x<0+tamano/2)x=tamano/2;
  if (x>width-tamano/2)x=width-tamano/2;
  if (y<0+tamano/2)y=tamano/2;
  if (y>height-tamano/2) y=height-tamano/2;



  //evaluar area sensible

  //area sensible1
  if (x>0-tamano/2 && x<width/2+tamano/2&& y<height/2+tamano/2) {
    led1=1;
  } else led1=0;

  //area sensible2
  if (x>width/2-tamano/2 && x<width+tamano/2&& y<height/2+tamano/2) {
    led2=1;
  } else led2=0;

  //area sensible3
  if (x>0-tamano/2 && x<width/2+tamano/2&& y>height/2-tamano/2) {
    led3=1;
  } else led3=0;

  //area sensible4
  if (x>width/2-tamano/2 && x<width+tamano/2&& y>height/2-tamano/2) {
    led4=1;
  } else led4=0;



  //paso de datos

  puerto.write(led1+""+led2+""+led3+""+led4+"\n");
  println(led1+""+led2+""+led3+""+led4+"\n");
}


void mousePressed() {

  if (dist(mouseX, mouseY, x, y)<tamano/2 ) {
    cogida=true;
  }
}

void mouseReleased() {
  cogida=false;
}
