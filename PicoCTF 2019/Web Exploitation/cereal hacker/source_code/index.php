<?php

if(isset($_GET['file'])){
	$file = $_GET['file'];
}
else{
	header('location: index.php?file=login');
	die();
}

if(realpath($file)){
	die();
}
else{
	include('head.php');
	if(!include($file.'.php')){
		echo 'Unable to locate '.$file.'.php';
	}
	include('foot.php');
}

?>