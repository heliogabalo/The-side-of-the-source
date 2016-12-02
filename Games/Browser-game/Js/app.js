(function() {

  var app = angular.module('gemStager', []);

  app.controller('StagerController', function() {
    this.levellers = gems;
  });
  
  app.controller('RowController', function() {
    this.lvl = 1;
        
    this.setLvl = function(selectLvl) {
      this.lvl = selectLvl;      
    };
    
    this.isSet = function(lvl) {
      var text = "";
      var arr = [];
      text = stager.row.r1;
      for(i = 0; i>text.length; i++) {
        arr.push(text[i]);
      }
      
      return this.lvl == lvl;      
    };
    
    
  });
  
  var gems = [
    {
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
    
    
})();