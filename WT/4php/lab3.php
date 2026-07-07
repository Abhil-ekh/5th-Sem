<?php
    $num = array(10, 40, 30);
    $num[1] = 50;
    echo "Numeric Array:<br>";
    print_r($num);
    echo "<br><br>";
    $ass = array("name" => "Abhilekh", "age" => 20);
    $ass["age"] = 21;
    echo "Associative Array:<br>";
    print_r($ass);
    echo "<br><br>";
    $multi = array(
        array(1, 2),
        array(5, 4)
    );
    $multi[1][0] = 3;
    echo "Multidimensional Array:<br>";
    print_r($multi);
?>