from flask import Flask, render_template
import serial
import time

try:
    arduino = serial.Serial('COM4',9600,timeout=1);
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

app = Flask(__name__)

@app.route('/')
def index():
    return render_template("index.html")
@app.route("/control/<sensor>/<motor>")
def control(sensor,motor):
    if arduino:
        command = ''
        if sensor == '1':
            command = '1'
        if sensor == '2':
            command ='2'
        if motor == 'l' | motor == 'L':
            command = 'l'
        if motor == 'd' | motor == 'D':
            command = 'd'
        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' efetuado"
        else:
            return "Comando inválido"
    else:
        return "Arduino não conectado"
if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0',port=5000,use_reloader=False)