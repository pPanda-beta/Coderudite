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
			this.state = {};
		} else {
			this.state = JSON.parse(localStorage.appState);
		}
	};

	this.state.servers = {
		cdn: window.location.origin,
		chost: window.location.protocol + '//' + window.location.hostname + ':' + '4444'
	};

	this.requestJson = function (servlet, payload) {
		var jqXhr1 = $.post(this.state.servers.chost + servlet,
				{json: JSON.stringify(payload)});
		var oldDone = jqXhr1.done;
		jqXhr1.onsuccess = function (callbackEatsJson) {
			oldDone(function (data) {
				try {
					callbackEatsJson(JSON.parse(data));
				} catch (e) {
					console.warn(e);
				}
			});
		};
		return jqXhr1;
	};

	this.tryLoginWith = function (user) {
		return this.requestJson('/login', user);
	};

	this.getProblemById = function (idValue) {
		return this.requestJson('/problem/getById', {id: idValue});
	};

	this.submitSolution = function (cid, pid, src, type) {
		return {
			onsuccess: function (callback) {
				callback("sid");
			}
		};
	};

	this.registerUser = function (trialUser) {
//		return this.requestJson('/register',trialUser);

		return	{
			onsuccess: function (callback) {
				callback({
					message: "Registration Successful!",
					status: "OK"
				});
				callback({
					message: "Registration Unsuccessful! Email already exists",
					status: "ERROR"
				});
			}
		}
	}
	this.getSubmission = function (sid1) {
		return {
			onsuccess: function (callback) {
				callback({
					sid: 'S001',
					pid: 'P001',
					pname: 'Palash\'s Party ' + sid1,
					status: 'ERR',
					error: 'N/A',
					src: '#include........',
					lang: 'C++',
					difficulty: 'Easy'
				});
			}
		};
	};

	this.getMySubmissionIds = function () {
		return {
			onsuccess: function (callback) {
				callback(["S001", "Punit", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001", "S001"]);
			}
		};
	};
}
