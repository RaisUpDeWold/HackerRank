/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle{
protected:
	int width,height;
public:
	void read_input(){scanf("%d%d",&width,&height);}
	void display(){printf("%d %d\n",width,height);}
};
class RectangleArea:public Rectangle{
public:
	void display(){printf("%d\n",width*height);}
};
