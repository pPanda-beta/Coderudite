

function sleep(milliseconds) {
	var start = new Date().getTime();
	while ((new Date().getTime() - start) < milliseconds)
		;
}


function loadjscssfile(filename, container, isAsync) {
	if (typeof (isAsync) === 'undefined')
		isAsync = false;
	var fileref;
	var filetype = filename.substr(filename.lastIndexOf('.') + 1);
	if (filetype === "js") { //if filename is a external JavaScript file
		fileref = document.createElement('script');
		fileref.setAttribute("type", "text/javascript");
		fileref.setAttribute("src", filename);
		fileref.async = isAsync;
	} else if (filetype === "css") { //if filename is an external CSS file
		var fileref = document.createElement("link");
		fileref.setAttribute("rel", "stylesheet");
		fileref.setAttribute("type", "text/css");
		fileref.setAttribute("href", filename);
	}
	if ("undefined" != typeof fileref)
		container.appendChild(fileref);
}

//The Globals
{
	var externalLibraries = [
		"assets/lib/bootstrap/css/bootstrap.min.css",
		"assets/lib/bootstrap/css/bootstrap-theme.min.css",
		"assets/lib/c3/c3.min.css",
		"assets/lib/datatables/css/jquery.dataTables.min.css",
		"assets/lib/patternfly/css/patternfly.min.css",
		"assets/lib/patternfly/css/patternfly-additions.min.css",

		"assets/lib/font-awesome/css/font-awesome.min.css",
		"assets/lib/google-code-prettify/prettify.min.css",

//		"assets/lib/requirejs/require.js",
		"assets/lib/jquery/jquery.min.js",

		"assets/lib/bootstrap/js/bootstrap.min.js",
		"assets/lib/patternfly/js/patternfly.min.js",

		"assets/lib/c3/c3.min.js",
		"assets/lib/d3/d3.min.js",

//whats wrong with EACH of them???
		"assets/lib/datatables/js/jquery.dataTables.min.js", //neccessary

		"assets/lib/google-code-prettify/prettify.min.js",
//		"assets/lib/google-code-prettify/run_prettify.min.js",

		"assets/lib/easyXDM/easyXDM.min.js",
		"assets/lib/easyXDM/easyXDM.Widgets.min.js",

		"assets/lib/YUI/yahoo-min.js",
		"assets/lib/YUI/get-min.js",

		"assets/lib/angularJs/angular.js",
		"assets/lib/angularJs/angular-route.js"
	];


	var myJsFiles = [
		"assets/js/app.js",
		"assets/js/boot.js",
		"assets/js/helper.js",
		"assets/js/angularApps.js"
	];
}


function loadScripts(siteroot, scripts)
{
	var newbee = document.createElement('div');

	if (scripts == undefined) {
		externalLibraries.forEach(function (fileLocation) {
			loadjscssfile(siteroot + fileLocation, newbee);
		});
		myJsFiles.forEach(function (fileLocation) {
			loadjscssfile(siteroot + fileLocation, newbee);
		});
	} else {
		scripts.forEach(function (fileLocation) {
			loadjscssfile(siteroot + fileLocation, newbee);
		});
	}
	document.write(newbee.innerHTML);
//	document.head.appendChild(newbee);
}

