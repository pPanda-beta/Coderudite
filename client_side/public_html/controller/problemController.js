angular.module('mainNgApp').controller('problemController', function ($scope) {

	$scope.problem = {};

	app.getProblemById("P001")
			.onsuccess(function (problem1) {
				$scope.problem = problem1;
				$scope.$apply();
			});


});
