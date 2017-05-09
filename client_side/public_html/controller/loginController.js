angular.module('mainNgApp').controller('loginController', function ($scope) {
	$scope.trialUser = {
		email: "",
		password: "",
		login: function () {
			console.log(this);
		}
	};
});
