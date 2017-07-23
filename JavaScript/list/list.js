function Node(data){
	this.data=data;
	this.next="";
}


function List(){
	var node="",
		headNode="",
		lastNode="",
		length=0;
	this.addNode=function(data){
		node=new Node(data);
		if(lastNode===""){
			lastNode=node;
			headNode=node;
			length++;
		}else{
			lastNode.next=node;
			lastNode=node;
			length++;
		}
	};
	this.clearList=function(){

	};
	this.transval=function(){
		node=headNode;
		while(node!==""){
		console.log(node.data);
		node=node.next;
		}
	};
	this.listLength=function(){
		console.log(length);
	};
	this.listInsert=function(){

	};
	this.isEmpty=function(){
		if(length===0){
			console.log("The list is empty");
		}else{
			console.log("The list is not empty");
		}
	};
}

var listTest=new List();
listTest.addNode(20);
listTest.addNode(20);
listTest.addNode(20);
listTest.transval();
listTest.isEmpty();
listTest.listLength();