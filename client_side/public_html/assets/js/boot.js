var app = new Application();

app.loadState();

var submissionEvents = SSEService('http://localhost:4444/events',
		{event: 'submissionsUpdated'},
		1000);
submissionEvents.start();