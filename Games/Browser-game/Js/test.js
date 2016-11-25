var status;
var blocks = [];

function checkBricks() {
  var cadena;
  
  for(c=0; c<brickColumnCount; c++) {
    for(r=0; r<brickRowCount; r++) {
      if(cadena == "-"){
        status = 0;
      }
      else if(cadena == "*"){
        status = 1;        
      }
    }
  }
}

[
  {
  "f-1": "*****",
  "f-2": "-***-",
  "f-3kojslin": "--*--"
  }
]
function constructLvl() {
  var i, rowBrick, blocks, strQuery;
  strQuery = (typeof arguments[0] === "object") ? arguments[0] : arguments;
  
  rowBrick = blocks.length;  
  if(rowBrick >= 5) {
    rowBrick = {blocks:[]};
    for(i = 0; i < rowBrick; i += 5) {
      rowBrick.push({r:blocks[i], r:blocks[i+1],r:blocks[i+2]
                   r:blocks[i+3],r:blocks[i+4]});
    }    
  }
  else {
      cosole.error("Son 5 columnas, revisa el código!");
    }
  return cadena;
}