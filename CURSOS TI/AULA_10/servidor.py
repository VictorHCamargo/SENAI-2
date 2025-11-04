from flask import Flask, render_template, jsonify
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
@app.route("/control/<motor>")
def control(motor):
    if arduino:
        command = ''
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
@app.route("/read/<sensor>")
def buscarDados(sensor):
    if arduino:
        try:
            if sensor == '1':
                command = '1'
            if sensor == '2':
                command ='2'
            arduino.write(command.encode())
            time.sleep(0.1)
            dados = arduino.readline().decode('utf-8').strip()
            if dados and dados != -1 and ";" in dados:
                temperatura, pir = dados.split(';')
                return jsonify(temperatura=float(temperatura),pir=int(pir))
            else:
                return jsonify(error="Falha ao ler o sensor"), 500
        except Exception as e:
            print(f"Erro na leitura serial: {e}")
            return jsonify(error="Erro serial"),500
    else:
        return jsonify(error="Arduino não conectado"),500
if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0',port=5000,use_reloader=False)
