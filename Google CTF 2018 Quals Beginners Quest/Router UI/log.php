<?php
file_put_contents('log.txt',$_SERVER['REQUEST_URI'].PHP_EOL,FILE_APPEND);
die;