$(function() {
  var canvas = $("#canvas")[0];
  context = canvas.getContext("2d");

  context.beginPath();
  context.moveTo(100,100);
  context.lineTo(200,200);
  context.stroke();

  context.beginPath();
  context.arc(250,100,40,0,Math.PI * 2,false);
  context.fillStyle = "#ff0000";
  context.fill();

  context.beginPath();
  context.arc(250,100,40,0,Math.PI * 2,false);

  context.strokeStyle = "#00ff00";
  context.lineWidth = 10;
  context.stroke();

  context.strokeStyle = "#000000";
  context.lineWidth = 1;
  context.stroke();
});
