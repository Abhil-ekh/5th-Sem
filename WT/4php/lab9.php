<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "DELETE FROM student WHERE address = 'Lalitpur'";

if ($conn->query($sql) === TRUE) {
    echo "Record(s) deleted successfully";
} else {
    echo "Error deleting record: " . $conn->error;
}

$conn->close();
?>