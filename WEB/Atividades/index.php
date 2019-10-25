<?php
    

?>

<html>
    <head>
    
        <title>Comentários</title>

        <!--Bootstrap-->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        
        <!--Custom-->
        <link rel="stylesheet" href="stylo.css">
    </head>


    <body>

        <main>

            <!-- Titulo do site -->
            <h1> Pagina de Comentários</h1>
        
            <!-- Enviar Comentario & Comentarios -->
            <div class="row">  <!-- LINHA -->

                <div class="col-sm-4"> <!-- Coluna 4/12   (Podem ter até 12 colunas numa linha(ROW))-->

                    <!-- ENVIO DE COMENTÁRIOS
                    Form possui um ID que utilizo para trocar a rota, pelo JavaScript
                                    ID                  ROTA              POST   -->
                    <form id="comentarioForm" action="enviar.php" method="POST">

                        <label for="comentario">Escreva seu comentário</label>
                        <textarea class="form-control" name="comentario"></textarea> <!-- Comentario -->
                    
                        <!-- Prefiro fazer o Submit pelo JavaScript,
                        porque nessa pagina, 3 botões precisam Submeter
                        EnviarMsg  ,  ApagarMsgs   ,  Sair 
                        Mas cada um aponta para uma rota diferente, que é definida no Script -->
                        <button onclick="EnviarMsg()" type="button" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-success">Enviar</button>
                    </form>
                </div>
            

                <div class="col-sm-6"> <!-- Coluna 6/12    (Total de 10 colunas com a de cima, falta 2, mas não vou utilizar) -->

                    <!-- LISTA DE COMENTARIOS
                    Aqui é listado os comentários -->

                    <div></div>
                    <?php 
                        
                    ?>

                </div>

                <button type="submit" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-success">Enviar</button>
                   
            </div>









        
        </main>


        <!-- SCRIPTS
        Os scripts ficam abaixo.
        Pra usar o BOOSTRAP, é necessário que os scripts
        estejam na ordem: JQUERY, POOPER.JS e BOOTSTRAP.

        Scripts customizados vem depois -->
        
        <!--Boostrap-->
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    
        <!
    
    </body>


</html>