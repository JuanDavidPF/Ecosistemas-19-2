package com.example.javaclient;


import java.io.IOException;

import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;


public class Comunicacion implements Runnable {

    private Socket s;
    private OutputStream salida;
    private boolean conectado;
    private InetAddress address;

    public Comunicacion() {

        conectado = false;

    }//cierra el constructor comunicacion

    public void enviar(final String mensaje) {
        if (conectado) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        byte[] buf = mensaje.getBytes();
                        salida.write(buf);
                        salida.flush();

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }//cierra el metodo enviar


    @Override
    public void run() {


        if (!conectado) {

            try {
                address = InetAddress.getByName("192.168.0.10");
                int port = 5000;
                s = new Socket(address, port);
                salida = s.getOutputStream();
                conectado = true;
            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}//cierra la clase comunicion
