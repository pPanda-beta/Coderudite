angular.module('mainNgApp').controller('loginController', function ($scope) {
	$scope.trialUser = {
		email: "",
		password: "",
		login: function () {
//			console.log(this);
			app.tryLoginWith($scope.trialUser)
					.onsuccess(function (d) {
						console.log(d);
						$scope.message = d.message;
						app.state.sessionId = d.sessionId;
						app.saveState();
						$scope.$apply();
					});
		}
	};
});
