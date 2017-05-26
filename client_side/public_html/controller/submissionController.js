angular.module('mainNgApp').controller('submissionController', function ($scope) {

	$scope.submissions = [];
//	app.getSubmission("S001")
//			.onsuccess(function (submission1) {
//				$scope.submission = submission1;
////				$scope.$apply();
//
//
//			});
	app.getMySubmissionIds()
			.onsuccess(function (subIds) {
				subIds.forEach(function (subId) {
					app.getSubmission(subId)
							.onsuccess(function (submission1) {
								$scope.submissions.push(submission1);
								$scope.$apply();
							});
				});
			});

//	this.getMySubmissionIds = function () {
//
//		return {
//			onsuccess: function () {
//				$scope.mysubmissions = {
//					sid: 'S001'
//				};
//			}
//		};
//		alert(JSON.stringify($scope.mysubmissions));
//		$scope.$apply();
//	};
	$scope.selected = {};
	$scope.displayCode = function (src) {
		//TODO : set the spource
		if ($scope.selected.src != src) {
			$scope.selected.src = src;
			$("#submissionpanel").show();

//			$("#submissionpanel").toggle();
		} else {
			$("#submissionpanel").toggle();
		}
	}
});
