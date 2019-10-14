package java_Server;

import java.util.Observable;
import java.util.Observer;

import processing.core.PApplet;

public class Main extends PApplet implements Observer {

	public static void main(String[] args) {
		PApplet.main("java_Server.Main");
	}// cierra el constructor Main

	@Override
	public void settings() {
		size(1000, 600);
	}// cierra el metodo settings

	private Comunicacion com;
	private float x, y, tam;
	private int r, g, b;

	@Override
	public void setup() {

		x = width / 2;
		y = height / 2;
		tam = 100;

		r = (int) random(80, 220);
		g = (int) random(80, 220);
		b = (int) random(80, 220);

		com = new Comunicacion();
		new Thread(com).start();
		com.addObserver(this);
	}// cierra el metodo setup

	@Override
	public void draw() {
		background(0);
		fill(r, g, b);
		ellipse(x, y, tam, tam);
	}// cierra el metodo draw

	@Override
	public void update(Observable o, Object arg) {
		if (arg instanceof String) {

			String mensaje = arg.toString();

			if (mensaje.contains(",")) {

				String[] coordenadas = mensaje.split(",");
				String direccion = coordenadas[1];
				switch (direccion) {

				case "up":
					y -= 10;
					break;

				case "down":
					y += 10;
					break;

				case "left":
					x -= 10;
					break;

				case "right":
					x += 10;
					break;

				}// cierra el switch de la direccion

			} else if (mensaje.contains("color")) {

				nuevoColor();
			}

		}
	}// cierra el metodo update

	private String nuevoColor() {
		r = (int) random(80, 220);
		g = (int) random(80, 220);
		b = (int) random(80, 220);
		String color = r + "," + g + "," + b;
		return color;

	}// cierra el metodo nuevo color

}// cierra la clase main
