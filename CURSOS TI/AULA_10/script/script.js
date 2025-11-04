presence = 0
temperatura = 0
tempo = 0
function enviarDados(motor) {
    fetch(`/control/${motor}`)
}
function receberDados(sensor) {
    fetch(`/read/${sensor}`).then(response => response.json()).then(dados => {
        if(dados.error != '') {
            document.getElementById('error').innerHTML = dados.error
        } else {
            document.getElementById('temp').innerHTML = dados.temperatura
            document.getElementById('presence').innerHTML = dados.pir
            presence = dados.pir
            temperatura = dados.temperatura
        }
    })
}
async function control(sensor){
    await receberDados(sensor);
    tempo = presence == 1 ? tempo++ : tempo--; 
    if(presence == 1 && temperatura >= 28){
        enviarDados('l')
    } else {
        if(tempo == 0 && presence == 0) {
            enviarDados('d')
        }
    }

}