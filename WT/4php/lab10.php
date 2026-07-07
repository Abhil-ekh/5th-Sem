<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST['name'];
        $address = $_POST['address'];
        echo "<h3>Data received using POST:</h3>";
        echo "Name: " . $name . "<br>";
        echo "Address: " . $address . "<br><br>";
    }
    if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET['name'])) {
        $name = $_GET['name'];
        $address = $_GET['address'];

        echo "<h3>Data received using GET:</h3>";
        echo "Name: " . $name . "<br>";
        echo "Address: " . $address . "<br><br>";
    }
    ?>
    <h2>Student Form</h2>
    <form method="POST" action="">
        <h3>POST Method</h3>
        Name: <input type="text" name="name"><br><br>
        Address: <input type="text" name="address"><br><br>
        <input type="submit" value="Submit via POST">
    </form>
    <br>
    <form method="GET" action="">
        <h3>GET Method</h3>
        Name: <input type="text" name="name"><br><br>
        Address: <input type="text" name="address"><br><br>
        <input type="submit" value="Submit via GET">
</form>