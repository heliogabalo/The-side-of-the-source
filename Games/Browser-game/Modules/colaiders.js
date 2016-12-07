function ColaiderMod() {
  
  this.colaider = function() {
    
      //colaider prototype !!!!!!!!!!!!!!!
      ctx.beginPath();
      ctx.arc(240,160,20,0,2 * Math.PI, false);
      ctx.strokeStyle = "rgba(0,255,255,1)";
      ctx.stroke();
      ctx.closePath();
      console.log("step Mod:", this.colaider);
      return "hello";
  };
  
}

module.exports = ColaiderMod;