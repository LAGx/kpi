


function main(){
	(function($, undefined){
		
		process_task_1();

		process_task_2();

		process_task_3();

		process_task_4();

	})(jQuery);	
}


function parcePixel(value){
	return parseInt(value.replace(/px/,""));
}

function process_task_1(){

	$("#table_1 >>>> td").html("<p>текст у клітинці</p>");
	$("#table_1 >>>> td > p").css("margin","0px");

	$("#table_1 >>>> td[colspan]").not("[colspan=1]").children().css("color", "red");

	var current_text_size = $("#table_1 >>>> td[rowspan]").not("[rowspan=1]").children().css("font-size");
	$("#table_1 >>>> td[rowspan]").not("[rowspan=1]").children().css("font-size", parcePixel(current_text_size)*2 + "px");
}



function process_task_2(){
	$("#table_3 >>>> td").html("<p>текст у клітинці</p>");
	$("#table_3 >>>> td > p").css("margin","0px");

	$("#table_3 > table").css("background-color", "blue");

	$("#table_3 >>> tr").each(function(index){
		if((index % 3) == 0){
			$(this).css("font-style", "italic");
		}else{
			$(this).css("font-style", "bold");
		}
	});

	$("#table_3 >>> tr").each(function(index){
		if(index >= 3){
			$(this).find("p").html($(this).find("p").text().toUpperCase());
		}
	});
}


function process_task_3(){
	$("#table_4 >>> :first-child > td").html("<pre>текст у клітинці</pre>");

	$("#table_4 >>> :first-child > td").each(function(index){
		if((index % 2) == 0){
			$(this).find("pre").css("color", "green");
		}
	});

	$("#table_4 >>> :first-child > td").eq(2).html($("#table_4 >>> :first-child > td").eq(2).html() + "<hr>");
}


function process_task_4(){
	
	$("#table_4 >>> :last-child > td:first-child").html( 
		"<ul>" +
			"<li>1 рядок</li>" +
			"<li>2 рядок</li>" +
			"<li>3 рядок</li>" +
			"<li>4 рядок</li>" +
		"</ul>");


	$("#table_4 >>> :last-child > td:first-child >> li").each(function(index){
		alert($(this).text());
	});

}