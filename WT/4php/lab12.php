<?php
    setcookie("user", "Psy", time() + 5000); 
    echo "Cookie is set!";
    session_start();
    $_SESSION["user"] = "Psy";
    $_SESSION["age"] = 21;
    echo "Session is set!";
?>