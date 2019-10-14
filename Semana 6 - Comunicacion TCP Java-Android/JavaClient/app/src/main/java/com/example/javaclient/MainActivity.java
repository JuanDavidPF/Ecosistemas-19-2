package com.example.javaclient;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.util.Observable;
import java.util.Observer;

public class MainActivity extends AppCompatActivity {


    private Comunicacion com;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        com = new Comunicacion();
        new Thread(com).start();
    }


    public void up(View view) {
        String mensaje;
        mensaje = "direccion,up";
        com.enviar(mensaje);
        Toast.makeText(getApplicationContext(), mensaje, Toast.LENGTH_LONG).show();

    }

    public void down(View view) {
        String mensaje;
        mensaje = "direccion,down";
        com.enviar(mensaje);
        Toast.makeText(getApplicationContext(), mensaje, Toast.LENGTH_LONG).show();

    }

    public void left(View view) {
        String mensaje;
        mensaje = "direccion,left";
        com.enviar(mensaje);
        Toast.makeText(getApplicationContext(), mensaje, Toast.LENGTH_LONG).show();

    }

    public void right(View view) {
        String mensaje;
        mensaje = "direccion,right";
        com.enviar(mensaje);
        Toast.makeText(getApplicationContext(), mensaje, Toast.LENGTH_LONG).show();

    }

    public void change(View view) {
        String mensaje;
        mensaje = "color";
        com.enviar(mensaje);
        Toast.makeText(getApplicationContext(), mensaje, Toast.LENGTH_LONG).show();

    }

}
