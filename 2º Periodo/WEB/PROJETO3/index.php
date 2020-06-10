
<?php 
    $st = "";
    if(isset($_GET["status"])){
        switch($_GET["status"]){
            case '1':
                $st = "<p id='stTxt' style='color: orangered'><b>Login ou Senha Inválidos!</b></p>";
                break;
            case '2':
                $st = "<p id='stTxt' style='color: green'><b>Cadastro efetuado com sucesso!</b></p>";
                break;
            case '3':
                $st = "<p id='stTxt' style='color: orangered'><b>Login necessário!</b></p>";
                break;
        }
    }

?>

<html>
    <head>
    
        <title>Login</title>

        <!--Bootstrap-->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        
        <!--Custom-->
        <link rel="stylesheet" href="stylo.css">
    </head>


    <body>

        <main >

            <div class="row" id="telaLogin">
                <div class="col-sm-4" style="display:block; margin:auto; margin-top: 60px;  ">

                    <h1>Login</h1>
                    <form id="loginForm" action="login.php" method="POST">

                        <label for="nome">Usuário</label>
                        <input type="text" style="margin-bottom: 20px" class="form-control" name="user">

                        <label for="comentario">Senha</label>
                        <input type="password" style="margin-bottom: 20px" class="form-control" name="pass">

                        <button type="button" style="float:left; padding: 5px 35px; margin-top:0.5rem" class="btn btn-info RegistrarBut">Registrar</button>
                        <button type="submit" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-success">Logar</button>
                    </form>
                </div>
            </div>

            <div class="row" id="telaRegistro" style="display: none">
                <div class="col-sm-4" style="display:block; margin:auto; margin-top: 60px;  ">
                    
                    <button type="button" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-info LoginBut">Fazer Login</button>
                    <h1>Registrar</h1>
                    
                    <form id="registroForm" action="registrar.php" method="POST">

                        <label for="regUser">Usuário</label>
                        <input type="text" style="margin-bottom: 20px" class="form-control" name="regUser"> 

                        <label for="regPass">Senha</label>
                        <input type="password" style="margin-bottom: 20px" class="form-control" name="regPass"> 
                        
                        <label for="regPassConfirm">Confirmar Senha</label>
                        <input type="password" style="margin-bottom: 20px" class="form-control" name="regPassConfirm"> 

                        <label for="regEmail">Email</label>
                        <input type="email" style="margin-bottom: 20px" class="form-control" name="regEmail"> 

                        <button type="button" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-success RegistrarConfirm">Registrar!</button>
                    </form>
                </div>
            </div>

            <div style="text-align: center; margin-top: 20px">
                <p id="statusTxt"> <?php echo $st; ?> </p>
            </div>

        </main>



        <!-- SCRIPTS -->
        <!-- Jquery, Popper e Bootstrap -->
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    

        <!-- SCRIPTS CUSTOM-->
        <script>

            $(".RegistrarBut").on("click", function(){
                $("#telaRegistro").css("display", "");
                $("#telaLogin").css("display", "none");

                $("#stTxt").html("");
            });

            $(".LoginBut").on("click", function(){
                $("#telaLogin").css("display", "");
                $("#telaRegistro").css("display", "none");

                $("#stTxt").html("");
            });


            $(".RegistrarConfirm").on("click", function(){
                
                //Valida se as informações foram preenchidas
                var confirm = $("input[name='regUser']").val().length > 0 && $("input[name='regPass']").val().length > 0
                    && $("input[name='regPassConfirm']").val().length > 0 && $("input[name='regEmail']").val().length > 0;
                
                if(confirm){
                    confirm = $("input[name='regPass']").val() == $("input[name='regPassConfirm']").val();
                    if(confirm){
                        $("#statusTxt").html("Registro Ok!");
                        $("#statusTxt").css("color", "forestgreen");
                        $("#registroForm").submit();
                    } else {
                        $("#statusTxt").html("Senhas estão diferentes!");
                        $("#statusTxt").css("color", "crimson");
                    }
                } else {
                    $("#statusTxt").html("Preencha todos os campos!");
                    $("#statusTxt").css("color", "orangered");
                }
                
            });
        </script>


    </body>


</html>