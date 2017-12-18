var MAX = 100000;
var vertex_number = 13;
var edge_number = 20;
function Create2DArray(rows){
	var arr = [];
	for(var i = 0; i < rows; i++){
		arr[i] = [];
	}

	return arr;
}

var map = Create2DArray(MAX);
var auto = Create2DArray(MAX);//存储是否可以给汽车通过
var map_road = Create2DArray(MAX);
for(var i = 0; i <= vertex_number; i++){
	for(var j = 0; j <= vertex_number; j++){
		map[i][j] = MAX;
	}
}
//reference
var reference = [];
reference["计院楼"] = 1;
reference["北门"] = 2;
reference["停车棚"] = 3;
reference["行政楼"] = 4;
reference["公教楼"] = 5;
reference["图书馆"] = 6;
reference["传设院"] = 7;
reference["体育馆"] = 8;
reference["真草"] = 9;
reference["工学院广场"] = 10;
reference["假草"] = 11;
reference["快递点"] = 12;
reference["新活"] = 13;
//store spot info
var spot = [];
spot[1] = ["计院楼" ,"计算机学院行政和学术活动地点"];
spot[2] = ["北门","中大牌坊"];
spot[3] = ["停车棚","超多小黄！"];
spot[4] = ["行政楼","办公、吃饭"];
spot[5] = ["公教楼","上课的地方"];
spot[6] = ["图书馆","借阅、自习"];
spot[7] = ["传设院","传播与设计学院"];
spot[8] = ["体育馆","打羽毛球"];
spot[9] = ["真草","上体育课的地方"];
spot[10] = ["工学院广场","许多院学生会迎新选地"];
spot[11] = ["假草","跑步的地方"];
spot[12] = ["快递点","收发快递"];
spot[13] = ["新活","学生活动中心"];

//simplify?
map[1][2] = 247;
map[2][1] = 247;
auto[1][2] = auto[2][1] = 1;
map_road[1][2] = map_road[2][1] = "R1";
map[1][3] = 490;
map[3][1] = 490;
auto[1][3] = auto[3][1] = 1;
map_road[1][3] = map_road[3][1] = "R9";
map[2][4] = 313;
map[4][2] = 313;
auto[2][4] = auto[4][2] = 1;
map_road[2][4] = map_road[4][2] = "R2";
map[2][5] = 317;
map[5][2] = 317;
auto[2][5] = auto[5][2] = 1;
map_road[2][5] = map_road[5][2] = "R3";

// map[3][4] = 349;
// map[4][3] = 349;
// auto[3][4] = auto[4][3] = 1;

// //meiyoulu
// map_road[3][4] = map_road[4][3] = "R5";

map[8][3] = 525;
map[3][8] = 525;
auto[8][3] = auto[3][8] = 1;
map_road[8][3] = map_road[3][8] = "R8";

map[5][4] = 132;
map[4][5] = 132;
auto[4][5] = auto[5][4] = 1;
map_road[5][4] = map_road[4][5] = "R4";

map[6][4] = 233;
map[4][6] = 233;
auto[6][4] = auto[4][6] = 1;
map_road[6][4] = map_road[4][6] = "R5";

map[4][10] = 744;
map[10][4] = 744;
auto[10][4] = auto[4][10] = 1;
map_road[4][10] = map_road[10][4] = "R15";
map[5][6] = 167;
map[6][5] = 167;
auto[5][6] = auto[6][5] = 0;
//r4r6repeat
map_road[5][6] = map_road[6][5] = "R6";
map[6][7] = 397;
map[7][6] = 397;
auto[6][7] = auto[7][6] = 1;
map_road[6][7] = map_road[7][6] = "R13";
map[6][8] = 219;
map[8][6] = 219;
auto[6][8] = auto[8][6] = 1;
map_road[6][8] = map_road[8][6] = "R7";
map[7][10] = 286;
map[10][7] = 286;
auto[7][10] = auto[10][7] = 1;
map_road[7][10] = map_road[10][7] = "R14";
map[7][11] = 224;
map[11][7] = 224;
auto[7][11] = auto[11][7] = 1;
map_road[7][11] = map_road[11][7] = "R12";
map[8][9] = 209;
map[9][8] = 209;
auto[8][9] = auto[9][8] = 1;
map_road[8][9] = map_road[9][8] = "R10";
map[8][11] = 298;
map[11][8] = 298;
auto[8][11] = auto[11][8] = 0;
map_road[8][11] = map_road[11][8] = "R11";
map[12][8] = 397;
map[8][12] = 397;
auto[12][8] = auto[8][12] = 1;
map_road[12][8] = map_road[8][12] = "R20";
map[13][8] = 639;
map[8][13] = 639;
auto[13][8] = auto[8][13] = 1;
map_road[13][8] = map_road[8][13] = "R16";
map[13][10] = 816;
map[10][13] = 816;
auto[13][10] = auto[10][13] = 0;
map_road[13][10] = map_road[10][13] = "R18";
map[12][11] = 449;
map[11][12] = 449;
auto[12][11] = auto[11][12] = 1;
map_road[12][11] = map_road[11][12] = "R19";
map[13][12] = 535;
map[12][13] = 535;
auto[13][12] = auto[12][13] = 1;
map_road[13][12] = map_road[12][13] = "R17";



