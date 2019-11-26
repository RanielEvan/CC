<?php 

    include_once 'conexao.php';

    $nome = $_POST["pNome"];
    $preco = $_POST["pPreco"];
    $estoque = $_POST["pEstoque"];

    $con -> exec("
        INSERT INTO produtos (nome, preco, estoque)
        VALUES ('".$nome."', '".$preco."', '".$estoque."')
    ");
    
    header('Location: paineldecontrole.php?sts=1');


?>