<?php  

    include_once 'conexao.php';
    
    $user = $_POST["user"];
    $pass = base64_encode($_POST["pass"]); //Aplica o B64, para comparar com a senha B64 do banco


    $dados = $con -> query("
        SELECT * FROM usuarios WHERE nome = '".$user."' AND senha = '".$pass."'
    ");

    if ($dados->rowCount() > 0){
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