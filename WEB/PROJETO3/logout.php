<?php 

    session_start();
    unset($_SESSION["USER_LOG"]);

    header("Location: index.php");

?>