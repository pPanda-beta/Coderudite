angular.module('mainNgApp').controller('codeEditorController', function ($scope) {
	console.log('Code editor started');

	$scope.types = ['c', 'java'];

	$scope.sol = {
		type: 'x'
	};

	$scope.result = {};

	$scope.modeChanged = function () {
		var aceThemes = {
			c: "ace/mode/c_cpp",
			java: "ace/mode/java"
		};
		editor.session.setMode(aceThemes[$scope.sol.type]);
	};

	$scope.submitSolution = function () {
		$scope.sol.src = editor.getValue();
		console.log($scope.sol);
	};
});
