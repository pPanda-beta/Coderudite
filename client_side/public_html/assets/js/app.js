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
		jqXhr1.onsucess = function (callbackEatsJson) {
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
		return this.requestJson('/problem/getId', {id: idValue});
	};
}
