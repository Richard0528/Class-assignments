package subsetsum_recover;

public class Subsetsum {
	
	private static int[][] result = new int[7][9];

	public static void main(String[] args) {
		int[] list = new int[] {0,1,2,1,3,1,4,1,5};
//		int[][] result = new int[7][9];
		int i = 0;
		while (i < 9) {
			result[0][i] = 1;
			i++;
		}
		int j = 1;
		while (j < 7) {
			result[j][0] = 0;
			j++;
		}
		
		for (i = 1; i < 7; i++) {
			for (j = 1; j < 9; j++) {
				int a = 0;
				int b = 0;
				if (j-1 >= 0) {
					a = result[i][j-1];
					if (i- list[j] >= 0) {
						b = result[i- list[j]][j-1];
					}
				}
				
				result[i][j] = a + b;
				System.out.print(result[i][j]+ ", ");
			}
			System.out.println(" ");
		}
		
		recover(8, 6);
		
		
	}

	private static void recover(int i, int j) {
		// TODO Auto-generated method stub
		
	}


}
