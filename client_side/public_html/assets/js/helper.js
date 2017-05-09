
var helper = {

	prepareRoute: function (strings) {
		var routeName = strings[0];
		var routeViewUrl = strings[1];
		var routeControllerJsUrl = strings[2];
		var routeControllerName = strings[3];

		if (routeViewUrl == undefined) {
			routeViewUrl = siteroot + 'view/' + routeName + 'View.html';
		}

		if (routeControllerJsUrl == undefined) {
			routeControllerJsUrl = siteroot + 'controller/' + routeName + 'Controller.js';
		}

		if (routeControllerName == undefined) {
			routeControllerName = routeName + 'Controller';
		}

		return {
			requestName: '/' + routeName,
			viewUrl: routeViewUrl,
			controllerJsUrl: routeControllerJsUrl,
			controllerName: routeControllerName
		};
	},

	makeRoutingModule: function (attribs) {
		var moduleName = attribs[0];
		console.warn('Kai' + moduleName);
		var routerModule = angular.module(moduleName, ['ngRoute']);
		routerModule.config(['$locationProvider', function ($locationProvider) {
				$locationProvider.hashPrefix('');
			}]);
		var routes = attribs.slice(1).map(this.prepareRoute);
		routes.forEach(function (route) {
			var controllerJs = document.createElement('div');
			loadjscssfile(route.controllerJsUrl, controllerJs);
			document.write(controllerJs.innerHTML);
		});

		routerModule.config(function ($routeProvider) {
			console.warn('Chai');
			routes.forEach(function (route) {
				$routeProvider
						.when(route.requestName, {
							templateUrl: route.viewUrl,
							controller: route.controllerName
						});
			});
		});

		return routerModule;
	},

	bootstrapAngularApps: function () {
		$('[ng-app]').each(function (index, node) {
			if (!node.getAttribute('bootstraped')) {
				var appName = node.getAttribute('ng-app');
				angular.bootstrap(node, [appName]);
				node.setAttribute('bootstraped', true);
			}
		});
	}
};