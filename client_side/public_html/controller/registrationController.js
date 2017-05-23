angular.module('mainNgApp').controller('registrationController', function ($scope, $location) {
	$scope.trialUser = {};
	$scope.registration = function () {
//			console.log(this);
		//alert(JSON.stringify($scope.trialUser));
		app.registerUser($scope.trialUser)
				.onsuccess(function (d) {
					//console.log(d);
					//$scope.message = d.message;
					if (d.status === "OK") {
						alert(d.message);
						//TODO : move to login page
						document.getElementById('loginLink').click();
					} else
						alert(d.message);
					$scope.$apply();
				});
	};
});


