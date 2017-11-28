// refatorizado paso 3, paso 4 intacto.
// 

 (function() {
  
  var canvas = document.getElementById("myCanvas");
  var test = document.getElementById("test");
  var ctx = canvas.getContext("2d");
  
  var x = canvas.width/2, y = canvas.height-30;  
  var ballRadius = 10;  
  
  var dx = 2, dy = -2;  
  
  var paddleHeight = 10;
  var paddleWidth = 75;
  var paddleX = (canvas.width-paddleWidth)/2;
  var rightPressed = false;
  var leftPressed = false;
  
  
  document.addEventListener("keydown", keyDownHandler, false);
  document.addEventListener("keyup", keyUpHandler, false);
  
  function keyDownHandler(e) {
    if(e.keyCode === 39) {
      rightPressed = true;
    }
    else if(e.keyCode === 37) {
      leftPressed = true;
    }
  }
  
  function keyUpHandler(e) {
    if(e.keyCode === 39) {
      rightPressed = false;
    }
    else if(e.keyCode === 37) {
      leftPressed = false;
    }
  }
  
  function drawBall() {
    // The ball
    ctx.beginPath();
    ctx.arc(x,y,ballRadius,0, Math.PI*2, false);
    ctx.fillStyle = "#0095DD";
    ctx.fill();
    ctx.closePath();  //end draw
  }
  
  function drawPaddle() {
    ctx.beginPath();
    ctx.rect(paddleX, canvas.height-paddleHeight, paddleWidth, paddleHeight);
    ctx.fillStyle = "#0095DD";
    ctx.fill();
    ctx.closePath();
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
    drawPaddle();
    
    if(rightPressed && paddleX < canvas.width-paddleWidth) {
      paddleX += 7;
    }
    
    else if(leftPressed && paddleX > 0) {
      paddleX -= 7;
    }
    
    x += dx;
    y += dy;    
    canvasBounder();             // check bounds after each frame draw.
    
  }
  
  
  setInterval(draw, 10);
  
  test.innerHTML = "ARKA-NO-ITS v0.01"; 
  
  
  })();