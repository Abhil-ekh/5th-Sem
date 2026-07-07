<?php
    $conn = new mysqli("localhost", "root", "", "labassignment1");
    if($conn->connect_error) {
        die("Connection error".$conn->connect_error);
    }
    $sql = "CREATE TABLE IF NOT EXISTS student (
        roll INT PRIMARY KEY,
        name VARCHAR(50),
        address VARCHAR(100),
        contact VARCHAR(15)
    )";    
    if ($conn->query($sql) === TRUE) {
        echo "Table 'student' created successfully<br>";
    } 
    else {
        echo "Error creating table: " . $conn->error . "<br>";
    }
    $sql = "INSERT INTO student (roll, name, address, contact)
            VALUES (1, 'Suresh', 'Dallu', '9800000000')";
    if ($conn->query($sql) === TRUE) {
        echo "Data inserted successfully<br>";
    } 
    else {
        echo "Error inserting data: " . $conn->error . "<br>";
    }
    $conn->close();
?>