/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

var mainNgApp = helper.makeRoutingModule(['mainNgApp',
	['login'],
	['contest'],
	['problem'],
	['registration'],
	['submission']
]);


var codeEditorApp = angular.module('codeEditorApp', []);