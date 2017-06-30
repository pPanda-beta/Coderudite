angular.module('mainNgApp').controller('leaderboardController', function ($scope) {

	app.requestJson('/leaderboard', {})
			.onsuccess(function (ldb) {
				$("#example").dataTable({
					data: ldb.body,
					columns: ldb.header.map((hd) => ({title: hd})),
					iDisplayLength: -1
				});
			});
});
