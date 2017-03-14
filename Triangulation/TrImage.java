import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import javax.imageio.ImageIO;

public class TrImage {
	int[][] brMatrix;	//matrix of pixel brightnesses
	private Queue<Triangle> triangleQ = new LinkedList<Triangle>();	//queue of triangles
	int size;	//pixel size of image (size*size)
	int limit;	//maximal difference of brghtnesses
	
	TrImage(int s, int l){
		size = s;
		limit = l;
	}
	
	//resizes originalImage to the chosen size (now only rectangles)
	BufferedImage resizeImage(BufferedImage originalImage){
		BufferedImage resizedImage = new BufferedImage(size, size, BufferedImage.TYPE_INT_RGB);
		Graphics2D g = resizedImage.createGraphics();
		g.drawImage(originalImage, 0, 0, size, size, null);
		g.dispose();
		return resizedImage;
	}
	
	//gets matrix of brightnesses from the image in path
	void getMatrix(String path) throws IOException{
		BufferedImage img = ImageIO.read(new File(path));
		img = resizeImage(img);
		brMatrix = new int[size][size];
		for( int i = 0; i < size; i++ ){
		    for( int j = 0; j < size; j++ ){
		    	brMatrix[i][j] = TrColor.getBrightness(img.getRGB(j, i));
		    }
		}
	}
	
	//triangulates (obviously) this TrImage object
	BufferedImage triangulate(){
		Stack<Triangle> q = new Stack<Triangle>();
		Triangle f = new Triangle(new Point(0, 0), new Point(0, 2*size), new Point(2*size, 0));
		if(f.isSeparatable(this, limit)){
			q.add(new Triangle(new Point(0,0), new Point(0,size-1), new Point(size-1,0)));
			q.add(new Triangle(new Point(size-1, size-1), new Point(0,size-1), new Point(size-1,0)));
		}
		while(!q.isEmpty()){
			Triangle current = q.pop();
			if(current.isSeparatable(this, limit) && current.getYardage() > 2){
				Point nEdge = new Point((current.a.x + current.b.x)/2,(current.a.y + current.b.y)/2);
				q.add(new Triangle(nEdge, current.edge, current.a));
				q.add(new Triangle(nEdge, current.edge, current.b));
			}else{
				current.setColor(this);
				triangleQ.add(current);
			}
			
		}
		return drawTriangles();
	}
	
	//draws (im not joking!) triangles in triangleQ
	BufferedImage drawTriangles(){
		BufferedImage bi = new BufferedImage(size, size, BufferedImage.TYPE_INT_RGB);
		while(!triangleQ.isEmpty()){
			Triangle current = triangleQ.poll();
			int xMin, xMax, yMin, yMax;
			xMin = TrMath.getMinOrMax(current.a.x, current.b.x, current.edge.x, 0);
			xMax = TrMath.getMinOrMax(current.a.x, current.b.x, current.edge.x, 1);
			yMin = TrMath.getMinOrMax(current.a.y, current.b.y, current.edge.y, 0);
			yMax = TrMath.getMinOrMax(current.a.y, current.b.y, current.edge.y, 1);
			for(int i = yMin; i <= yMax && i < size; i++)
				for(int j = xMin; j <= xMax && j < size; j++)
					if(current.isPointInTriangle(j, i)){
						bi.setRGB(j, i, current.color);
					}
			}
		return bi;
	}
}
