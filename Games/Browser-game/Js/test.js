  
// http://kopy.io/CuT7d
///////////////////////////////////////
///// The checkLevel() Function notes /

function activeLevel(){
	var checkLevel = []; 					// Actual level.
	var levelArray = ['r1','r2','r3'];  // string inside object.row.
	var stringLvl;

/* That was the original function. Never worked!!	
	for(i=0; i<=gems.length; i++) {    // Loop to find active lvl.
    for(j=0; j<=gems[i]; j++){
      if( gems[i].id[j] == level ){
			checkLevel = gems[i].id[j];      
      }
    }		
	}
*/
// I used this beautifull ruby syntax, and works like a chimp.
gems.forEach(function(value, i) {
  if(gems[i].id == level){
    checkLevel = gems[i].row;  // we want key "row".
  }
});

  console.log("step 1 - checkLevel is:", checkLevel);

  levelArray.forEach(function (value, i) {
    stringLvl[i] = checkLevel[value].split('');    
    });
  
  console.log("step 2 - stringLvl is:", stringLvl);
  
  // This waw original function, we can translate it to ruby syntax
  // and get out the "symbol" checker to avoid extra checks!.

	for(c=0; c<brickColumnCount; c++){   // to push the strings from array &
		blocks[c] = [];					 // to interpret booleans.
		blocks.push(stringLvl[c]);        
		for(r=0; r<brickRowCount; r++){
			blocks[c][r] = { x: 0, y: 0, status: 1 };
			blocks.push(stringLvl[c][r]);
			if(blocks[c][r] == "-"){    // this checks exhaustively the [] get out instead!!
				status = 0;
			}
			else if(blocks[c][r] == "*"){  // wrap out that too.
				status = 1;
			}      
		}        
	}
  
  stringLvl.forEach(function(c, r) {
    if(stringLvl[c][r] == "-"){
      bricks.status = 0;
    }
    else{
      bricks.status = 1;
    }
  });
  
  
  console.log("step 3 - blocks is:", blocks);
  bricks = blocks;

//	drawBricks();						// function call from actual lvl.
}

///////////////////////////////////////////////


// Alternativa para construir bloques por nivel -- yet untested!!
function constructLvl() {
  var i, rowBrick, blocks;
  blocks = (typeof arguments[0] === "object") ? arguments[0] : arguments;
  
  rowBrick = blocks.length;  
  if(rowBrick >= 5) {
    rowBrick = {blocks:[]};
    for(i = 0; i < rowBrick; i += 5) {
      rowBrick.push({c:blocks[i], c:blocks[i+1],c:blocks[i+2],
                   c:blocks[i+3],c:blocks[i+4]});
    }    
  }
  else {
      console.error("Son 5 columnas, revisa el código!");
    }
  return cadena;
}


////////////////////////////////////////////////
/////////           APUNTES  ///////////////////
///////////////////////////////////////////////
var arr = gems[0].row.r1;
var arr2 = arr.split('');
/////////////////
    var getter = $parse(str);
    var theValue = getter(obj);
////////////////////
    arr = arr2.split('');
///////////////////
Object.byString = function(o, s) {
    s = s.replace(/\[(\w+)\]/g, '.$1'); // convert indexes to properties
    s = s.replace(/^\./, '');           // strip a leading dot
    var a = s.split('.');
    for (var i = 0, n = a.length; i < n; ++i) {
        var k = a[i];
        if (k in o) {
            o = o[k];
        } else {
            return;
        }
    }
    return o;
};
/////////////////////
var x = obj[Object.keys(obj).filter(item => obj[item].id)];

////////////////////////
// if you don't know all the key in your object:
Object.keys(myObject).forEach(...);

////////////////////////////////////////
//// boolean way to get out on a loop ///
////////////////////////////////////////
var a, b, abort = false;
for (a = 0; a < 10 && !abort; a++) {
    for (b = 0; b < 10 && !abort; b++) {
        if (condition) {
            doSomeThing();
            abort = true;
        }
    }
}

/////////////////////////////////////////////////
///////////// Color aleatorio ///////////////////

function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++ ) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}
var randColor = '#'+(Math.random()*0xFFFFFF<<0).toString(16);

/////////////////////////////////////////////
// On tne end of the .js file it was called
// main draw function as this.
// setInterval(draw, 10); // as argument, now it is done
// by: requestAnimationFrame(draw) and draw() is called
// directly.