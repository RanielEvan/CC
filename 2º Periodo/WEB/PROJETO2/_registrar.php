<?php

    session_start();
    $_SESSION["S_USER"] = $_POST["username"];
    $_SESSION["S_PASS"] = $_POST["passw"];

    if($_POST["Status"] == "CRIA"){
        $_SESSION["Status"] = "Usuario Registrado com Sucesso!";
    } else if ($_POST["Status"] == "REDEF"){
        $_SESSION["Status"] = "Senha Alterada com Sucesso!";
    }
   
    
    header('Location: index.php');
?>