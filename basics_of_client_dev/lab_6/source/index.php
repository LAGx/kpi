
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>index</title>
	<link type="text/css" rel="stylesheet" href="style.css">
</head>
<body>

<!--format table function block-->
<?php 
	
	function formTable_type1( $line_amount){

		echo "<table border=\"1\">";

		echo "<tr>";
		echo "<td colspan=\"$line_amount\">&nbsp;</td>";			
		echo "</tr>";

		$line_amount--;
		$fourth_cell = 0;

		for($line = 0; $line < $line_amount; $line++ ){
			echo "<tr>";

			$very_difficult_calculations = $line_amount - $line;
			
			$fourth_cell += 2;

			if($fourth_cell == 4){
				echo "<td colspan=\"$very_difficult_calculations\">4</td>";
    			echo "<td rowspan=\"$very_difficult_calculations\">&nbsp;</td>"; 
    			$fourth_cell = 0;
			}else{
				echo "<td colspan=\"$very_difficult_calculations\">&nbsp;</td>";
    			echo "<td rowspan=\"$very_difficult_calculations\">&nbsp;</td>"; 
			}

			echo "</tr>";
		}

		echo "</table>";
	}


	function formTable_type2($line_amount){

		echo "<table border=\"1\">";

		$fourth_cell = 0;

		for($line = 0; $line < $line_amount-1; $line++ ){
			echo "<tr>";

			$very_difficult_calculations = $line_amount - $line;
			
			$fourth_cell += 2;

			if($fourth_cell == 4){
				echo "<td colspan=\"$very_difficult_calculations\">&nbsp;</td>";
    			echo "<td rowspan=\"$very_difficult_calculations\">4</td>"; 
    			$fourth_cell = 0;
			}else{
				echo "<td colspan=\"$very_difficult_calculations\">&nbsp;</td>";
    			echo "<td rowspan=\"$very_difficult_calculations\">&nbsp;</td>"; 
			}

			echo "</tr>";
		}

		echo "<tr>";
		echo "<td >&nbsp;</td>";			
		echo "</tr>";

		echo "</table>";
	}


	function formTable_type3($colunm_amount, $line_amount){
		echo "<table border=\"1\">";

		$fourth_cell = 0;

		//init phase
		echo "<tr>";
		for($colunm = 0; $colunm < $colunm_amount; $colunm++){
			$fourth_cell += 1;

			if($fourth_cell == 4){
				if ($colunm%2 == 0){
					echo "<td>&nbsp;</td>";
				}else{
					echo "<td rowspan=\"2\">4<br/>&nbsp;</td>";
				}

				$fourth_cell = 0;
			}else{
				if ($colunm%2 == 0){
					echo "<td>&nbsp;</td>";
				}else{
					echo "<td rowspan=\"2\">&nbsp;<br/>&nbsp;</td>";
				}
			}

		}
		echo "</tr>";

		

		//main phase
		for($line = 1; $line < $line_amount; $line++){
			echo "<tr>";
			if($line%2 == 1){
				for($colunm = 0; $colunm < $colunm_amount/2; $colunm++){
					$fourth_cell += 1;
					if($fourth_cell == 4){
						echo "<td rowspan=\"2\">4</td>";
						$fourth_cell = 0;
					}
					else{
						echo "<td rowspan=\"2\">&nbsp;</td>";
					}
				}
			}else{
				if($line == $line_amount-1){
					for($colunm = 0; $colunm < ($colunm_amount-1)/2; $colunm++){
						$fourth_cell += 1;
						if($fourth_cell == 4){
							echo "<td rowspan=\"2\">4</td>";
							$fourth_cell = 0;
						}
						else{
							echo "<td rowspan=\"2\">&nbsp;</td>";
						}
					}
				}else{
					for($colunm = 0; $colunm < ($colunm_amount-1)/2; $colunm++){
						$fourth_cell += 1;
						if($fourth_cell == 4){
							echo "<td rowspan=\"2\">4<br/>&nbsp;</td>";
							$fourth_cell = 0;
						}
						else{
							echo "<td rowspan=\"2\">&nbsp;<br/>&nbsp;</td>";
						}
					}
				}
			}
			echo "</tr>";
		}

		echo "</table>";
	}


	function formTable_type4($colunm_amount, $line_amount, $main_offset){
		echo "<table border=\"1\">";

		//genetare data
		$generator_data = [[]];
		for($line = 0; $line < $line_amount; $line++){
			$current_offset = ($line+$main_offset-1)%$main_offset+1;

			
			$generator_data[0][$line] = $current_offset;

			$sum = $current_offset;
			$column_iterator = 1;

			while($sum <= $colunm_amount*$main_offset){				
			
				$generator_data[$column_iterator][$line] = $main_offset;
				$sum += $main_offset;
				$column_iterator++;
			}

			$generator_data[$column_iterator][$line] = $colunm_amount-$sum;
			
		}

		$fourth_cell = 0;

		//use data
		for($line = 0; $line < $line_amount; $line++){
			echo "<tr>";
			for($column = 0; $column < $colunm_amount; $column++ ){
				$curr_cos = $generator_data[$column][$line];
				$curr_pers = 100 * $curr_cos / ($colunm_amount*$colunm_amount-1);
				
				$fourth_cell += 1;
				
				if($fourth_cell == 4){
					echo "<td width=\"$curr_pers%\"  colspan=\"$curr_cos\">4</td>"; 
					$fourth_cell = 0;
				}else{
					echo "<td width=\"$curr_pers%\"  colspan=\"$curr_cos\">&nbsp;</td>";
				}
			}
			echo "</tr>";
		}

		echo "</table>";	
	}
