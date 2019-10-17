package Java.Server;

import processing.core.PApplet;

public class Main extends PApplet {

	public static void main(String[] args) {

		PApplet.main("Java.Server.Main");
	}

	private Logica log;

	public void settings() {
		size(700, 700);
	}

	public void setup() {
		frameRate(60);
		log = new Logica(this);

	}

	public void draw() {

	}

	public void mouseClicked() {

	}

	public void keyPressed() {

	}

	public void keyReleased() {

	}

}
