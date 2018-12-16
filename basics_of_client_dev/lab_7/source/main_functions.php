<?php

function get_default_sql_connector(){
	$host = 'kpilabs.io';
    $dbname = 'kpilabs';
    $username = 'kvark';
    $password = 'hellokitty';

    $connection = mysqli_connect($host, $username, $password, $dbname);
    mysqli_set_charset( $connection, 'utf-8');
	return $connection;
}

/*
	"title" => "some text",
	"menu" => "some text",
	"article_title" => "some text",
	"article_text" => "some text",
	"amount_of_additional_articles" => 0,
	"bottom_text" => "some text"
*/
function write_in_db_struct($connector, $data_array){

	$sql_request = "INSERT INTO laba_7_frame (`title`, `menu`, `article_title`, `article_text`, `amount_of_additional_articles`, `bottom_text`) VALUES ('" . $data_array["title"] . "', '" . $data_array["menu"]. "', '".$data_array["article_title"]."', '".$data_array["article_text"]."', '".$data_array["amount_of_additional_articles"]."', '".$data_array["bottom_text"]."')";

	return $connector->query($sql_request) ;
}


/*
	"id" => 0
	"title" => "some text",
	"menu" => "some text",
	"article_title" => "some text",
	"article_text" => "some text",
	"amount_of_additional_articles" => 0,
	"date_of_creation" => data;
	"bottom_text" => "some text"
*/
function get_data_from_db($connector, $id){

	$request = "SELECT * FROM laba_7_frame where id= '$id'";
	//$request = "SELECT * FROM laba_7_frame where id= '0'; CREATE TABLE `kek_table` (`trash_field` VARCHAR(255));";

	//echo $request;

	//$result = $connector->query($request);

	mysqli_multi_query($connector, $request);

	$result = mysqli_store_result($connector);

	if(!$result) {
		return ;
	}

	$line = mysqli_fetch_array($result);

	mysqli_free_result($result);

	return array(
		"id" => $line["id"],
		"title" => $line["title"],
		"menu" => $line["menu"],
		"article_title" => $line["article_title"],
		"article_text" => $line["article_text"],
		"amount_of_additional_articles" => $line["amount_of_additional_articles"],
		"date_of_creation" => $line["create_data"],
		"bottom_text" => $line["bottom_text"]
	);

}


function get_array_of_data_from_n_random_id($connector, $amount){
	
	$request = "SELECT * FROM `laba_7_frame` ORDER BY RAND() LIMIT $amount";

	$result = $connector->query($request);

	if(!$result) {
		return ;
	}

	$for_ret = array();

	if ($result->num_rows > 0) {
		while($row = $result->fetch_assoc()){
			$filtred_row = array(
				"id" => $row["id"],
				"title" => $row["title"],
				"menu" => $row["menu"],
				"article_title" => $row["article_title"],
				"article_text" => $row["article_text"],
				"amount_of_additional_articles" => $row["amount_of_additional_articles"],
				"date_of_creation" => $row["create_data"],
				"bottom_text" => $row["bottom_text"]
			);

			array_push($for_ret, $filtred_row);
		}
	}

	return $for_ret;

}


function validate_text(string $text){
	return strlen($text) >= 1;
}

function validate_number( int $number){
	return $number >= 0;
}

?>