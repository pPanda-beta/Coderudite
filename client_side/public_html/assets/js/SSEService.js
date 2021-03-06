
function SSEService(url, payload, interval) {
	var lastTriggered = Date.now();
	var timeoutId;
	var jqXhrSSE;
	var doneCallbacks = [];
	var doneWithJsonCallbacks = [];
	var sseService = this;


	this.repeatImmediate = function () {
		this.lastTriggered = Date.now();
		if (this.jqXhrSSE)
			this.jqXhrSSE.abort();

		this.jqXhrSSE = $.ajax({
			url: url,
			method: "POST",
			data: payload,
			timeout: 12000
		});
		this.jqXhrSSE.done(function (data) {

			try {
				var jsonData = JSON.parse(data);
				if (jsonData.type === "BEGIN")
					return;
				doneWithJsonCallbacks.forEach(function (callback) {
					callback(jsonData);
				});
			} catch (e) {
			}

			doneCallbacks.forEach(function (callback) {
				callback(data);
			});
		});
		this.jqXhrSSE.always(function (_d, textStatus, _e) {
//			console.log(textStatus);
			if (textStatus !== "error" && textStatus !== "timeout")
				sseService.repeatImmediate();
			else
				sseService.repeatScheduled();
		});
	};

	this.repeatScheduled = function () {
		if (this.timeoutId)
			clearInterval(this.timeoutId);
		if (Date.now() <= this.lastTriggered + interval)
			this.timeoutId = setTimeout(sseService.repeatImmediate, this.lastTriggered + interval - Date.now());
		else
			sseService.repeatImmediate();
//		console.log(this.timeoutId);
	};


	return {
		onmessage: function (callback) {
			doneCallbacks.push(callback);
		},
		onJson: function (callback) {
			doneWithJsonCallbacks.push(callback);
		},
		start: function () {
			sseService.repeatImmediate();
		}
	};
}