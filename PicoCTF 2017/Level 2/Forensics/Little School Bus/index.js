const fs = require('fs');
const raw = fs.readFileSync('littleschoolbus.raw');
let result = '';
let tmp = '';
for(let i = 0 ; i < raw.length; i++)
{
	tmp += ( raw[i] & 1 );
	if( tmp.length === 8 )
	{
		result += String.fromCharCode(parseInt(tmp,2));
		tmp = '';
	}
}
fs.writeFileSync("result.txt",result);