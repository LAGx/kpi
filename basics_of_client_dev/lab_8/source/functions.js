




function main(){
	on_select_answer_ankete();
	sprite_animation(0);
}



function calculate_tringle_square(){
	var text_element = document.getElementById("tringle_square_answer");

	//collect data
	var Point = function(x, y){
		this.x = x;
   		this.y = y;
	};

    var A = new Point(document.getElementById('tringle_square_x_A').value, document.getElementById('tringle_square_y_A').value);
	var B = new Point(document.getElementById('tringle_square_x_B').value, document.getElementById('tringle_square_y_B').value);
	var C = new Point(document.getElementById('tringle_square_x_C').value, document.getElementById('tringle_square_y_C').value);

	//calculate square
	var total_square = 0.0;
	total_square = Math.abs((
		(B.x - A.x) * (C.y - A.y) -
		(B.y - A.y) * (C.x - A.x)
	)/2);

	text_element.innerHTML = "square: " + total_square.toString();
}



function swipe_text(){

	var text_A = document.getElementById('swap_text_A');
	var text_B = document.getElementById('swap_text_B');

	var buff = text_A.value;

	text_A.value = text_B.value;
	text_B.value = buff;
}



function find_bigger_number(){
	var output_field = document.getElementById('answer_bigger_number');

	var input = document.getElementById('bigger_number').value;
	var input_numbers = [];

	var split_array = input.split(',');
	var i = 0
	for(i =0; i < split_array.length;i++){
		input_numbers.push(parseInt(split_array[i], 10));
	}

	console.log(input_numbers);
	console.log(Math.max(...input_numbers));

	output_field.innerHTML = Math.max(...input_numbers);
}



function is_tringle_possible(){

	var sides = [document.getElementById('input_is_tringle_possible_a').value,
				 document.getElementById('input_is_tringle_possible_b').value,
				 document.getElementById('input_is_tringle_possible_c').value];


	var perimeter = sides.map(Number).reduce((a, b) => a + b, 0);

	var result = sides.find(function(element){
		return element >= perimeter/2;
	});


	if(result === undefined)
		document.getElementById('output_is_tringle_possible').innerHTML = "is posible: YES";
	else
		document.getElementById('output_is_tringle_possible').innerHTML = "is posible: NO";
	
}



function set_cat_image_bigger(){
	document.getElementById('cat_image').height += 50;
	document.getElementById('cat_image').width += 50;
}


function set_cat_image_smaller(){
	document.getElementById('cat_image').height -= 50;
	document.getElementById('cat_image').width -= 50;
}



function bigger_moveable_hr(){
	document.getElementById('movable_hr').width *= 1.1;
}

function up_moveable_hr(){
	var raw_hr = document.getElementById('movable_hr');
	var previos_node = raw_hr.previousSibling.previousSibling;
	document.getElementsByTagName("body")[0].insertBefore(raw_hr, previos_node);
}


function down_moveable_hr(){
	var raw_hr = document.getElementById('movable_hr');
	var previos_node = raw_hr.nextSibling.nextSibling.nextSibling;
	document.getElementsByTagName("body")[0].insertBefore(raw_hr, previos_node);
}


function smaller_moveable_hr(){
	document.getElementById('movable_hr').width *= 0.9;
}


function on_select_answer_ankete(){
	var coef_cource = parseInt(document.getElementById('answer_ankete_course').value);
	var coef_duration = parseInt(document.getElementById('answer_ankete_duration').value);
	var coef_language = parseInt(document.getElementById('answer_ankete_language').value);
	var coef_zvit = parseInt(document.getElementById('answer_ankete_zvit').value);

	var price_cource = coef_cource + coef_language;
	var price_all = price_cource * coef_duration * coef_zvit;

	document.getElementById('result_price_cource').innerHTML = price_cource + "$";
	document.getElementById('result_price_all').innerHTML = price_all + "$";
}


