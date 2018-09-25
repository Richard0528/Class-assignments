/*
 * TMath 412 cryptography take home quiz 2
 */
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * A shift cipher breaker.
 * 
 * @author richardyang
 * @version 1.0
 */
public class BreakerMain {

	/**
	 * Main method.
	 * 
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws Exception {
		String cipher = FileReader(args[0]);
		String actualplain = getActualResult(cipher);
		System.out.println(actualplain);
	}
	
	/**
	 * A method pick and provide actual correct plain text.
	 * 
	 * @param cipher given cipher text
	 * @return correct plain text
	 */
	private static String getActualResult(String cipher) {
		String result = null;
		double topentropy = 1000;
		for (int i = 0; i < 26; i++) {
			String plaintext = decrypt(cipher,i);
			double temp = entropy(plaintext);
			if (topentropy > temp) {
				topentropy = temp;
				result = plaintext;
			}
		}
		return result;
	}

	/**
	 * A method decrypt the given shift cipher.
	 * 
	 * @param cipher given cipher text
	 * @param key given key
	 * @return possible plain text
	 */
	private static String decrypt(String cipher, int key) {
		String result = "";
		for (int i = 0; i < cipher.length(); i++) {
			int c = (int) cipher.charAt(i);
			if (65 <= c && c <= 90) {
				result += (char) ((c - 65 + key) % 26 + 65);
			}
		}
		return result;
	}

	/**
	 * A method calculate the cross entropy for each plain text.
	 * 
	 * @param cipher given cipher text
	 * @return entropy for the corresponding plain text
	 */
	private static double entropy(String cipher) {
		
		ArrayList<Double> letterfreq= new ArrayList<Double>(); 
		letterfreq.add(0.08167);
		letterfreq.add(0.01492);
		letterfreq.add(0.02782);
		letterfreq.add(0.04253);
		letterfreq.add(0.12702);
		letterfreq.add(0.02228);
		letterfreq.add(0.02015);
		letterfreq.add(0.06094);
		letterfreq.add(0.06966);
		letterfreq.add(0.00153);
		letterfreq.add(0.00772);
		letterfreq.add(0.04025);
		letterfreq.add(0.02406);
		letterfreq.add(0.06749);
		letterfreq.add(0.07507);
		letterfreq.add(0.01929);
		letterfreq.add(0.00095);
		letterfreq.add(0.05987);
		letterfreq.add(0.06327);
		letterfreq.add(0.09056);
		letterfreq.add(0.02758);
		letterfreq.add(0.00978);
		letterfreq.add(0.02360);
		letterfreq.add(0.00150);
		letterfreq.add(0.01974);
		letterfreq.add(0.00074);
		
		double sum = 0;
		for (int i = 0; i < cipher.length(); i++) {
			int c = (int) cipher.charAt(i);  // ascii value of each letter
			sum += Math.log(letterfreq.get(c-65)); // Uppercase
		}
		return -sum/Math.log(2)/(cipher.length());
	}

	/**
	 * A method read the given file.
	 * 
	 * @param args filename
	 * @return a string as cipher text
	 * @throws Exception possible IOexception
	 */
	private static String FileReader(String args) throws Exception {
		String textFile = args;
		String line = null;
        BufferedReader cipherText = new BufferedReader(new FileReader(textFile));
        line = cipherText.readLine();
        cipherText.close();
        
		return line;
	}


}
