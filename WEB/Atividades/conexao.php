<?php

	$con = mysqli_connect("localhost", "root", "");
	
	mysqli_select_db($con, "meubd");
		
	mysqli_query($con,"
		CREATE TABLE IF NOT EXISTS comentarios (
		id MEDIUMINT NOT NULL AUTO_INCREMENT,
		nome varchar(30),
		texto varchar(255),
		PRIMARY KEY(id))");

?>