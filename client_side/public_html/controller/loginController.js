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
						app.state.userInfo = d.info;
						app.saveState();
						$scope.$apply();
						$('#userName').html(app.userName());
					});
		}
	};

	if (app.state.sessionId !== undefined) {
		$("#loginLink").hide();
	}

});
