<?php  

    include_once 'conexao.php';
    
    $user = $_POST["user"];
    $pass = md5($_POST["pass"]); //Aplica o MD5, para comparar com a senha md5 do banco


    $dados = mysqli_query($con,"
        SELECT * FROM usuarios WHERE nome = '".$user."' AND senha = '".$pass."'
    ");
    
    if (mysqli_num_rows($dados) > 0){
        //Logado
        // while($tb = mysqli_fetch_array($dados)){
        //     echo $tb['nome'].'<br/>'.$tb['senha'].'<br/>'.$tb['email'];
        // }
        
        session_start();
        $_SESSION["USER_LOG"] = 1; //Armazena a info numa variavel de sessão
        
        header("Location: paineldecontrole.php");
    
    } else {

        //Informações erradas...
        header("Location: index.php?status=1");
      }


?>