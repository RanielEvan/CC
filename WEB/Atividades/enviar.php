<?php 

    include_once 'conexao.php';

    $comentario = $_POST["comentario"];
    $nome = $_POST["nome"];

    mysqli_query($con,"
                INSERT INTO comentarios 
                (nome, texto)
                VALUES
                ('".$nome."', '". $comentario ."')
                ");
        

    header('Location: index.php');
?>
