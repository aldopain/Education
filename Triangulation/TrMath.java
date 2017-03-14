public class TrMath {
	
	/* k == 1 - get max
	 * k == 0 - get min
	 */
	static int getMinOrMax(int a, int b, int c, int k){
		if(k == 0){
			a *= -1;
			b *= -1;
			c *= -1;
		}
		if(a >= b)
			if(a >= c)
				return k == 0 ? -a : a;
			else
				return k == 0 ? -c : c;
		else if (b >= c)
			return k == 0 ? -b : b;
		else
			return k == 0 ? -c : c;
	}
	
	static int sgn(int a){
		if(a > 0)
			return 1;
		if(a < 0)
			return -1;
		return 0;
	}
}
