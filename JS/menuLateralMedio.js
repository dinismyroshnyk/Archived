let menu = document.querySelector(".menu");
let menu_lateral = document.querySelector(".menu_lateral");

menu.onclick = function(){
    menu_lateral.classList.toggle("active");
}
