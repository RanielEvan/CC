<?php

    //PHP DATA OBJECTS

	$con = new PDO('mysql:host=localhost; port=3306; dbname=meubanco', 'root', '');

        
    $con -> exec("
        CREATE TABLE IF NOT EXISTS usuarios (
        id MEDIUMINT NOT NULL AUTO_INCREMENT,
        nome varchar(50),
        senha varchar(50),
        email varchar(50),     
        PRIMARY KEY(id))");

    $con -> exec("
		CREATE TABLE IF NOT EXISTS itens (
		id MEDIUMINT NOT NULL AUTO_INCREMENT,
		nome varchar(50),
        preco MEDIUMINT,
        estoque MEDIUMINT,
        imagem LONGBLOB,        
		PRIMARY KEY(id))");

?>