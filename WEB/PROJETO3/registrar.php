<?php 

    include_once 'conexao.php';

    $user = $_POST["regUser"];
    $pass = md5($_POST["regPass"]); //Aplica o MD5
    $email = $_POST["regEmail"];


    mysqli_query($con, "
        INSERT INTO usuarios (nome, senha, email)
        VALUES ('".$user."', '".$pass."', '".$email."')
    ");
    
    header('Location: index.php?status=2');


?>