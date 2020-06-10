
<?php 

    include_once 'conexao.php';

    session_start();
    if(!isset($_SESSION["USER_LOG"])) //Verifica se o usuario está logado
        header("Location: index.php?status=3");

    $filtro = "";
    if(isset($_GET["filtro"])){
        $filtro = $_GET["filtro"];
    } else {
        $filtro = "ASC";
    }

    $st = "";
    if(isset($_GET["sts"])){
        switch($_GET["sts"]){
            case 1:
                $st = "<p style='color: green'><b>Produto cadastrado com sucesso!</b></p>";
            break;
        }
    }
?>

<html>
    <head>
    
        <title>Painel de Controle</title>

        <!--Bootstrap-->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        
        <!--Custom-->
        <link rel="stylesheet" href="stylo.css">
    </head>


    <body>

        <main style="margin: 35 50;">

            <h2>Produtos</h2>
            <div class="row" >

                <div class="col-sm-4"> 

                    <form id="produtoForm" action="addproduto.php" method="POST" style="margin-top: 20px">

                        <label for="pNome">Nome</label>
                        <input type="text" style="margin-bottom: 20px" class="form-control" name="pNome">

                        <div class="row">
                            <div class="col-6">
                                <label for="pPreco">Preço</label>
                                <input type="text" style="margin-bottom: 20px" class="form-control moeda" name="pPreco">
                            </div>

                            <div class="col-6">
                                <label for="pEstoque">Estoque</label>
                                <input type="text" style="margin-bottom: 20px" class="form-control numero" name="pEstoque">
                            </div>
                        </div>
                        
                        <button onclick="CadastrarProduto()" type="button" style="float:right; padding: 5px 35px; margin-top:0.5rem" class="btn btn-success">Cadastrar Produto</button>
                    </form>

                    <div style="text-align: center; margin-top: 80px">
                        <p id="statusTxt"> <?php echo $st; ?> </p>
                    </div>
                </div>
                
                   
                <div style="margin-right: 0; margin-left: auto;" class="col-sm-7"> 
                    
                    <button onclick="Logout()" type="button" style="float:right; padding: 5px 5px; position:relative; top:-40px" class="btn btn-danger">Logout</button>
                    
                    
                    

                    <div id="listaProd" style="margin-top: 70px;"> 
                        
                        <table style="border: 2px outset; width:100%">
                            
                            <thead>
                                <tr>
                                <th style="width:200px; border: 2px inset;">Nome</th>
                                <th style="width:100px; border: 2px inset;" class="text-right">Preço</th>
                                <th style="width:100px; border: 2px inset;" class="text-right">Estoque</th>
                                </tr>
                            </thead>

                            <tbody style="padding:20px">
                                <?php 
                                    // echo $filtro;
                                    $dados = mysqli_query($con, "SELECT * FROM produtos ORDER BY preco ".$filtro);
                                    
                                    while($tb = mysqli_fetch_array($dados)){
                                        echo
                                        '<tr style="height:30px">'.
                                            '<td>'.$tb['nome'].'</td>'.
                                            '<td class="moeda text-right">'.$tb['preco'].'</td>'.
                                            '<td class="text-right">'.$tb['estoque'].'</td>'.
                                        '</tr>';
                                    }
                                ?>
                            </tbody>

                        </table>

                        <div class="text-right" style="margin-top: 20px">
                            <?php 
                                if($filtro != "ASC"){
                                    echo "<button type='button' class='btn btn-warning' style='padding:3px 7px' onclick='ToggleFiltro(\"ASC\")'>Mais barato primeiro</button>";
                                } else {
                                    echo "<button type='button' class='btn btn-warning' style='padding:3px 7px' onclick='ToggleFiltro(\"DESC\")'>Mais caro primeiro</button>";
                                }
                                        
                            ?>
                        </div>
                        

                    </div>

                </div>


            </div>


            

        </main>



        <!-- SCRIPTS -->
        <!-- Jquery, Popper e Bootstrap -->
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
   

        <!-- SCRIPTS CUSTOM-->
        <script>

            $(document).ready(function(){
                //Formata os campos que vieram do BD, para Moeda
                $(".moeda").each(function(){ 
                    var v = $(this).html();
                    v = v.replace(/\D/g, '');
                    v = v.replace(/([0-9]{2})$/g, ",$1");
                    $(this).html(v);
                });
            });
            

            $(".moeda").on("keyup", function(){
                var v = $(this).val();
                v = v.replace(/\D/g, '');
                v = v.replace(/([0-9]{2})$/g, ",$1");
                $(this).val(v);
            });

            $(".numero").on("keyup", function(){
                var v = $(this).val();
                v = v.replace(/\D/g, '');
                $(this).val(v);
            });
            

            function CadastrarProduto(){

                var confirm = $("input[name='pNome']").val().length > 0 && $("input[name='pPreco']").val().length > 0
                    && $("input[name='pEstoque']").val().length > 0;

                if(confirm){
                    var vlrToInt = $(".moeda").val().replace(",","");
                    $(".moeda").val(vlrToInt);

                    $("#produtoForm").submit();
                } else {
                    $("#statusTxt").html("<p style='color: red'>Preencha todos os campos!</p>")
                }
            }

            function ToggleFiltro(filto){
                window.location="paineldecontrole.php?filtro="+filto;
            }

            function Logout(){
                window.location="logout.php";
            }

        </script>


    </body>


</html>