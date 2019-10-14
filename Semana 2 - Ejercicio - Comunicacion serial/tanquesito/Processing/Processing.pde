import processing.serial.*;

Serial puerto;


float r= 0;
float disparo;
int mapaX, mapaY;
int ancho= 90;
int alto=100;
int capacidad=3;
PVector posicion;
PVector direccion;
PVector velocidad = new PVector(200, 200);
float aceleracion;
PImage tank;
PImage mapa;
ArrayList<Balas> balas = new ArrayList<Balas>();
ArrayList<Enemigos> enemigos = new ArrayList<Enemigos>();
int feedback=0;


void setup() {

  size(500, 500);


  mapa= loadImage("mapa.png");
  mapaX=-500;
  mapaY=-200;
  tank= loadImage("tank.png" );

  puerto= new Serial(this, Serial.list()[1], 9600 );
  puerto.bufferUntil(10);
}


void draw() {


  background(255);
  imageMode(CORNER);
  image(mapa, mapaX, mapaY, 1200, 700);




  //movimiento del tank
  pushMatrix();


  direccion=new PVector(cos(r), sin(r));
  direccion=PVector.mult(direccion, aceleracion/500);
  velocidad.x+=direccion.x;
  velocidad.y+=direccion.y;
  posicion=  PVector.add(velocidad, direccion);

  translate(posicion.x, posicion.y);

  rotate(r) ;
  imageMode(CENTER);
  image(tank, 0, 0, ancho, alto );


  popMatrix();

  //disparos

  if (capacidad>0 ) {
    if (disparo==1 ) {

      balas.add(new Balas(posicion, r));
      capacidad-=1;
      disparo=0;
    }
  }

  //recarga

  if (frameCount%180==0 && capacidad<3)capacidad+=1;

  for (int i= 0; i<balas.size(); i++) {
    Balas bala= balas.get(i);
    bala.pintar();
  }

  //pintar enemigos

  //crearlos

  if (frameCount%1000==0) {
    PVector enePos = new PVector (random(0, 500  ), random(0, 500   ));
    enemigos.add(new Enemigos(enePos));
  }

  for (int i= 0; i<enemigos.size(); i++) {
    Enemigos malo= enemigos.get(i);
    malo.pintar();
  }

  //matarlos
  for (int i= 0; i<enemigos.size(); i++) {
    for (int j= 0; j<balas.size(); j++) {
      Enemigos malo=  enemigos.get(i);
      Balas bala=  balas.get(j);

      if (dist(malo.posicion.x, malo.posicion.y, bala.posicion.x, bala.posicion.y)<40  ) {
        enemigos.remove(i);
        balas.remove(j);
      }
    }
  }

  //feecdback

  if (capacidad>0)feedback=1;
  if (capacidad==0)feedback=0;

  //movimiento del mapas


  if (mapaX<-670) mapaX=-670;
  if (mapaX>0) mapaX=0;
  if (mapaY>0) mapaY=0;
  if (mapaY<-200)mapaY=-200;

  if (mapaX<=0 && mapaX>=-670 && mapaY<=0 && mapaY>=-200) {

    if (velocidad.x<100 && direccion.x<0) {
      mapaX-=direccion.x;
      velocidad.x=100;

      for (int i= 0; i<enemigos.size(); i++) {
        enemigos.get(i).posicion.x-=direccion.x;
      }
    }

    if (velocidad.x>400 && direccion.x>0) {
      mapaX-=direccion.x;
      velocidad.x=400;
      for (int i= 0; i<enemigos.size(); i++) {
        enemigos.get(i).posicion.x-=direccion.x;
      }
    }

    if (velocidad.y>400 && direccion.y>0) {
      mapaY-=direccion.y;
      velocidad.y=400;
      for (int i= 0; i<enemigos.size(); i++) {
        enemigos.get(i).posicion.y-=direccion.y;
      }
    }

    if (velocidad.y<100 && direccion.y<0) {
      mapaY-=direccion.y;
      velocidad.y=100;
      for (int i= 0; i<enemigos.size(); i++) {
        enemigos.get(i).posicion.y-=direccion.y;
      }
    }
  }

  //hud

  fill(0, 0, 0, 180);
  rect(350, 0, 150, 70);
  textSize(20);
  fill(255);
  text("AMMO", 370, 20);

  fill(255, 0, 0);
  for (int i = 0; i<capacidad; i++) {
    ellipse(i*40+390, 50, 25, 25  );
  }
}

void serialEvent(Serial puerto) {
  String coordenadas = puerto.readString();
  String[] posiciones = split(coordenadas, ',');
  float[] axis = float(posiciones);
  aceleracion = axis[0]; 
  r= axis[1];
  r=map(r, 0, 1023, 0, TWO_PI);
  disparo=axis[2];  
  puerto.write(feedback);
}