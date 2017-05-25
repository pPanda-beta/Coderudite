angular.module('mainNgApp').controller('contestController', function ($scope) {

	$scope.problems = [];
	app.getProblems()
			.onsuccess(function (subprobs) {
				subprobs.forEach(function (subprob) {
					app.getProblemById(subprob.id)
							.onsuccess(function (problem1) {
								$scope.problems.push(problem1);
								$scope.$apply();
							});
				});
			});
	$scope.setCurrentProblem = function (pid) {
		console.log(pid);
	}
});
