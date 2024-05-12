double valor = 3.14159; // Tu valor double
String num; // Variable para almacenar el valor convertido

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read(); // Lee el carácter recibido por el puerto serie
    if (incomingChar == '1') {
      // Convierte el valor double a una cadena de caracteres y lo asigna a la variable num
      num = printDouble(valor, 4); // 4 indica el número de decimales
      Serial.println(num); // Imprime el valor almacenado en la variable num
    }
  }
}

// Función para convertir un valor double a una cadena de caracteres con una cantidad específica de decimales
String printDouble(double val, unsigned int precision) {
  String result; // Variable para almacenar el valor convertido
  
  // Parte entera del valor double
  result += (int)val;
  
  // Parte decimal del valor double
  if(precision > 0) {
    result += "."; // Punto decimal
    
    unsigned long frac;
    unsigned long mult = 1;
    byte padding = precision - 1;
    while(precision--) mult *= 10;
    
    if(val >= 0) frac = (val - int(val)) * mult;
    else frac = (int(val) - val ) * mult;
    
    unsigned long frac1 = frac;
    
    while(frac1 /= 10) padding--;
    while(padding--) result += "0";
    
    result += frac;
  }
  
  return result; // Devuelve la cadena de caracteres resultante
}
