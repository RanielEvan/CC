<?php 

    $_SESSION["Status"] = ".";

?>

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

        /* BG 'ANIMADO' */
        body {
            margin: 0;
            width: 100%;
            height: 100vh;
            background: linear-gradient(-45deg, rgb(59, 214, 212), rgb(26, 99, 128),#31519b,#100e7c);
            background-size: 400% 400%;
            animation: gradientBG 10s ease infinite;
        }

        @keyframes gradientBG {
            0% {
                background-position: 0% 50%;
            }
            50% {
                background-position: 100% 50%;
            }
            100% {
                background-position: 0% 50%;
            }
        }
    </style>
</head>

<body style="background-color: darkgreen">
    <!-- PLAYER -->
    <div id="player" style="position: relative; top: 50px; left: 50px; box-shadow: 0px 5px 4px; border-radius: 50%; height: 20px; width: 20px; background-image: linear-gradient(#00F260, #0575E6)"></div>

    <main class="text-center">
        <h2 style="text-shadow: 0px 5px 5px gray">BEM VINDO MEU QUERIDO!</h2>
        <h3>De <b>Painel de Controle</b> aqui, não tem é nada!</h3>
        <h4>Mas deixo uma parada bem interessante.. Aperte W-A-S-D ai!</h4>

    </main>


    <a href="../index.html" class="btn btn-warning ml-3 mb-3">Quero ir embora daqui agora pelo amor de Deus!</a> 

    <script>

        var up = false,
            right = false,
            down = false,
            left = false,
            x = window.innerWidth/2-130/2,
            y = window.innerHeight/2-130/2


        x = 669;
        y = 377;
        document.addEventListener('keydown',press)
        function press(e){
            if (e.keyCode === 38 /* up */ || e.keyCode === 87 /* w */){
                up = true
            }
            if (e.keyCode === 39 /* right */ || e.keyCode === 68 /* d */){
                right = true
            }
            if (e.keyCode === 40 /* down */ || e.keyCode === 83 /* s */){
                down = true
            }
            if (e.keyCode === 37 /* left */ || e.keyCode === 65 /* a */){
                left = true
            }
        }

        document.addEventListener('keyup',release)
        function release(e){
            if (e.keyCode === 38 /* up */ || e.keyCode === 87 /* w */ || e.keyCode === 90 /* z */){
                up = false
            }
            if (e.keyCode === 39 /* right */ || e.keyCode === 68 /* d */){
                right = false
            }
            if (e.keyCode === 40 /* down */ || e.keyCode === 83 /* s */){
                down = false
            }
            if (e.keyCode === 37 /* left */ || e.keyCode === 65 /* a */ || e.keyCode === 81 /* q */){
                left = false
            }
        }

        function gameLoop(){
            var div = document.querySelector('div')
            if (up){
                y = y - 5
            }
            if (right){
                x = x + 5
            }
            if (down){
                y = y + 5
            }
            if (left){
                x = x - 5
            }
            div.style.left = x+'px'
            div.style.top = y+'px'
            window.requestAnimationFrame(gameLoop)
        }

        window.requestAnimationFrame(gameLoop)

    </script>


    <!-- SCRIPTS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    

</body>
</html>