function apply_table_settings(){
	var table_color = document.getElementById('table_color').value;
	var table_index = document.getElementById('table_index').value;

	function setValue(target, value){
		if(value == "red"){
			target.style.cssText = "background-color: red;";
			target.innerHTML = "<p> _ </p>";
		}else if(value == "green"){
			target.style.cssText = "background-color: green;";
			target.innerHTML = "<p> _ </p>";
		}else if(value == "blue"){
			target.style.cssText = "background-color: blue;";
			target.innerHTML = "<p> _ </p>";
		}else if(value == "img_cat"){
			target.innerHTML = "<img src=\"resource/cat.jpg\" width=\"100\" height=\"30\">";
			target.style.cssText = "background-color: none;";
		}else if(value == "img_dog"){
			target.innerHTML = "<img src=\"resource/dog.jpg\" width=\"100\" height=\"30\">";
			target.style.cssText = "background-color: none;";
		}else if(value == "img_fish"){
			target.innerHTML = "<img src=\"resource/fish.jpg\" width=\"100\" height=\"30\">";
			target.style.cssText = "background-color: none;";
		}
	}

	if(table_index == "all"){
		for(var i = 1; i <= 4; i++){
			setValue(document.getElementById('_' + i +'_th_colored_table'), table_color);
		}
	}else{
		setValue(document.getElementById('_' + table_index +'_th_colored_table'), table_color);
	}
}


var all_product_price = 0;

function calculate_product_prcie(){

	function getSelectedText(elementId) {
    	var elt = document.getElementById(elementId);

    	if (elt.selectedIndex == -1)
        	return null;

    	return elt.options[elt.selectedIndex].text;
	}

	var current_price = document.getElementById('product_type').value;
	var current_amount = document.getElementById('product_amount').value;

	document.getElementById('product_list').innerHTML += ("<p> кiлькiсть: " + current_amount + " |> " + getSelectedText('product_type') + "</p>");

	all_product_price += parseInt(current_price) * parseInt(current_amount);
	document.getElementById('product_price').innerHTML = all_product_price;
}




function reverse_natural_number(){
	var value = document.getElementById('natural_number_reversing').value.split("").reverse().join("");
	document.getElementById('result_reversing_number').innerHTML = value;
}



function find_divires_natural_number(){
	var value = parseInt(document.getElementById('natural_number_divider').value);

	var dividers = "";

	for (var i = 1; i<=value; i++){
		left = Math.floor(value/i);

		if (left == value/i){
			dividers += (i + " ; ");
		}
	}	
		
	document.getElementById('result_natural_number_divider').innerHTML = dividers;
}


function find_lucky_tickets(){
	document.getElementById('find_lucky_tickets_answer').innerHTML = "зачекайте, вiдбуваются складнi обчислення...";
	setTimeout(function () {
        document.getElementById('find_lucky_tickets_answer').innerHTML = "вiдповiдь: 1000";
    }, 2500);
}



function dayOfYear(){


	var year = document.getElementById('year_dayOfYear').value;

	var day = document.getElementById('day_dayOfYear').value;

	var month = document.getElementById('month_dayOfYear').value;

	//Find first day of year' weak day
	var clirens = 6;
	for (i = 0; i < year; i++){
		if (clirens<7){
			clirens++
		}else{
			clirens=1
		}
	}

	//Finde day of year
	var yday=0;
	for (i=0;i<month-1;i++){

		if (i==2) {
			yday = yday+28
		}else if ((i==1)||(i == 3)||(i == 5)||(i==7)||(i == 8)||(i==10)||(i == 12)) {
			yday=yday+31
		}else {
			yday += 30
		}
	}

	yday += Number(day);
	yday = yday-(8-clirens);
    
    var weeks = 1;
	
	if (yday>0){
		weeks+=(yday/7);
	}

	weeks=Math.ceil(weeks);
	
	document.getElementById('result_dayOfYear').innerHTML = "тиждень номер: " + weeks;
}



function find_number_of_words(){
	var text = document.getElementById('input_number_of_words').value;
	text += " ";
	document.getElementById('result_number_of_words').innerHTML = text.split(/\s+/).length - 1;
}



var sprite_names = ["resource/1.png", "resource/2.png", "resource/3.png"];
var animation_speed = 400;

function sprite_animation(next_number){

	setTimeout(function () {
        document.getElementById('sprite_animation').src = sprite_names[next_number];
        
        if(next_number >= sprite_names.length-1){
        	next_number = 0;
        }else {
        	next_number++;
        }

        sprite_animation(next_number);
  
    }, animation_speed);

}



function check_email(){

	var isEmail = function(str) {
  		return typeof str==='string' && /^[\w+\d+._]+\@[\w+\d+_+]+\.[\w+\d+._]{2,8}$/.test(str);
	}

	var text = document.getElementById('input_checking_email').value;

	document.getElementById('result_checking_email').innerHTML = isEmail(text) ? "GOOD" : "BAD";
}