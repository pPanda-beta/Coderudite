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
	$scope.displayCode = function (sub) {
		//TODO : set the spource
		console.log(sub);
		if ($scope.selected.src !== sub.src) {
			$scope.selected = sub;
//			$scope.selected.src = sub.src;
//			$scope.selected.lang = sub.lang;
			$("#submissionpanel").show();

//			$("#submissionpanel").toggle();
		} else {
			$("#submissionpanel").toggle();
		}
	}
});
