public class Balas { 

  private PVector direccion = new PVector();
  private PVector posicion = new PVector();
  private float angulo;
  private int tamano = 25;
  private int velocidadBala=15;

  public Balas(PVector posicion, float angulo) {
    this.angulo=angulo;
    direccion=new PVector(cos(this.angulo), sin(this.angulo));
    this.posicion=posicion;
    direccion=PVector.mult(direccion, velocidadBala);
  }

  public void pintar() {
    fill(255, 255, 0);
    ellipse(posicion.x, posicion.y, tamano, tamano);

    posicion= PVector.add(posicion, direccion);
   
  }
}