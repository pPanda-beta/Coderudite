angular.module('mainNgApp').controller('problemController', function ($scope) {

	$scope.problem = {};
	//app.get;
	app.getProblemById("p001")
			.onsucess(function (problem) {
				$scope.problem = problem;
			});


});
