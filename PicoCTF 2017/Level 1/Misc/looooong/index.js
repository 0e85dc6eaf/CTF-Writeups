const net = require('net');
const client = net.createConnection('51091','shell2017.picoctf.com',()=>{
	console.log('connected');
});
client.on('data',(data)=>{
	let msg = data.toString();
	console.log(msg);
	if(/^To prove your skills/.test(msg))
	{
		let res = msg.match(/'(.)' character '(.{3})' times, followed by a single '(.)'./);
		let answer = res[1].repeat(res[2])+res[3];
		client.write(answer+"\n");
		console.log(answer);
	}
});