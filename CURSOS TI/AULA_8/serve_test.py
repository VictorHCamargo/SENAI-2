from flask  import Flask, render_template
app = Flask(__name__)
print(app)
@app.route('/')
def index():
    return render_template('index.html')
@app.route('/control/<led_num>/<action>')
def control(led_num,action):
    print("="*40)
    print("COMANDO RECEBIDO DO NAVEGADOR!")
    print(f"-Alvo: LED número {led_num}")
    print(f"-Ação: '{action}'")
    return f"Servidor de teste recebeu o comando: LED {led_num}, Ação '{action}'"
if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0',port=5000)