const net = require('net');
const repl = require('repl');
const client = net.connect(32251,'shell2017.picoctf.com',()=>{
	console.log('CONNECTED');
});
client.on('close',()=>{
	console.log('DISCONNECTED');
	process.exit(1);
});
let leftCards = 52;
let money = 48;
client.on('data',(data)=>{
	data = data.toString();
	console.log(data.toString());
	if( /Please enter your name:/.test(data) )
	{
		client.write(Buffer.from([4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4]));
		client.write("\n");
	}
	else if( /How much would you like to bet?/.test(data) )
	{
		if(leftCards>0)
		{
			client.write("1\n");
			leftCards--;
		}
		else
		{
			client.write(money+"\n");
			money*=2;
		}
	}
	else if( /You won the game!/.test(data) )
	{
		repl.start({
			eval:(command)=>{
				client.write(command);
			}
		});
	}
});