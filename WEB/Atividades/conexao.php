<?php

    $con = mysqli_connect("localhost", "root", "");


	if($con){
		echo "<h1 style='color:green'>Conexão estabelecida pae!</h1>";
		
		// if (mysqli_query($con, "CREATE DATABASE IF NOT EXISTS meubd"))
		// 	echo 'Banco de dados criado';
		// else 
		// 	echo 'Erro criando o banco de dado';
		
		mysqli_select_db($con, "meubd");
		
		mysqli_query($con,"
			CREATE TABLE comentarios (
			id MEDIUMINT NOT NULL AUTO_INCREMENT,
			mensagem varchar(255),
			PRIMARY KEY(id))");
		
		// mysqli_query($con,"
			// INSERT INTO pessoas 
			// (nome)
			// VALUES
			// ('EVAN EVAN ERASL')
			// ");
	
		// $dados = mysqli_query($con, "SELECT * FROM PESSOAS");
		// while($tb = mysqli_fetch_array($dados)){
		// 	echo $tb['nome'].'<br/>';
		// }
		
		mysqli_close($con);
		
	} else {
		echo "<h1>ERRO NA CONEXÃO!</h1>";
	}
	
?>