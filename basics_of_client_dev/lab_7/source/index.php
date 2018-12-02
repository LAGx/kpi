<html>
<head>

  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />
  <title>Зразок оформлення веб-сторінки</title>

</head>
<body>

  <?php //init region

    include 'main_functions.php';

    $connector = get_default_sql_connector();

    if($connector == false){
      echo "<p style=\"color: red;\">ERROR: can`t connect to database!</p> <br>";
      echo "<p style=\"color: red;\">" . mysqli_connect_error() . "</p>";
      exit();
    }
    
    $main_article = get_data_from_db($connector, isset($_GET["id"]) ? $_GET["id"] : 0 );

    if(!isset($main_article) || empty($main_article) || is_null($main_article)){
      echo "<p style=\"color: red;\">ERROR: does not exist page with such id!</p> <br>";
      exit();
    }

    $additional_articles = get_array_of_data_from_n_random_id($connector, $main_article["amount_of_additional_articles"]);

    if(!isset($additional_articles)){
      echo "<p style=\"color: red;\">ERROR: can`t load additional articles!</p> <br>";
      exit();
    }

  ?> 

  <div id="content">
    <h1>
      <?php 
        echo $main_article["title"];
      ?>
    </h1>

    <ul id="menu">
        <?php 
        
          foreach (explode( ",", $main_article["menu"]) as $iter => $elem){
            echo '<li>';
            echo "<a href=\"#\">$elem</a>";
            echo '</li>';
          }
        
        ?>
        <!--<a href="#">головна</a></li><li><a href="#">архів</a></li><li><a href="#">контакти</a>-->
    </ul>

    <div class="post">

      <div class="details">
        <h2><a href="#"><?php echo $main_article["article_title"]; ?></a></h2>
        <p class="info">опубліковано <?php echo $main_article["date_of_creation"]; ?> у секції <a href="#">загальне</a></p>
      </div>
      
      <div class="body">
        <p><?php echo $main_article["article_text"]; ?></p>
      </div>

      <!--<span class="x"></span>-->
    
    </div>

    <?php 
    
      foreach ($additional_articles as $iter => $elem){
        echo "<div class=\"col\">";
        echo "<h3><a href=\"#\">". $elem['article_title'] ."</a></h3>";
        echo "<p>". substr($elem['article_text'], 0, 200) ."</p>";
        echo "<p class=\"det\">&not; <a href=\"http://kpilabs.io/lab_7/source/index.php?id=".$elem["id"]."\">детальніше</a></p>";
        echo "</div>";
      }

    ?>

    <div id="footer">
      
      <p><?php echo $main_article["bottom_text"]; ?></p>
    </div>
  </div>

</body>
</html>