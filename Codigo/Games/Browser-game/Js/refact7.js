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
  
  var brickRowCount = 3;
  var brickColumnCount = 5;
  var brickWidth = 75;
  var brickHeight = 20;
  var brickPadding = 10;
  var brickOffsetTop = 30;
  var brickOffsetLeft = 30;  
  
  var bricks = [];
  
  
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
  
  function bricksLoop() {
    for(c=0; c<brickColumnCount; c++){
      bricks[c] = [];
      for(r=0; r<brickRowCount; r++) {
        bricks[c][r] = {x: 0, y: 0, status: 1 };
        if(bricks[c][r].status == 1) {          
          var brickX = (c*(brickWidth+brickPadding))+brickOffsetLeft;
          var brickY = (r*(brickHeight+brickPadding))+brickOffsetTop;
          bricks[c][r].x = brickX;
          bricks[c][r].y = brickY;
          ctx.beginPath();
          ctx.rect(brickX,brickY,brickWidth,brickHeight);
          ctx.fillStyle = "#0095DD";
          ctx.fill();
          ctx.closePath();
        }        
      }    
    }
    collisionDetection();
  }

  function canvasBounder() {
    var bounder = y + dy > canvas.height-ballRadius;
    var paddBounder = x > paddleX && x < paddleX + paddleWidth;
    
    if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
      dx = -dx;
    }
    if( y + dy < ballRadius) {
      dy = -dy;
    }
    else if(bounder) {
      if(paddBounder) {        
        dy = -dy;
      }    
      else {
        swal("Game Over", "Try again", "error");
        //document.location.reload();
      }
    }
  }
  
  // Another time it is iterating over a brick loop,
  // should be possible to merge again on bricksLoop().
  // That will produce a huge function, It must be a way to
  // hard refactor the whole function().
  function collisionDetection() {
    for(c=0; c<brickColumnCount; c++) {
      for(r=0; r<brickRowCount; r++) {
        var b = bricks[c][r];        
        if(b.status == 1) {
          if(x > b.x && x < b.x+brickWidth+ballRadius &&
             y > b.y && y < b.y+brickHeight+ballRadius) {
            dy = -dy;
            b.status = 0;
          }
        }        
      }
    }    
  }
  
  function draw() {
    ctx.clearRect(0,0,canvas.width, canvas.height);    
    
    bricksLoop();    
    drawBall();
    drawPaddle();
    
    
    // Fija limite de paleta respecto canvas !!
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