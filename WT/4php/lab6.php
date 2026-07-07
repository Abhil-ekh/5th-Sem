<?php
    $conn = new mysqli("localhost", "root", "", "labassignment1");
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "INSERT INTO student (roll, name, address, contact) VALUES
    (2, 'Suresh', 'Bhaktapur', '9800000001'),
    (3, 'Ram', 'Kathmandu', '9800000002'),
    (4, 'Hari', 'Pokhara', '9800000003'),
    (5, 'Gita', 'Lalitpur', '9800000004'),
    (6, 'Sita', 'Bhaktapur', '9800000005'),
    (7, 'Ramesh', 'Biratnagar', '9800000006'),
    (8, 'Suresh', 'Butwal', '9800000007'),
    (9, 'Kiran', 'Lalitpur', '9800000008'),
    (10, 'Mina', 'Dharan', '9800000009'),
    (11, 'Bikash', 'Lalitpur', '9800000010')";

    if ($conn->query($sql) === TRUE) {
        echo "10 records inserted successfully";
    } else {
        echo "Error: " . $conn->error;
    }

    $conn->close();
?>