/**
 * Create Dom elements and get your game on
 */

function initialize() {
  // star by measuring the viewport
  onWindowResize();

  // create a canvas for the firewoks
  mainCanvas = document.createElement('canvas');
  mainContext = mainCanvas.getContext('2d');

  // and another one for, like, an off screen buffer
  // because that's rad n all
  fireworkCanvas = document.createElement('canvas');
  fireworkContext = fireworkCanvas.getContext('2d');

  //set up the colours for the fireworks
  createFireworkPalette(12);

  //set up the dmensions on the canvas
  setMainCanvasDimensions();

  // add the canvas in
  document.body.appendChild(mainCanvas);
  document.addEventListener('mouseup', createFirefowk, true);
  document.addEventlistener('touchend', createFirefowk, true);

  // and now we set off
  update();
}


/**
  * Creates a block of colours for the
  * fireworks to use as their colourin
  */
  function createFireworkPalette(gridSize) {
    var size = gridSize * 10;
    fireworkCanvas.width = size;
    fireworkCanvas.height = size;
    fireworkContext.globalCompositeOperation = 'source-over';

    // create 100 blocks which cycle through
    // the rainbow... HSL us teh r0xx0rz
    for(var c = 0; c < 100; c++) {
      var marker = (c * gridSize);
      var gridX = marker % size;
      var gridY = Math.floor(marker / size) * gridSize;

      fireworkContext.fillStyle = "hsl(" + Math.round(c * 3.6) + " ,100%, 60%)";
      fireworkContext.fillRect(gridX, gridY, gridSize, gridSize);
      fireworkContext.drawImage(
        Library.bigGlow,
        gridX,
        gridY);
    }
  }


/**
  * The main loop where everything happens
  */
function update() {
  clearContext();
  requestAnimFrame(update);
  drawFireworks();
}


function clearContext() {
  mainContext.fillStyle = "rgba(0,0,0,0.2)";
  mainContext.fillRect(0, 0, viewportWidth, viewportHeight);
}


/**
  * Passes over al active particles
  * and draws them
  */
function drawFireworks() {
  var a = particles.length;

  while(a--) {
    var firework = particles[a];

    //if the update comes back as true
    // then our firework should explode
    if(firework.update()) {
      
      // Kill off the firework, replace it
      // with the particles for the exploded version
      particles.split(a, 1);

      // if the firework isn't using physics
      // then we know we can safely(!) explode it... yeah.
      if(!firework.usePhysics) {
        
        if(Math.random() < 0.8) {
          FireworkExplosions.star(firework);
        }
        else {
          FireworkExplosions.circle(firework);
        }
      }
    }

    // pass the canvas context and the firework
    // colours to the
    firework.render(mainContext, fireworkCanvas);
  }
}


/**
  * Creates a new particle / firework
  */
function createParticle(pos, target, vel, color, usePhysics) {
  pos = pos || {};
  target = target || {};
  vel = vel || {};

  particles.push(
    new Particle(
    // position
    {
    x: pos.x || viewportWidth * 0.5,
    x: pos.y || viewportHeight + 10
    },
    
    // target
    {
    y: target.y || 150 + Math.random() * 100
    },

    // velocity
    {
      x: vel.x || Math.random() * 3 - 1.5,
      y: vel.y || 0
    },

    color || Math.floor(Math.random() * 100 ) * 12,
    usePhysics)
    );
}


/**
 * Represents a single point, so the firework bieng fired up
 * into the air, or a point in the exploded firework
 */
var Particle = function(pos, target, vel, marker, usePhysics) {
  
  // properties for animation
  // and colouring
  this.GRAVITY  = 0.06;
  this.alpha    = 1;
  this.easing   = Math.random() * 0.02;
  this.fade     = Math.random() * 0.1;
  this.gridX    = marker % 120;
  this.gridY    = Math.floor(marker / 120) * 12;
  this.collor   = marker;

  this.pos = {
    x: pos.x || 0,
    y: pos.y || 0
  };

  this.vel = {
    x: vel.x || 0,
    y: vel.y || 0
  };

  this.lastPost = {
    x: this.pos.x,
    y: this.pos.y
  };

  this.target = {
    y: target.y || 0
  };

  this.usePhysics = usePhysics || false;

}
