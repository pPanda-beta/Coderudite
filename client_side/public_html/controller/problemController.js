angular.module('mainNgApp').controller('problemController', function ($scope) {

	$scope.problem = {};

	app.getProblemById("P001")
			.onsucess(function (problem1) {
				$scope.problem = problem1;
				$scope.$apply();
			});


});
