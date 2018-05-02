import java.util.HashMap;
import java.util.Scanner;

public class SmsConvert
{
    // TODO: add a member variable for the map

    public SmsConvert() {

	// TODO: initialize the member variable

	fillMap();
    }

    private void fillMap() {
	
	// TODO: initialize the map with all of the text mappings
    }

    public String translate(String sentence) {
	String ret = "";

	// TODO: split the sentence up into separate words
	// and translate each word. Return a single string
	// with all of the words in it

	return(ret);
    }

    public static String getSentence() {
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter: ");
	String text = sc.nextLine();
	return(text);
    }

    public static void main(String[] args) {

	SmsConvert converter = new SmsConvert();
	String text = getSentence();

	while (text.equals(".") == false) {
	    
	    String translatedString = converter.translate(text);
	    System.out.println("You said: " + translatedString);
	    
	    text = getSentence();
	}
    }
}
