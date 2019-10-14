package java_Server;

import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Observable;

public class Comunicacion extends Observable implements Runnable {

	private ServerSocket ss;
	private Socket s;
	private InputStream entrada;

	public Comunicacion() {

		try {

			ss = new ServerSocket(5000);
			s = ss.accept();
			entrada = s.getInputStream();

		} catch (IOException e) {
			e.printStackTrace();
		}

	}// cierra el constructor comunicación

	@Override
	public void run() {
		while (true) {
			try {
				String m = recibir();			
				setChanged();
				notifyObservers(m);
				
				clearChanged();
				Thread.sleep(1);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
	}// cierra el run

	public String recibir() throws IOException {
	
		byte[] buf = new byte[56];
		entrada.read(buf);	
		return new String(buf).trim();

	}// cierra el metodo recibir

}// cierra la clase comunicacion
