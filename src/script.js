function MyClass( label ) {
    this.label = label; }
MyClass.prototype.updateText = function ( str ) {
    this.label.text = str;
}
function updateText( str ) {
    label1.text = str;
}
wgt.windowTitle = "Signals And Slots";
lineedit.text = "Test";
lineedit.textChanged.connect( updateText );
var myObject = new MyClass( label2 );
lineedit.textChanged.connect( myObject, myObject.updateText );
lineedit.textChanged.connect( label3.setText );
lineedit.textChanged.connect( function(str) {label4.text = str} );