var store_path_str = Create2DArray(MAX);
var store_path_str_word = Create2DArray(MAX);
var shortest_length = Create2DArray(MAX);
var store_path_str_auto = Create2DArray(MAX);
var store_path_str_auto_word = Create2DArray(MAX);
var shortest_length_auto = Create2DArray(MAX);

var store_path_road = Create2DArray(MAX);
var store_path_road_auto = Create2DArray(MAX);

$("#find-path-people").click(function(){
	$("#map-pic").find("div").attr("class", "hide");
	var from = reference[$("#start").val()];
	var to = reference[$("#end").val()];
	console.log("起始", $("#start").val());
	console.log("终点", $("#end").val());

	if (from === undefined || to === undefined)
		$("#info").text("请输入有效地点名称");
	else{
		find_shortest_path(from, to);

		var test_tmp;
		test_tmp = store_path_str[from][to].split("->");
		$("#info").text("步行路线 ：" + store_path_str_word[from][to] + ", 共 " + shortest_length[from][to] + " 米");

		console.log("步行路线 ：", store_path_str_word[from][to]);

		store_path_road[from][to] = [];
		for(var i = 0; i < test_tmp.length-1; i++){
			
			console.log(map_road[test_tmp[i]][test_tmp[i+1]]);
			store_path_road[from][to].push(map_road[test_tmp[i]][test_tmp[i+1]]);
		}
		
		console.log(store_path_road[from][to]);
		console.log(test_tmp);

		//路线显示部分
		/*for(var h = 0; h < store_path_road[from][to].length; h++){
			var str_id = "#" + store_path_road[from][to][h];
			//$(str_id).removeClass("hide").removeClass("auto").addClass("walk");
			$(str_id).attr("class", "walk");
			console.log(str_id);
		}*/
		
		var h = 0;
		(function looper() {
	    if( h < store_path_road[from][to].length ) {
	        var str_id = "#" + store_path_road[from][to][h];
	        //$(str_id).removeClass("hide").removeClass("auto").addClass("walk");
	        $(str_id).attr("class", "walk");
	        h++;
	        setTimeout(looper, 1000);
	    }
		})();
	}
});

$("#find-path-car").click(function(){
	$("#map-pic").find("div").attr("class", "hide");
	console.log("----auto part-------");
	var from = reference[$("#start").val()];
	var to = reference[$("#end").val()];
	console.log($("#start").val());
	console.log($("#end").val());


	find_shortest_path(from, to);
	if(!store_path_road_auto[from][to]){
		var test_tmp;
		test_tmp = store_path_str_auto[from][to].split("->");
		//console.log("hh"+test_tmp.length);
		store_path_road_auto[from][to] = [];
		for(var i = 0; i < test_tmp.length-1; i++){
			
			console.log(map_road[test_tmp[i]][test_tmp[i+1]]);
			store_path_road_auto[from][to].push(map_road[test_tmp[i]][test_tmp[i+1]]);
		}	
	}
	else{
		console.log("already split");
	}
	$("#info").text("车行路线 ：" + store_path_str_auto_word[from][to]);
	
	
	console.log(store_path_road_auto[from][to]);
	console.log(test_tmp);
	// 路线显示部分
	// var t;
	/*for(var h = 0; h < store_path_road_auto[from][to].length; h++){
		var str_id = "#" + store_path_road_auto[from][to][h];
		var content = document.getElementById(store_path_road_auto[from][to][h]);

		//sleep(1000, function(){content.className="auto";});
		$(str_id).removeClass("hide").removeClass("walk").addClass("auto");
		console.log(str_id);
		
	}*/
	var h = 0;
	(function looper() {
    if( h < store_path_road_auto[from][to].length ) {
        var str_id = "#" + store_path_road_auto[from][to][h];
        $(str_id).removeClass("hide").removeClass("walk").addClass("auto");
        h++;
        setTimeout(looper, 1000);
    }
	})();
	console.log("---------------------");

});

//find_shortest_path(1, 5);

