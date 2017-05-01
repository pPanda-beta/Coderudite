

function sleep(milliseconds) {
	var start = new Date().getTime();
	while ((new Date().getTime() - start) < milliseconds);
}


function loadjscssfile(filename, container, isAsync) {
	if(typeof(isAsync)==='undefined') isAsync=false;
	var fileref;
	var filetype=filename.substr(filename.lastIndexOf('.') + 1);
	if (filetype === "js") { //if filename is a external JavaScript file
		fileref = document.createElement('script');
		fileref.setAttribute("type", "text/javascript");
		fileref.setAttribute("src", filename);
		fileref.async = isAsync;
	}
	else if (filetype === "css") { //if filename is an external CSS file
		var fileref = document.createElement("link");
		fileref.setAttribute("rel", "stylesheet");
		fileref.setAttribute("type", "text/css");
		fileref.setAttribute("href", filename);
	}
	if ("undefined" != typeof fileref)
		container.appendChild(fileref);
}


{
	var newbee = document.createElement('div');

	loadjscssfile("./assets/lib/bootstrap/css/bootstrap.min.css", newbee);
	loadjscssfile("./assets/lib/bootstrap/css/bootstrap-theme.min.css", newbee);
	loadjscssfile("./assets/lib/c3/c3.min.css", newbee);
	loadjscssfile("./assets/lib/datatables/css/jquery.dataTables.min.css", newbee);
	loadjscssfile("./assets/lib/patternfly/css/patternfly.min.css", newbee);
	loadjscssfile("./assets/lib/patternfly/css/patternfly-additions.min.css", newbee);

	loadjscssfile("./assets/lib/font-awesome/css/font-awesome.min.css", newbee);
	loadjscssfile("./assets/lib/google-code-prettify/prettify.min.css", newbee);




//loadjscssfile("assets/lib/requirejs/require.js", newbee);
	loadjscssfile("assets/lib/jquery/jquery.min.js", newbee);

//window.jQuery = window.$ = require('jquery');


	loadjscssfile("assets/lib/bootstrap/js/bootstrap.min.js", newbee);
	loadjscssfile("assets/lib/patternfly/js/patternfly.min.js", newbee);

	loadjscssfile("./assets/lib/c3/c3.min.js", newbee);
	loadjscssfile("./assets/lib/d3/d3.min.js", newbee);


//whats wrong with EACH of them???
	loadjscssfile("./assets/lib/datatables/js/jquery.dataTables.min.js", newbee);	//neccessary

	loadjscssfile("./assets/lib/google-code-prettify/prettify.min.js", newbee);
//loadjscssfile("./assets/lib/google-code-prettify/run_prettify.min.js", newbee);

	loadjscssfile("./assets/lib/easyXDM/easyXDM.min.js", newbee);
	loadjscssfile("./assets/lib/easyXDM/easyXDM.Widgets.min.js", newbee);



	loadjscssfile("./assets/lib/YUI/yahoo-min.js", newbee);
	loadjscssfile("./assets/lib/YUI/get-min.js", newbee);

	loadjscssfile("./assets/lib/angularJs/angular.js", newbee);

//	document.write(newbee.innerHTML);
	document.head.appendChild(newbee);
	//document.head.innerHTML+=newbee.innerHTML;
}

