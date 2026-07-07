<?php
    $nameErr = $emailErr = $phoneErr = "";
    $name = $email = $phone = "";
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (empty($_POST["name"])) {
            $nameErr = "Name is required";
        } 
        else {
            $name = $_POST["name"];
            if (!preg_match("/^[a-zA-Z ]*$/", $name)) {
                $nameErr = "Only letters and spaces allowed";
            }
        }
        if (empty($_POST["email"])) {
            $emailErr = "Email is required";
        } 
        else {
            $email = $_POST["email"];
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                $emailErr = "Invalid email format";
            }
        }
        if (empty($_POST["phone"])) {
            $phoneErr = "Phone number is required";
        } 
        else {
            $phone = $_POST["phone"];
            if (!preg_match("/^[0-9]{10}$/", $phone)) {
                $phoneErr = "Phone must be exactly 10 digits and only be number";
            }
        }
    }
?>
<h2>Form Validation</h2>
<form method="POST" action="">
    Name: <input type="text" name="name" value="<?php echo $name; ?>">
    <span style="color:red;">* <?php echo $nameErr; ?></span>
    <br><br>
    Email: <input type="text" name="email" value="<?php echo $email; ?>">
    <span style="color:red;">* <?php echo $emailErr; ?></span>
    <br><br>
    Phone: <input type="text" name="phone" value="<?php echo $phone; ?>">
    <span style="color:red;">* <?php echo $phoneErr; ?></span>
    <br><br>
    <input type="submit" value="Submit">
</form>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && empty($nameErr) && empty($emailErr) && empty($phoneErr)) {
        echo "<h3>Valid Input:</h3>";
        echo "Name: " . $name . "<br>";
        echo "Email: " . $email . "<br>";
        echo "Phone: " . $phone;
    }
?>