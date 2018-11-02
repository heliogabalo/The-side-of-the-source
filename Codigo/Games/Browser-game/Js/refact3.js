 (function() {
  
  var canvas = document.getElementById("myCanvas");
  var test = document.getElementById("test");
  var ctx = canvas.getContext("2d");
  
  var x = canvas.width/2, y = canvas.height-30;  
  var ballRadius = 10;  
  
  var dx = 2, dy = -2;  
  
  function drawBall() {
    // The ball
    ctx.beginPath();
    ctx.arc(x,y,ballRadius,0, Math.PI*2, false);
    ctx.fillStyle = "#0095DD";
    ctx.fill();
    ctx.closePath();  //end draw
  }

  function canvasBounder() {
    // canvas ball bounder
    if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
      dx = -dx;
    }
    if(y + dy > canvas.height-ballRadius || y + dy < ballRadius) {
      dy = -dy;
    }    
  }
  
  
  function draw() {
    ctx.clearRect(0,0,canvas.width, canvas.height);
    
    drawBall();    
    
    x += dx;
    y += dy;    
    canvasBounder();             // check bounds after each frame draw.
    
  }
  
  
  setInterval(draw, 10);
  
  test.innerHTML = "ARKA-NO-ITS v0.01"; 
  
  
  })();