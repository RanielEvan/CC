
<!DOCTYPE html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <!-- BOOTSTRAP -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    
    <!-- CUSTOM -->
    <style>
        
        main{
            background-color: white;
            border-radius:20px;
            margin: 150px; margin-left: 300px; margin-right: 300px;
            padding: 50px;
        }

        .formin{
            margin: 10px;
        }

        #formin{
            
        }

        .subs{
            padding: 10px; padding-left: 20px; padding-right:20px;
            font-weight: bold;
            float:right;
            margin-bottom: 20px;
        }
    </style>
</head>

<body style="background-color: darkslateblue">

    <main>

        <?php
            session_start();
            if(session_status() != PHP_SESSION_NONE && !empty($_SESSION["S_USER"])){
                echo "<h6 style='color: green'>".$_SESSION["Status"]."</h6>";
                echo "<input hidden='hidden' id='usr' value='".$_SESSION["S_USER"]."'/>".
                     "<input hidden='hidden' id='pw' value='".$_SESSION["S_PASS"]."'/>";
            }
        ?>

        <h3>Bem vindo!</h3>
        <i>Entre com seu Usuário e Senha</i>
        <form id="formin" action="paineldecontrole.php" method="POST">

            <input type="text" class="form-control formin" name="username" placeholder="Usuário" />
            <input type="password" class="form-control formin" name="passw" placeholder="Senha" />
            
            <button type="button" id="logBt" class="btn btn-primary formin subs">LOGAR!</button>
            
        </form>

        <div class="formin col-md-5" style="position: relative; top: 20px;">
            <a href="novoUser.php">Novo Usuário</a> | <a href="redefinirsenha.php">Esqueceu a senha?</a>
        </div>

    </main>


    <!-- SCRIPTS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    

    <script>
        
        $("#logBt").click(function(){

            var log = ($(":input[name='username']").val() == $("#usr").val());
            var pw = ($(":input[name='passw']").val() == $("#pw").val())
            if(log && pw){
                $("#formin").submit();
            } else {
                alert("USUÁRIO OU SENHA INCORRETOS!");
            }

        })


    </script>
</body>
</html>