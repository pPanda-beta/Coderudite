angular.module('mainNgApp').controller('loginController', function ($scope) {
	$scope.trialUser = {
		email: "",
		password: "",
		login: function () {
//			console.log(this);
			app.tryLoginWith($scope.trialUser)
					.onsucess(function (d) {
						console.log(d);
						$scope.message = d.message;
						$scope.$apply();
					});
		}
	};
});
