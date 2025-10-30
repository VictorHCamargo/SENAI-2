from flask import Flask, render_template, jsonify
import serial
import time

try:
    arduino = serial.Serial('COM4',9600,timeout=1);
    time.sleep(2)
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

# substituir o nome da pasta no lugar do template_folder, para selecionar a pasta que deseja funcionar que contenha um index
app = Flask(__name__,template_folder="sensor_temp")

@app.route('/')
def index():
    return render_template("index.html")
@app.route("/control/<botao>/<pasta>")
def control(botao,pasta):
    if arduino:
        command = ''
        if pasta == 'semaforo':
            if botao == 'H':
                command = 'H'
            else:
                command = 'L'
        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' efetuado"
        else:
            return "Comando inválido"
    else:
        return "Arduino não conectado"
@app.route("/get_data")
def buscarDadosSensor():
    if arduino:
        try:
            arduino.write(b'P') # Envia o comando 'P' para pedir os dados
            time.sleep(0.1) # Dá um tempo para o Arduino responder
            
            data_line = arduino.readline().decode('utf-8').strip()
            
            if data_line and data_line != "ERRO" and ";" in data_line:
                # Separa os valores "temp;umid"
                temperatura, umidade = data_line.split(';')
                return jsonify(temperatura=float(temperatura), umidade=float(umidade))
            else:
                return jsonify(error="Falha ao ler sensor"), 500

        except Exception as e:
            print(f"Erro na leitura serial: {e}")
            return jsonify(error="Erro serial"), 500
            
    return jsonify(error="Arduino nao conectado"), 500
if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0',port=5000,use_reloader=False)