function find_shortest_path(start, end){
	console.log(start, end, store_path_str);
	if(start == undefined)
		console.log("store_path_str undefined", store_path_str);
	else {
	if(store_path_str[start][end]){  
		console.log("already have");
		console.log("Final:" + store_path_str[start][end]);
		console.log("length: " + shortest_length[start][end]);
		console.log("Final car:" +store_path_str_auto[start][end]);
		console.log("length: " + shortest_length_auto[start][end]); 
		return;}
	var source = start;
	var target = end;
	var visited = [];
	var dis = [];
	var dis2 = [];
	var visited2 = [];
	//load the distance into dis array
	for(var i = 1; i <= vertex_number; i++){
		dis[i] = map[source][i];
		console.log("dis["+i+"] "+dis[i]);
		if(auto[source][i]){
			dis2[i] = map[source][i];
		}
		else{
			dis2[i] = MAX;
		}
	}
	visited[source] = 1;
	visited2[source] = 1;
	console.log(visited[2]);
	console.log(!!(visited[2]));
	console.log(!(visited[2]));
	var rec = 0;
	var rec2 = 0;
	for(var i = 1; i <= vertex_number; i++){
		var min = MAX;
		var min2 = MAX;
		for(var j = 1; j <= vertex_number; j++){
			if(!(visited[j]) && dis[j] < min){
				rec = j;
				min = dis[j];
			}
			if(!(visited2[j]) && dis2[j] < min2){
				rec2 = j;
				min2 = dis2[j];
			}
		}
		//got the min
		console.log("rec "+rec);
		console.log("rec2 " + rec2);
		visited[rec] = 1;
		visited2[rec2] = 1;
		if(map[source][rec] && !(store_path_str[source][rec])){
			var str_tmp = "";
			//console.log(source);
			str_tmp += source;
			str_tmp += "->";
			str_tmp += rec;
			store_path_str[source][rec] = str_tmp;
			store_path_str_word[source][rec] = spot[source][0] + "->" + spot[rec][0];
			//console.log("look at me!");
			console.log(store_path_str_word[source][rec]);
			shortest_length[source][rec] = map[source][rec];
			console.log("walk shortest_length " + shortest_length[source][rec]);
			console.log("hh" + store_path_str[source][rec]);
		}
		if(map[source][rec2] && !(store_path_str_auto[source][rec2])){
			var str_tmp = "";
			str_tmp += source;
			str_tmp += "->";
			str_tmp += rec2;
			store_path_str_auto[source][rec2] = str_tmp;
			shortest_length_auto[source][rec2] = map[source][rec2];
			store_path_str_auto_word[source][rec] = spot[source][0] + "->" + spot[rec2][0];
			//console.log("look at me!");
			console.log(store_path_str_auto_word[source][rec2]);
			console.log("auto shortest_length " + shortest_length[source][rec2]);
			console.log("auto" + store_path_str_auto[source][rec2]);

		}

		for(var k = 1; k <= vertex_number; k++){
			// console.log("vec ")
			// console.log("visited[7] " +visited[7]);
			// console.log("dis[7] " + dis[7]);
			// console.log(map[rec][k]+min)
			if(!visited[k] && dis[k] > map[rec][k]+min){
				dis[k] = map[rec][k] + min;
				var str_tmp = store_path_str[source][rec];
				str_tmp += "->";
				str_tmp += k;
				store_path_str[source][k] = str_tmp;
				store_path_str_word[source][k] = store_path_str_word[source][rec] + "->" + spot[k][0];
				console.log(store_path_str_word[source][k]);
				shortest_length[source][k] = dis[k];
				console.log(store_path_str[source][k]);
			}
			if(!visited2[k] && dis2[k] > map[rec2][k] + min2 && auto[rec2][k]){
				dis2[k] = map[rec2][k] + min2;
				var str_tmp = store_path_str_auto[source][rec2];
				str_tmp += "->";
				str_tmp += k;
				store_path_str_auto_word[source][k] = store_path_str_auto_word[source][rec2] + "->" + spot[k][0];
				console.log(store_path_str_auto_word[source][k]);
				shortest_length_auto[source][k] = dis2[k];
				store_path_str_auto[source][k] = str_tmp;
				console.log("auto " + store_path_str_auto[source][k]);
			}
		}
	}

	console.log("Final:" + store_path_str[source][target]);
	console.log("人："+ store_path_str_word[source][target]);
	console.log("length: " + shortest_length[source][target]);
	console.log("Final car:" +store_path_str_auto[source][target]);
	console.log("车："+store_path_str_auto_word[source][target]);
	console.log("length: " + shortest_length_auto[source][target]);
}

}


function sleep(n, callback){
	//$(str).attr("class", "auto");
 var start=new Date().getTime();//定义起始时间的毫秒数
 while(true){
  var time=new Date().getTime();//每次执行循环取得一次当前时间的毫秒数
  if(time-start>n){//如果当前时间的毫秒数减去起始时间的毫秒数大于给定的毫秒数，即结束循环
   callback();
   break;
  }
 }
}

$("#find-spot").click(function(){
	if($("#query").val() == "") return ;
	var str = spot[reference[$("#query").val()]][0] + " " + spot[reference[$("#query").val()]][1];
	$("#info").text(str);
	console.log(spot[reference[$("#query").val()]][0]);
	console.log(spot[reference[$("#query").val()]][1]);

});