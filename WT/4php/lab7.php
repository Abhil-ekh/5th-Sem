<?php
    $conn = new mysqli("localhost", "root", "", "labassignment1");
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT * FROM student";
    $result = $conn->query($sql);
    echo "<h2>Student Records</h2>";
    if ($result->num_rows > 0) {
        echo "<table border='1' cellpadding='10'>
                <tr>
                    <th>Roll</th><th>Name</th><th>Address</th><th>Contact</th>
                </tr>";
        while($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>".$row["roll"]."</td><td>".$row["name"]."</td><td>".$row["address"]."</td><td>".$row["contact"]."</td>
                </tr>";
        }
        echo "</table>";
    } 
    else {
        echo "No records found";
    }
    $conn->close();
?>