from flask import Flask, render_template
import serial
import time

try:
    arduino = serial.Serial('COM3',9600,timeout=1);
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None
app = Flask(__name__,template_folder="AULA_8")

@app.route('/')
def index():
    return render_template("index.html")
@app.route("/control/<led_num>/<action>")
def control(led_num,action):
    if arduino:
        command = ''
        if led_num == '2':
            command = 'y' if action == 'on' else 'n'
        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' enviado para o LED {led_num}"
        else:
            return "Comando inválido"
    else:
        return "Arduino não conectado"
if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0',port=5000,use_reloader=False)