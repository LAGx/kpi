<html>
<head>

  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />
  <title>tool for create answer</title>

</head>
<body>

	<H1>Result: </H1>

	
	<form action="creator_tool.php" method="POST" style="text-align: left; width:90%;">
		<input type="submit" class="button" name="submit" value="<- back" />
	</form>


	<?php //init region

		include 'main_functions.php';

		$connector = get_default_sql_connector();

		if($connector == false){
			echo "<p style=\"color: red;\">ERROR: can`t connect to database!</p> <br>";
			echo "<p style=\"color: red;\">" . mysqli_connect_error() . "</p>";
			exit();
		}
	?> 

	<?php //validate values region


		$data = array(
			"title" => $_POST["title"],
			"menu" => $_POST["menu"],
			"article_title" => $_POST["article_title"],
			"article_text" => $_POST["article_text"],
			"amount_of_additional_articles" => $_POST["amount_of_additional_articles"],
			"bottom_text" => $_POST["bottom_text"]
		);

		$what_error = "";

		if(!validate_text($data["title"])){
			$what_error = "title";
		}
		if(!validate_text($data["menu"])){
			$what_error = "menu";
		}
		if(!validate_text($data["article_title"])){
			$what_error = "article_title";
		}
		if(!validate_text($data["article_text"])){
			$what_error = "article_text";
		}
		if(!validate_number($data["amount_of_additional_articles"])){
			$what_error = "amount_of_additional_articles";
		}
		if(!validate_text($data["bottom_text"])){
			$what_error = "bottom_text";
		}

		if($what_error != ""){
			echo "<p style=\"color: red;\">ERROR: invalid input field: $what_error</p>";
			exit();
		}

	
		$result = write_in_db_struct($connector, $data);

		if($result == false){
			$result_info = "<p style=\"color: red;\">ERROR: can`t write data in database: ".$connector->error. "</p>";
		}else{
			$result_info = "<p style=\"color: green;\">INFO: operation was complete with succsess</p>";
		}


		echo $result_info;

	?>


</body>
</html>