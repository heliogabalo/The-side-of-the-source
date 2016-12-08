var canvas = document.getElementById("myCanvas");
var lvlText = document.getElementById("test");
var ctx = canvas.getContext("2d");

  var gems = [
    {
      id: 1,
      name: 'Level-1',
      row: {
        r1: '*****',
        r2: '-***-',
        r3: '--*--'
        },
      canPushtoDb: true,
      hideLevel: false,
      status: 1
      //canvas
    },
    {
      id: 2,
      name: 'Level-2',
      row: {
        r1: '**-**',
        r2: '-*-*-',
        r3: '-***-',
        },
      canPushtoDb: true,
      hideLevel: false,
      status: 1
      //canvas
    },
    {
      id: 3,
      name: 'Level-3',
      row: {
        r1: '*-*-*',
        r2: '**-**',
        r3: '*-*-*'
        },
      canPushtoDb: true,
      hideLevel: true,
      status: 1
      //canvas
    }    
    
  ];


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
          if(score == brickRowCount*brickColumnCount+totalScore) {
              alert("- CONGRATULATIONS !! - Another lvl?");
              ctx.clearRect(0, 0, canvas.width, canvas.height);
              //level++           // moved to getLevel;
              getLevel();              
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
  ctx.fillText("Level: "+ level, canvas.width-150, 20);  
}

function getLevel() {
  level++;  
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

function activeLevel(){       // Data base Levels - Active Level!!
	var checkLevel; 					
	var levelArray = ['r1','r2','r3'];
	var stringLvl = [];	
  
  
  gems.forEach(function(value, i) {
    if(gems[i].id == level){
      checkLevel = gems[i].row;
    }
  });

  levelArray.forEach(function (value, i) {    
    stringLvl[i] = checkLevel[value].split(''); 
    });
  
  stringLvl.forEach(function(c, r) {    
    stringLvl[r].forEach(function(value, index) {      
      if(stringLvl[r][index] == "-") {        
        bricks[index][r].status = 0;
      }
      else {        
        bricks[index][r].status = 1;
      }
    });
  });  

  drawBricks();
  
}

function drawBricks() {                 // Draw bricks on Canvas
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

function draw() {                 // Main function, it must be Init()
  ctx.clearRect(0, 0, canvas.width, canvas.height);
	activeLevel();
  //drawBricks();
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


window.confirm("Press Ok to start!!");
draw();
//////////////////////////////////////////
/// Anoter elements called after Canvas //
//////////////////////////////////////////



lvlText.innerHTML = "ARKA-NO-ITS -v9.1" + arr + '<br />' +
'<em>' + "... continue the batle !! " + '</em>';
/* Intérvalo de refresco de dibujo



TODO:
    * Refactorizadion:
    * [*] Refactorizado espacio global accedido por 'función de página'.
    * [] Aislar array de bloques, Jason file.
    * [] Encapsular variables globales.
    * [] Crear función Init() - el Main!
    * [*] primer paso refactorización activeLevel().
    * [*] Cambio 'Alertas' por customAlerts gameOver y nextLevel.
    * [*] Merged drawBricks on bricksLoop() to avoid loop duplicity.
    * [*] Ball GPS (The axis for ball is embeded on canvas!!!(var x & y))
    * ****************************
    * Lógica:
    * [] Función init() - iniciar la página
    * [] Modificar canvas - ocupa toda la ventana/explorador!!.
    *    muestra en 31 dias JS - 
    *    --> http://creativejs.com/2013/05
    *     /make-a-shoot-em-up-in-20-minutes/index.html
    * [*] Crear marcador de nivel.
    * [] Identificar variables constantes.
    * []  Sustituir llamadas a varibles constantes por llaves del struct(gems!).
    * [*] Crear Loop de niveles "pasar pantalla, eliminados bloques".
    * [*] Función de nivel independiente. Ahora podemos dar o quitar niveles,
    *     en función del "Bonus" de bloque.
    * [*] Diccionario para el constructor de nivel.
    * [*]  Motor de nivel - datos externos desde array.
    * [*] Editor de nivel. -- Angular!!
    * [] Función subir a DB. -- Angular??
    * [] Formulario para el editor de nivel. -- Angular!!
    * [] Menú de partida, modal boxes - Angular!!    
    * [*] Colaiders bloques mejorados(added ballradius).
    * [*] Funcion canvasBounder() - Limites del canvas.
    * [] Cambio de ángulo de rebote(bola) respecto paleta.
    * [] Velocidad aumentada(acumul/temporal!!) con respecto rebote en bloque.
    * [] Velecidad alterada +/-Bonus de bloque.
    * [] Esquema de colores {bloques-Bonus}.
    * [] Mensaje alerta comenzar partida. Debe ser fuera de la función
    *    draw(), puede que con un switch con break; Podria ser cuando
    *    se dibujan los bloques y comprobando el status on/off.
    *    [*] Un confirm antes de dibujar?
    *    Tambien puedo dibujar un botón en medio de la pantalla vinculado a
    *    draw().
    * ******************************
    * Desarrollo gráfico:
    * [] I'd have a better dream if someone do that!
    * [] Necesarias tres imagenes de paleta, en tono gris con capa transparente.
    * [] Imagen nave para paleta.
    * [] Similar para la bola. Los bloques necesitan al menos dos imagenes.
    *   - Ancho normal y ancho reducido(mitad del normal).
*/


