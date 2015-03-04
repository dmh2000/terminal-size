# terminal-size
a simple node module to get the size of the terminal window in which it is running.


    var terminal_size = require("./terminal-size.js");
    var a = terminal_size();
    console.log(a);
    [ 25, 80 ]
    returns an array with 2 integers representing [rows,cols]