?>

<form action="index.php" method="POST">
	lines:<br>
	<input type="text" name="lines" /><br>
	columns:<br>
	<input type="text" name="columns" /><br><br>
	<input type="submit" />
</form>


<?php

	function get_connection(){
		$host = 'kpilabs.io';
    	$dbname = 'kpilabs';
    	$username = 'kvark';
    	$password = 'hellokitty';
		return mysqli_connect($host, $username, $password, $dbname);
	}

	function insert_good_input_in_database($connection, $lines, $columns){
		$sql = "INSERT INTO laba_6_good (`line`, `column`) VALUES ('$lines', '$columns')";

		if ($connection->query($sql) === TRUE) {
    		echo "<p> write in database...</p><br>";
		} else {
    		echo "<p>Error: " . $sql . "<br>" . $connection->error. "</p><br>";
		}

	}


	function insert_bad_input_in_database($connection, $lines, $columns){
		$sql = "INSERT INTO laba_6_bad (`line`, `column`) VALUES ('$lines', '$columns')";

		if ($connection->query($sql) === TRUE) {
    		echo "<p> write in database...</p><br>";
		} else {
    		echo "<p>Error: " . $sql . "<br>" . $connection->error. "</p><br>";
		}
	}

	
	$valid_lines = 7;
	$valid_col = 7;

	$connection = get_connection();

	if($connection == false){
		echo "<p>ERROR: can`t connect to database!</p> <br>";
		echo "<p>" . mysqli_connect_error() . "</p>";
		exit();
	}

	$lines = $_POST["lines"];
	$columns = $_POST["columns"];	

	echo "<br>";

	if( is_numeric($lines) && is_numeric($columns) ){
		$lines = (int)$lines;
		$columns = (int)$columns;

		if($lines >= 1 && $columns >= 1){
			echo "<p>confirmation was successful:</p><br>";
			$valid_lines = $lines;
			$valid_col = $columns;

			insert_good_input_in_database($connection, $lines, $columns);

		}else{
			echo "<p>confirmation failed: < 1</p><br>";
			insert_bad_input_in_database($connection, $lines, $columns);
		}

	}
	else{
		echo "<p>confirmation failed: NAN</p><br>";
		insert_bad_input_in_database($connection, $lines, $columns);
	}


	echo "<p>lines: $valid_lines </p><br>";
	echo "<p>columns: $valid_lines </p><br><br>";
?>


<p> table 1: </p>
<div>
	<?php 
		formTable_type1($valid_lines);
	?>
</div>

<p> table 2: </p>
<div>
	<?php 
		formTable_type2($valid_lines);
	?>
</div>

<p> table 3: </p>
<div>
	<?php 
		formTable_type3($valid_col , $valid_lines);
	?>
</div>

<p> table 4: </p>
<div>
	<?php 
		formTable_type4($valid_col , $valid_lines, 3);
	?>
</div>

</body>
</html>