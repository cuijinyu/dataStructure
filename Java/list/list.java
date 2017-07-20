package chain;
public class Node{
	public Node next;
	public int data;
	public Node(int data){
		this.data=data;
	}
	public void display(){
		System.out.println(this.data);
	}
}
public class List {
	private Node headNode;
	private Node lastNode;
	private int length;
	public List(){
		this.headNode=null;
		this.lastNode=null;
	};
	public boolean addNode(Node newNode){
		if(headNode==null){
			this.headNode=newNode;
			this.lastNode=this.headNode;
			length++;
		}else{
			this.lastNode.next=newNode;
			this.lastNode=newNode;
			length++;
		}return true;
	};
	public boolean insertNode(int i,Node p){
		if(p==null){
			return false;
		}else{
			Node myNode=new Node(i);
			myNode.next=p.next;
			p.next=myNode;
			if(myNode.next==null){
				lastNode=myNode;
			}
			length++;
		}return true;
	}
	public boolean clearList(){
		Node myNode=this.headNode;
		if(myNode==null){
			return true;
		}else{
			myNode=null;
			myNode=this.headNode.next;
			while(this.headNode.next!=null){
				myNode=null;
				myNode=this.headNode.next;
				length--;
			}
			return true;
		}
	}
	public boolean clearNode(Node p){
		Node myNode=new Node(0);
		myNode=this.headNode;
		while(myNode.next!=p){
			myNode=myNode.next;
			 if(myNode.next==null){
				 return false;
			 }
		}
		if(myNode.next==p){
			myNode.next=p.next;
			p=null;
			this.length--;
			return true;
		}else{
			return false;
		}
	}
	public int listLength(){
		return this.length;
	}
	public boolean isEmpty(){
		if(this.length==0){
			return true;
		}else{
			return false;
		}
	}
	public boolean tranfser(){
		Node myNode=new Node(0);
		myNode=this.headNode;
		while(myNode!=null){
			myNode.display();
			myNode=myNode.next;
		}return true;
	}
	public static void main(String args[]){
		List test1=new List();
		Node node1=new Node(1);
		Node node2=new Node(2);
		test1.addNode(node1);
		test1.addNode(node2);
		test1.tranfser();
	}
}
