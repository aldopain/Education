import java.awt.image.BufferedImage;

public class TrColor {
	static int getColor(int brightness){
		return (brightness << 16) + (brightness << 8) + brightness;
	}
	
	static int getColor(int r, int g, int b){
		return (r << 16) + (g << 8) + b;
	}
	
	static int getBrightness(int rgb){
		return (int)(0.299*getRed(rgb) + 0.587*getGreen(rgb) + 0.114*getBlue(rgb));
	}
	
	private static int getRed(int rgb){
		return (rgb >> 16) & 0xFF;
	}
	
	private static int getGreen(int rgb){
		return (rgb >> 8) & 0xFF;
	}
	
	private static int getBlue(int rgb){
		return rgb & 0xFF;
	}
	
	static int getPixelColor(BufferedImage bi ,int x, int y){
		int buf = bi.getRGB(x, y);
		return (65535*getRed(buf) + 256*getGreen(buf) + getBlue(buf));
	}
}
