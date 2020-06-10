<?php  

    include_once 'conexao.php';
        
    mysqli_query($con,"DELETE FROM comentarios");

    header('Location: index.php');

?>