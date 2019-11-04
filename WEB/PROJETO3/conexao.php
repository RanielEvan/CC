<?php

	$con = mysqli_connect("localhost", "root", "");
	
	mysqli_select_db($con, "meubanco");
		
    mysqli_query($con,"
        CREATE TABLE IF NOT EXISTS usuarios (
        id MEDIUMINT NOT NULL AUTO_INCREMENT,
        nome varchar(50),
        senha varchar(50),
        email varchar(50),     
        PRIMARY KEY(id))");

    mysqli_query($con,"
		CREATE TABLE IF NOT EXISTS produtos (
		id MEDIUMINT NOT NULL AUTO_INCREMENT,
		nome varchar(50),
        preco MEDIUMINT,
        estoque MEDIUMINT,        
		PRIMARY KEY(id))");

?>