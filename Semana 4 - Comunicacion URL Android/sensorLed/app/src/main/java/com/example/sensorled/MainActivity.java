package com.example.sensorled;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.Button;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class MainActivity extends AppCompatActivity {

    private Button btn_red, btn_green, btn_blue;
    private int red, green, blue;
    private URL generadorColor;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn_red = findViewById(R.id.btn_red);
        btn_green = findViewById(R.id.btn_green);
        btn_blue = findViewById(R.id.btn_blue);

        red = 0;
        green = 0;
        blue = 0;


        Sensor hiloSensor = new Sensor();
        hiloSensor.start();

    }

    public class Sensor extends Thread {

        public void run() {

            try {
                while (true) {

                    //referencia el link
                    URL url = new URL("https://www.darkart.com/cgi-bin/colors.cgi");

                    //abre la conexion con la url
                    HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

                    //recibe lo que envia la conexion
                    InputStream is = urlConnection.getInputStream();

                    //lee y almacena lo que se envío
                    BufferedReader br = new BufferedReader(new InputStreamReader(is));


                    StringBuilder sb = new StringBuilder();
                    String valores;


                    while ((valores = br.readLine()) != null) {
                        sb.append(valores);
                    }

                    String doc = sb.toString();
                    String docNoHtml = doc.replaceAll("\\<.*?>", "");
                    String rango = docNoHtml.substring(37, docNoHtml.length() - 47);
                    String[] numeros = rango.split(",");
                    red = Integer.parseInt(numeros[0]);
                    green = Integer.parseInt(numeros[1]);
                    blue = Integer.parseInt(numeros[2]);

                    btn_red.setText(red + "");

                    if (red < 100) {
                        btn_red.setTextColor(Color.WHITE);
                    } else btn_red.setTextColor(Color.BLACK);

                    btn_red.setBackgroundColor(Color.rgb(red, 0, 0));

                    btn_green.setText(green + "");

                    if (green < 100) {
                        btn_green.setTextColor(Color.WHITE);
                    } else btn_green.setTextColor(Color.BLACK);

                    btn_green.setBackgroundColor(Color.rgb(0, green, 0));

                    btn_blue.setText(blue + "");

                    if (blue < 200) {
                        btn_blue.setTextColor(Color.WHITE);
                    } else btn_blue.setTextColor(Color.BLACK);

                    btn_blue.setBackgroundColor(Color.rgb(0, 0, blue));


                    Thread.sleep(5000);
                }

            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }


        }//cierra el run
    }//cierra la clase Sensores
}//cierra main Activity
