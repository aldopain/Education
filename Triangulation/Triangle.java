import java.awt.Point;

public class Triangle {
	Point edge;
	Point a, b;
	int color;
	
	//returns triangles yardage
	int getYardage(){
		return (int) (Math.pow(Math.pow(edge.x - a.x, 2) + Math.pow(edge.y - a.y, 2), 0.5)*Math.pow(Math.pow(edge.x - b.x, 2) + Math.pow(edge.y - b.y, 2), 0.5));
	}
	
	Triangle(Point e, Point f, Point s){
		edge = e;
		a = f;
		b = s;
	}
	
	//sets color, basing on brightnesses of all pixels in triangle
	void setColor(TrImage img){
		int br = 0;
		int xMin = TrMath.getMinOrMax(a.x, b.x, edge.x, 0),
		xMax = TrMath.getMinOrMax(a.x, b.x, edge.x, 1),
		yMin = TrMath.getMinOrMax(a.y, b.y, edge.y, 0),
		yMax = TrMath.getMinOrMax(a.y, b.y, edge.y, 1);
		int count = 0;
		for(int i = yMin; i <= yMax && i < img.size; i++)
			for(int j = xMin; j <= xMax && j < img.size; j++)
				if(isPointInTriangle(j, i)){
					br += img.brMatrix[i][j];
					count++;
				}
		br = br/count;
		color = TrColor.getColor(br, br, br);
	}
	
	//returns true, if triangle needs to be separated
	boolean isSeparatable(TrImage img, int limit){
		int xMin, xMax, yMin, yMax;
		xMin = TrMath.getMinOrMax(a.x, b.x, edge.x, 0);
		xMax = TrMath.getMinOrMax(a.x, b.x, edge.x, 1);
		yMin = TrMath.getMinOrMax(a.y, b.y, edge.y, 0);
		yMax = TrMath.getMinOrMax(a.y, b.y, edge.y, 1);
		for(int i = yMin; i <= yMax && i < img.size; i++)
			for(int j = xMin; j <= xMax && j < img.size; j++)
				if(this.isPointInTriangle(j, i) && Math.abs(img.brMatrix[edge.y][edge.x] - img.brMatrix[i][j]) > limit)
					return true;
		return false;
	}
	
	/*
	 * returns true, if point is in triangle
	 * formula:
	(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
	(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
	(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
	*/
	boolean isPointInTriangle(int x, int y){
		int c1, c2, c3;
		c1 = TrMath.sgn((edge.x - x)*(a.y - edge.y)-(a.x - edge.x)*(edge.y - y));
		c2 = TrMath.sgn((a.x - x)*(b.y - a.y)-(b.x - a.x)*(a.y - y));
		c3 = TrMath.sgn((b.x - x)*(edge.y - b.y)-(edge.x - b.x)*(b.y - y));
		if(c1 == c2 && c2 == c3)
			return true;
		if(c1 == 0 && c2 == c3 || c1 == c3 && c2 == 0 || c3 == 0 && c1 == c2)
			return true;
		if(x == a.x && y == a.y || x == b.x && y == b.y || x == edge.x && y == edge.y)
			return true;
		return false;
	}
}
