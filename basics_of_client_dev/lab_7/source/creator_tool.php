<html>
<head>

  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />
  <title>tool for create new page</title>

</head>
<body>

	<H1>tool for creating new page </H1>
	<br>


	<form action="creator_tool_controller.php" method="POST" style="text-align: left; width:90%;">
		
		title:<br>
		<input value="Зразок оформлення веб-сторінки" type="text" name="title" style="text-align: left; width:90%;" /><br><br>
		
		menu (delimit by ","):<br>
		<input value="головна,архів,контакти" type="text" name="menu" style="text-align: left; width:90%;"/><br><br>
		
		article title:<br>
		<input value="Тут щось незрозуміле" type="text" name="article_title" style="text-align: left; width:90%;"/><br><br>

		article text:<br>
		<input value="Тут щось незрозуміле написано, треба розбиратись." type="text" name="article_text" style="text-align: left; width:90%;"/><br><br>

		amount of additional articles:<br>
		<input value="3" type="number" name="amount_of_additional_articles" style="text-align: left; width:90%;"/><br><br>

		bottom text:<br>
		<input value="Copyright &copy; 2018 <em>Koвтyнeць O.B. &laquo;Beб-тexнoлoгiї&raquo;</em>
        &middot; Design: ІП-6х, <a href=&quot;http://asu.kpi.ua/&quot; title=&quot;ACOI KПI&quot;>ACОIУ KПI</a>" type="text" name="bottom_text" style="text-align: left; width:90%;"/><br><br>

		<input type="submit" class="button" name="submit"/>
	</form>


</body>
</html>