$(function() {
  var wl1 = new Wirelib($("#canvas1")[0]), n = 0;
  wl1.setStrokeStyle("#ff0000");
  wl1.addBox(0,0,0,100,100,100);
  wl1.loop(24,
           function() {
            wl1.rotateY(0.1);
            });
  var wl2 = new Wirelib($("#canvas2")[0]);
  wl2.setStrokeStyle("#0000ff");
  wl2.addBox(0,0,0,100,100,100);
  wl2.loop(12,
           function() {
            wl2.rotateX(0.1);            
            wl2.rotateY(Math.sin(n) * 0.2);
            n += 0.02;
            });
});