const btnLerMais = document.querySelector('.btnLerMais');
const texto = document.querySelector('.texto');

btnLerMais.addEventListener('click',(e)=>{
    texto.classList.toggle('mostrarMais');
    if(btnLerMais.innerText === 'Ler mais'){
        btnLerMais.innerText = 'Ler menos';
    } else{
        btnLerMais.innerText = 'Ler mais';
    }
})