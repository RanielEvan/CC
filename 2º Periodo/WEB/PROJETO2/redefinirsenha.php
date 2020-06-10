<?php session_start(); ?>

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

        <h3>Redefinir Senha</h3>
        <form id="cadast" action="_registrar.php" method="POST">
            
            <div class="row my-2">
                <label class="col-sm-3 text-right my-2">Usuário: </label>
                <?php 
                    echo "<input type='text' readonly required class='form-control col-sm-8' name='username' value='".$_SESSION["S_USER"]."'   />";
                ?>
            </div>
           
            <div class="row my-2">
                <label class="col-sm-3 text-right my-2">Senha Antiga: </label>
                <?php 
                    echo "<input type='text' readonly class='form-control col-sm-8' value='".$_SESSION["S_PASS"]."'   />";
                ?>
            </div>
          
            <div class="row my-2">

                <label class="col-sm-3 text-right my-2">Nova Senha: </label>
                <input type="password" required class="form-control col-sm-8" name="passw" placeholder="Senha" />
            </div>

            <div class="row my-2">
                <label class="col-sm-3 text-right my-2">Redigite a Senha: </label>
                <input type="password" required class="form-control col-sm-8" name="passwConf" placeholder="Senha" />
            </div>

            <input hidden="hidden" name="Status" value="REDEF"/>
         
            <button id="btConf" type="button" class="btn btn-success formin">Atualizar Senha</button>
            
            
        </form>

    </main>


    <!-- SCRIPTS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    

    <script>
        
        $("#btConf").click(function(){

            if($(":input[name='passw']").val() == $(":input[name='passwConf']").val()){
                $("#cadast").submit();
            } else {
                alert("As senhas não são iguais! Tente novamente")
            }

        });
    
    </script>

</body>
</html>