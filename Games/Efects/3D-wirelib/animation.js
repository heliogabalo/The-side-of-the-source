$(function() {
  var x = 0, y = 0, vx = 3, vy = 2, canvas, context;
  
  canvas = $("#canvas")[0];
  context = canvas.getContext("2d");

  //setInterval(draw, 1000/24);
  draw();
  
  function draw() {
    context.clearRect(0,0,500,500);
    context.beginPath();
    context.arc(x,y,20,0,Math.PI * 2, false);
    context.fill();
    x += vx;
    y += vy;
    setTimeout(draw, 1000/24);    
  }
});