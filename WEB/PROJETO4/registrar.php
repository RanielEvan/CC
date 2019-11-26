<?php 

    include_once 'conexao.php';

    $user = $_POST["regUser"];
    $pass = base64_encode($_POST["regPass"]); //Aplica o Base64
    $email = $_POST["regEmail"];


    $con->exec("
        INSERT INTO usuarios (nome, senha, email)
        VALUES ('".$user."', '".$pass."', '".$email."')
    ");
    
    header('Location: index.php?status=2');


?>