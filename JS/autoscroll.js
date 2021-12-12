var x = 1;
setInterval(function(){
    document.getElementById('btn' + x).checked = true;
    x++;
    if(x > 4){
        x = 1;
    }
},5000);