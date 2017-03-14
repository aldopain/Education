import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

import org.bytedeco.javacv.FFmpegFrameGrabber;
import org.bytedeco.javacv.Java2DFrameConverter;

import com.jbrown.image2avi.core.AVIOutputStream;
import com.jbrown.image2avi.core.VideoFormat;

public class VideoController {

	//gets frames from video in [start; end]
	static ArrayList<BufferedImage> grabFrames(String videoPath, int start, int end) throws IOException, Exception{
		FFmpegFrameGrabber g = new FFmpegFrameGrabber(new File(videoPath));
		ArrayList<BufferedImage> retVal = new ArrayList<BufferedImage>();
		g.start();
		Java2DFrameConverter jfc = new Java2DFrameConverter();
		for (int i = 0 ; i < start ; i++)
			g.grab();
		for (int i = start ; i <= end ; i++) {
			retVal.add(jfc.convert(g.grab()));
		}
		g.stop();
		return retVal;
	}
	
	/* creates video from frames, grabbed into imgPath directory
	 * all frames should be called as numbers (ex.: 1.jpeg, 2.jpeg ... 10000.jpeg, etc.)
	 * start and finish - nums of first and last frames in directory
	 */
	void createVideo(int start, int finish, File video, String imgPath, VideoFormat format) throws IOException{
		 AVIOutputStream out = null;
		 Graphics2D g = null;
	     try {
	    	 out = new AVIOutputStream(video, format);
	         out.setVideoCompressionQuality(1f);
	         out.setTimeScale(1);
	         out.setFrameRate(30);
	         for (int i = start; i < finish; i++) {
	     		out.writeFrame(ImageIO.read(new File(imgPath + i + ".jpeg")));
	         }
	     } finally {
	          if (g != null) {
	              g.dispose();
	          }
	          if (out != null) {
	              out.close();
	          }
	      }
	}
	
	
	
}
