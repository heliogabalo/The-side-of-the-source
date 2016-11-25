

var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");

var x = canvas.width/2;
var y = canvas.height-30;

var dx = 2;
var dy = -2;

var ballRadius = 10;

var paddleHeight = 10;
var paddleWidth = 75;
var paddleX= (canvas.width-paddleWidth)/2;
var rightPressed = false;
var leftPressed = false;

var brickRowCount = 3;
var brickColumnCount = 5;
var brickWidth = 75;
var brickHeight = 20;
var brickPadding = 10;
var brickOffsetTop = 30;
var brickOffsetLeft = 30;

var score = 0;
var lives = 3;

var level = 1;
var totalScore = 0;

var bricks = [];


for(c=0; c<brickColumnCount; c++) {
    bricks[c] = [];
    for(r=0; r<brickRowCount; r++) {
        bricks[c][r] = { x: 0, y: 0, status: 1 };
    }
}

document.addEventListener('keydown', keyDownHandler, false);
document.addEventListener('keyup', keyUpHandler, false);
document.addEventListener('mousemove', mouseMoveHandler, false);

function keyDownHandler(e) {
  if(e.keyCode == 39) {
    rightPressed = true;
  }
  else if(e.keyCode == 37) {
  leftPressed = true;
  }
}

function keyUpHandler(e) {
  if(e.keyCode == 39) {
    rightPressed = false;
  }
  else if(e.keyCode == 37) {
  leftPressed = false;
  }
}


function mouseMoveHandler(e){
  var relativeX = e.clientX - canvas.offsetLeft;
  if(relativeX > 0 && relativeX < canvas.width) {
    paddleX = relativeX - paddleWidth/2;
  }
}


function drawLives() {
  ctx.font = "16px Arial";
  ctx.fillStyle = "#0095DD";
  ctx.fillText("Lives: "+lives, canvas.width-65, 20);
}

function checkStatus() {
  for(c=0; c<brickColumnCount; c++) {
    for(r=0; r<brickRowCount; r++) {
      bricks[c][r].status = 1;
    }
  }
}

function collisionDetection() {
  for(c=0; c<brickColumnCount; c++){
    for(r=0; r<brickRowCount; r++) {
      var b = bricks[c][r];
      if(b.status == 1) {
        if(x > b.x && x < b.x+brickWidth && y > b.y && y < b.y+brickHeight) {
          dy = -dy;
          b.status = 0;
          score++;
          if(score == brickRowCount*brickColumnCount) {
            alert("YOU WIN, Congratulations!");            
            //document.location.reload();
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            totalScore = score; 
            level++;
            checkStatus();
            drawBricks();            
          }
          else if(score == brickRowCount*brickColumnCount+totalScore) {
              alert("Another lvl?");
              ctx.clearRect(0, 0, canvas.width, canvas.height);
              level++;
              totalScore = score;
              checkStatus();
              drawBricks();              
          }
        }
      }
    }
  }
}


function drawScore() {
  ctx.font = "16px Arial";
  ctx.fillStyle = "#0095DD";
  ctx.fillText("Score: "+score, 8, 20);
}

function drawLevel() {
  ctx.font = "16px Arial";
  ctx.fillStyle = "#0095DD";
  ctx.fillText("Level: "+level, canvas.width-150, 20);
}

function drawBall() {

  ctx.beginPath();
  ctx.arc(x, y, ballRadius, 0, Math.PI*2);
  ctx.fillStyle = "#0095DD";
  ctx.fill();
  ctx.closePath();
}


function drawPaddle() {
  ctx.beginPath();
  ctx.rect(paddleX, canvas.height-paddleHeight, paddleWidth, paddleHeight);
  ctx.fillStyle = "#0095DD";
  ctx.fill();
  ctx.closePath();
}


function drawBricks() {
  for(c=0; c<brickColumnCount; c++) {
    for (r=0; r<brickRowCount; r++) {
      if(bricks[c][r].status == 1) {
        var brickX = (c*(brickWidth+brickPadding))+brickOffsetLeft;
        var brickY = (r*(brickHeight+brickPadding))+brickOffsetTop;
        bricks[c][r].x = brickX;
        bricks[c][r].y = brickY;
        ctx.beginPath();
        ctx.rect(brickX, brickY, brickWidth, brickHeight);
        ctx.fillStyle = "#0095DD";
        ctx.fill();
        ctx.closePath();
      }
    }
  }
}


function draw() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  drawBricks();
  drawBall();
  drawPaddle();
  drawScore();
  drawLives();
  drawLevel();
  collisionDetection();

  if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
      dx = -dx;
  }
  
  if(y + dy < ballRadius) {
      dy = -dy;
  }
  else if (y + dy > canvas.height-ballRadius) {
    if(x > paddleX && x < paddleX + paddleWidth) {
      dy = -dy;
    }
    else {
      lives--;
      if(!lives) {
      alert("Game Over");
      document.location.reload();
      }
      else {
      x= canvas.width/2;
      y = canvas.height-30;
      dx = 2;
      dy = -2;
      paddleX = (canvas.width-paddleWidth)/2;
      }
    }
  }

  if(rightPressed && paddleX < canvas.width-paddleWidth) {
      paddleX += 7;
  }
  else if(leftPressed && paddleX > 0) {
      paddleX -= 7;
  }

  x += dx;
  y += dy;
  requestAnimationFrame(draw);
}


draw();

/* Intérvalo de refresco de dibujo

setInterval(draw, 10);
*/

/* Color aleatorio
function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++ ) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}
var randColor = '#'+(Math.random()*0xFFFFFF<<0).toString(16);
*/
