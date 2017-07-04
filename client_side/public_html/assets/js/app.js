/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function Application() {

	this.state = {};
	this.saveState = function () {
		localStorage.appState = JSON.stringify(this.state);
	};
	this.loadState = function () {
		if (localStorage.appState == undefined) {
			this.state = {
				servers: app.defaultServers
			};
		} else {
			this.state = JSON.parse(localStorage.appState);
		}
	};

	this.userName = function () {
		if (this.state.userInfo == undefined)
			return 'NOT LOGGED IN';
		return this.state.userInfo.firstName + ' ' + this.state.userInfo.lastName;
	};

	this.defaultServers = {
		cdn: window.location.origin,
		chost: window.location.protocol + '//' + window.location.hostname + ':' + '4444'
	};

	this.requestJson = function (servlet, payload) {
		var jqXhr1 = $.post(this.state.servers.chost + servlet,
				{sessionId: app.state.sessionId, json: JSON.stringify(payload)});
		var oldDone = jqXhr1.done;
		jqXhr1.onsuccess = function (callbackEatsJson) {
			oldDone(function (data) {
				try {
					callbackEatsJson(JSON.parse(data));
				} catch (e) {
					console.warn(e);
					console.log(servlet);
					console.log(payload);
				}
			});
		};
		return jqXhr1;
	};

	this.tryLoginWith = function (user) {
		return this.requestJson('/login', user);
	};

	this.setCurrentProblem = function (problem) {
		app.state.currentProblem = problem;
		app.state.currentPid = problem.id;
		app.saveState();
	};

	this.getCurrentProblemId = function () {
		return app.state.currentPid;
	};

	this.getProblemById = function (idValue) {
		return this.requestJson('/problem/getById', {id: idValue});
	};

	this.submitSolution = function (pid1, src1, type) {
		return this.requestJson('/submission/submit', {pid: pid1, src: src1, lang: type});
	};

	this.submitSolutionForCurrentState = function () {
		return this.requestJson('/submission/submit', {
			pid: app.state.currentProblem.id,
			pname: app.state.currentProblem.name,
			difficulty: 'Easy',
			src: app.state.currentSrc,
			lang: app.state.currentLang
		});
	};

	this.registerUser = function (trialUser) {
		return this.requestJson('/register', trialUser);
	};

	this.getProblems = function () {
		return {
			onsuccess: function (callback) {
				callback([{id: "P001"}, {id: "P002"}, {id: "P003"}]);
			}
		};
	};

	this.getSubmission = function (sid1) {
		return this.requestJson('/submission/getById', {sid: sid1});
	};

	this.getMySubmissionIds = function () {
		return this.requestJson('/submission/getAllIds', {});
		return {
			onsuccess: function (callback) {
				callback(["S001", "Punit", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001"]);
			}
		};
	};


}
