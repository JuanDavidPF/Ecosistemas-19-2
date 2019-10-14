public class Enemigos { 

  private PVector posicion= new PVector();
  private PImage enemy;

  public Enemigos(PVector posicion) {
    enemy=loadImage("enemy.png");
    this.posicion=posicion;
  }


  public void pintar() {

    imageMode(CENTER);
    image(enemy, posicion.x, posicion.y, 40, 80);
  }
}