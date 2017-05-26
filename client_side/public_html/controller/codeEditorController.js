angular.module('mainNgApp').controller('codeEditorController', function ($scope) {
	console.log('Code editor started');

	$scope.types = ['c', 'java'];

	$scope.sol = {
		type: app.state.currentLang || 'x'
	};


	$scope.result = {};

	$scope.modeChanged = function () {
		var aceThemes = {
			c: "ace/mode/c_cpp",
			java: "ace/mode/java"
		};
		editor.session.setMode(aceThemes[$scope.sol.type]);
		//alert($scope.sol.type);
		if (app.state.currentSrc !== undefined)
			return;
		if ($scope.sol.type === 'c')
		{
			var text = "#include<stdio.h>\n#include<string.h>\n#include<stdlib.h>\nint main()\n{\n\treturn 0;\n}";
			editor.setValue(text);

		} else
		{
			var text = "import java.io.*;\nimport java.util.*;\npublic class Main\n{\n\tpublic static void main(String args[])\n\t{\n\t\tSystem.out.println(\"Hello CSE\");\n\t}\n}";
			editor.setValue(text);
		}

	};

	$scope.submitSolution = function () {
		$scope.sol.src = editor.getValue();
		console.log($scope.sol);
//		app.submitSolution(app.getCurrentProblemId(), $scope.sol.src, $scope.sol.type)
		app.submitSolutionForCurrentState()
				.onsuccess(function (d) {
					$scope.result = d;
					$scope.$apply();
				});
	};

	$scope.updateModel = function () {
		console.log(editor.getValue());
		app.state.currentLang = $scope.sol.type;
		app.state.currentSrc = editor.getValue();
		app.saveState();
	};
});
