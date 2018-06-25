<?php
$sqlite = new SQLite3('wigle');
$result = $sqlite->query( 'SELECT COUNT(*) as count FROM location;' );
$count = $result->fetchArray(SQLITE3_ASSOC)['count'];
$result = $sqlite->query( 'SELECT lon,lat FROM location;' );
echo "longitude,latitude\n";
for($i=0;$i<$count;$i++)
{
	$row = $result->fetchArray(SQLITE3_ASSOC);
	echo $row['lon'].",".$row['lat']."\n";
}