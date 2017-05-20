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


}
