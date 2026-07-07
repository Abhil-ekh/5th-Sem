<?php
    $conn = new mysqli("localhost", "root", "", "labassignment1");
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "UPDATE student 
            SET address = 'Dallu' 
            WHERE name = 'Suresh'";
    if ($conn->query($sql) === TRUE) {
        echo "Data updated successfully";
    } 
    else {
        echo "Error updating record: " . $conn->error;
    }
    $conn->close();
?>