window.game = (function() {
  return {
    canvasElement: '#myCanvas',   // log: console.log("");    
    testId: '#test',               // this element isn't showed    
    ctx: "2d",
    x: canvas.width/2,
    y: canvas.height-30,
    ballRadius: 10,
    dx: 2,
    dy: -2,
    paddleHeight: 10,
    paddleWidth: 75,
    paddleX: (canvas.width-paddleWidth)/2,
    rightPressed: false,
    leftPressed: false,
    
    init: function(options) {
    this.canvas = document.getElementById(options.canvasElement);
    this.test = document.getElementById(options.testId);
    this.ctx = canvas.getContext(options.ctx);
    this.bindEvents();
    },
    
    keyDownHandler: function(e){
      if(e.keyCode === 39) {
        window.game.rightPressed = true;
      }
      else if(e,keyCode === 37) {
        window.game.leftPressed = true;
      }
    },
    
    keyUpHandler: function(){
      if(e.keyCode === 39) {
        window.game.rightPressed = false;
      }
      else if(e,keyCode === 37) {
        window.game.leftPressed = false;
      }
      },
  
    bindEvents: function() {
    document.addEventListener("keydown", this.keyDownHandler, false);
    document.addEventListener("keyup", this.keyUpHnadler, false);
    },
    
    drawBall: function(){
      // The ball
      this.ctx.beginPath();
      this.ctx.arc(x,y,ballRadius,0, Math.PI*2, false);
      this.ctx.fillStyle = "#0095DD";
      this.ctx.fill();
      this.ctx.closePath();  //end draw
    },
    
    drawPaddle: function() { //needed this for all vars? ejem this.paddleX
      this.ctx.beginPath();
      this.ctx.rect(paddleX, canvas.height-paddleHeight, paddleWidth, paddleHeight);
      this.ctx.fillStyle = "#0095DD";
      this.ctx.fill();
      this.ctx.closePath();
    },
    
    canvasBounder: function() {
      // canvas ball bounder
      if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
        dx = -dx;
      }
      if(y + dy > canvas.height-ballRadius || y + dy < ballRadius) {
        dy = -dy;
      }
    },
    
    draw: function() {
      init.ctx.clearRect(0,0,this.canvas.width, this.canvas.height);
      
      this.drawBall();
      this.drawPaddle();      
      
      if(this.rightPressed && this.paddleX < this.canvas.width - this.paddleWidth) {
        this.paddleX += 7;
      }
      else if(this.leftPressed && this.paddleX) {
        this.paddleX -= 7;
      }
      
      this.x += dx;
      this.y += dy;
      this.canvasBounder();
      
    }    
  };  
  
  
})();