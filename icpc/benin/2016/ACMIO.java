import java.io.FileReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PushbackReader;
import java.text.NumberFormat;

/*****************************************************************************
* The <CODE>ACMIO</CODE> class has methods for reading some primitive data values
* from the keyboard and text files, and it has methods to set fieldwidth
* and precision in formatting Strings for output. The class was designed
* for use in the ACM Mid-Central Regional Competition, November 6, 1999.
* See the sample program ACMIOTest.java and sample input file t.txt.
* <h4>
* <b>Input method overview</b></h4>
* 
* <dd>
* There is a constructor that takes a filename as parameter. For example</dd>
* 
* <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*        <CODE>ACMIO fileIn = new ACMIO("problem1.in");</CODE>
* <br>You may instantiate multiple file readers. There is only one keyboard,
* so a static method returns the only keyboard reader. For example:
* <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*        <CODE>ACMIO stdin = ACMIO.getStdin();</CODE>
* <dd>
* IOExceptions and input in illegal formats cause the program to terminate
* with an error message to System.err. The illegal input formats are caused
* by incorrect numeric format or end-of-file where a token was expected.</dd>
* 
* <dd>
* Most reading methods skip initial whitespace, but there are two methods
* that do not:</dd>
* 
* <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*      <CODE>getChar()</CODE> reads the next character, and</dd>
* 
* <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
*      <CODE>getLine()</CODE> reads a whole line.</dd>
* 
* <dd>
* Methods with names in the form typeRead skip whitespace and then read an
* int, long, double, char or String. Examples are 
* <CODE>intRead() andstringRead()</CODE>.
* Note all start with a lowercase letter. Method <CODE>stringRead()</CODE> reads
* the longest String with no whitespace. There are also methods with "ln"
* added to the end:&nbsp; <CODE>intReadln(), longReadln(), doubleReadln(),
* charReadln() </CODE>and<CODE> stringReadln()</CODE>, which all skip the rest
* of the line.</dd>
* 
* <dd>
* Note the distinction between that <CODE>getLine()</CODE> and 
* <CODE>stringReadln().&nbsp;&nbsp;</CODE>
* Both end up after the end of a line, but <CODE>getLine()</CODE> returns the
* rest of the current line, and <CODE>stringReadln()</CODE>skips all whitespace,
* possibly through several empty lines, and skips to the end of the line
* afterthe first sequence of non-whitespace characters it finds.</dd>
* 
* <dd>
* Boolean methods that test the state are <CODE>isEOLN()</CODE> and
* <CODE> isEOF()</CODE>, which read ahead to see if the end of a line or the 
* end of the file is next.</dd>
* 
* <dd>
* Void input skipping methods are <CODE>skipBlanks()</CODE>, 
* <CODE>skipWhitespace()</CODE>, and <CODE>skipLine()</CODE>.</dd>
* 
* <h4>
* <b>String formatting method overview:</b></h4>
* 
* <dd>
* To be comparable with output formatting in Pascal and C and C++, there
* are a group of overloaded static methods to specify the precision of a
* double and the minimum fieldwidth and left or right justification for any
* String.</dd>
* 
* <p><CODE>String format(long l, int minimumWidth)</CODE>
* <br><CODE>String format(Object o, int minimumWidth)</CODE>
* <br><CODE>String format(double d, int minimumWidth)</CODE>
* <br><CODE>String format(double d, int minimumWidth, int precision)</CODE>
* <p>where a positive <CODE>minimumWidth</CODE> means right-justify and negative
* means left-justify, and both are in a field of at least |<CODE>minimumWidth</CODE>|
* columns.
* <br>Explicit overloadings for the justification are only given for numbers
* and for objects, but anything can be converted to a String Object by concatenating
* it with the empty String: "" + (anything). Examples:
* <p><CODE>format(123.45678, 7, 2)</CODE> returns <CODE>" 123.46"</CODE>, with one
* blank on the left.
* <br><CODE>format(123.45678, -7, 2)</CODE> returns <CODE>"123.46 "</CODE>, with
* one blank on the right.
* <br><CODE>format(-1234, 8)</CODE> returns <CODE>"&nbsp;&nbsp; -1234"</CODE>, with
* three blanks on the left.
* <br><CODE>format("abc", -5)</CODE> returns <CODE>"abc&nbsp; "</CODE>, with two
* blanks on the right.
* 
* @author
*   Andrew Harrington (anh@cs.luc.edu)
*
* @version
*   Sept 16, 1999
****************************************************************************/
public class ACMIO
{
   private static ACMIO stdin = null; 
   private PushbackReader in;
   
   final static int  EOF = -1;      // Returned by in.read() at EOF

   
   /**
   * Construct an ACMIO to read from a file.
   * @param 
   *   <code>filename</code> file to read from.
   * <dt><b>Abort</b>
   *   if the file cannot be opened to read.
   **/
   public ACMIO(String filename) {
      try
      {
         in = new PushbackReader(new FileReader(filename));
      }
      catch (Exception e)
      {
        badExit("can't open file " + filename);
      }   
   }

   private ACMIO() {
         in = new PushbackReader(new InputStreamReader(System.in));
   }

   /**
   * Returns the <code>ACMIO</code> object that reads from <code>System.in</code>.
   * @param none
   * @return
   *   <code>ACMIO</code> object that reads from <code>System.in</code>
   **/
   public static ACMIO getStdin() {
        if (stdin == null)
            stdin = new ACMIO();
        return stdin;
   }

   /**
   * Read and discard whitespace: blanks, tabs, and newlines.
   * @param none
   **/
   public void skipWhitespace()
   {
      unread(pastWhitespace());   
   }


   /**
   * Read and discard blanks.
   * @param none
   **/
   public void skipBlanks()
   {
      int next = read();
      while (' ' == next)
         next = read();
      unread(next);   
   }


   /**
   * Read and discard the rest of the current input line.
   * @param none
   **/
   public void skipLine()
   {
      int next = read();
      while (next != '\n' && next != EOF)
         next = read();
   }

   /**
   * Read until the end of the current line.
   * @param none
   * @return
   *   a <CODE>String</CODE> with all characters other that '\r' or '\n' 
   *   until the end of the line, or end-of-file if that comes first.
   **/
   public String getLine()
   {
      StringBuffer buffer = new StringBuffer(80);
      int next = read();
      while (next != '\n' && next != EOF) {
         if (next != '\r') 
             buffer.append((char)next);
         next = read();
      }
      return buffer.toString();
   }

   /**
   * Read a character.
   * @param none
   * @return
   *   a character read 
   * 
   * <dt><b>Abort</b>
   *   if tried to read at end-of-file.
   **/
   public char getChar()
   {
      int next = read();
      if (next == EOF) 
          badExit("expected char, not EOF!");
      return (char) next;
   }

   /**
   * Skip whitespace and read a character.
   * @param none
   * @return
   *   a character read that is not whitespace 
   * 
   * <dt><b>Abort</b>
   *   if there was only whitespace until the end-of-file.
   **/
   public char charRead()
   {
      int next = pastWhitespace();
      if (next == EOF)
          badExit("expected char, not EOF!");
      return (char) next;
   }

   /**
   * Skip whitespace, read a character, and skip the rest of the line.
   * @param none
   * @return
   *   a character read that is not whitespace 
   * 
   * <dt><b>Abort</b>
   *   if there was only whitespace until the end-of-file.
   **/
   public char charReadln()
   {
      char answer = charRead();
      skipLine();
      return answer;
   }


   /**
   * Read a <CODE>double</CODE> number.
   * @param none
   * @return
   *   a </CODE>double</CODE> number that's been read
   * <dt><b>Parsing details:</b>  Skip whitespace and then read 
   *   an optional sign, 0 or more digits, an optional '.' 
   *   and 0 or more digits, and an optional exponent 
   *   including an 'e' or 'E', optional sign, and digits.  
   *   The first character not fitting this pattern is left in the input stream.
   *   The extracted string is converted using <CODE>Double.valueOf</CODE>.
   * <dt><b>Abort</b>
   *   if the conversion to a double causes an exception.
   **/
   public double doubleRead()
   {
      StringBuffer input = new StringBuffer();

      StringBuffer buffer = new StringBuffer(80);
      int next = findInteger(pastWhitespace(), buffer);
      if (next == '.')
      {  // Read the decimal point and fractional part.
         buffer.append('.');
         next = findDigits(read(), buffer);
      }
      if (next == 'E' || next == 'e')
      {  
         buffer.append('E');
         next = findInteger(read(), buffer);
      }
      unread(next);  // only private methods end up reading ahead
      double d = 0.0;
      try
      {
         d = Double.valueOf(buffer.toString()).doubleValue();
      }
      catch (NumberFormatException e)
      {
         badExit("bad double format!");
      }
      return d;
   }


   /**
   * Read a double value from a complete line.
   * @param none
   * @return
   *   a double value that's been read
   * <dt><b>Note:</b><dd>
   *   This method is identical to <CODE>doubleRead()</CODE> with 
   *   <CODE>skipLine()</CODE> called just before returning.
   **/
   public double doubleReadln()
   {
      double answer = doubleRead();
      skipLine();
      return answer;
   }


   /**
   * Read an int value.
   * @param none
   * @return
   *   an int that has been read
   * <dt><b>Parsing details:</b>  Skip whitespace and then read 
   *   an optional sign and digits.  
   *   The first character not fitting this pattern is left in the input stream.
   *   The extracted string is converted using <CODE>Integer.parseInt</CODE>.
   * <dt><b>Abort</b>
   *   if the conversion to an int causes an exception.
   **/
   public int intRead()
   {
      StringBuffer buffer = new StringBuffer(80);
      unread(findInteger(pastWhitespace(), buffer));
      int i = 0;
      try
      {
         i = Integer.parseInt(buffer.toString());
      }
      catch (NumberFormatException e)
      {
         badExit("bad int format!");
      }
      return i;
   }


   /**
   * Read an int value from a complete line.
   * @param none
   * @return
   *   an int that has been read
   * <dt><b>Note:</b><dd>
   *   This method is identical to <CODE>intRead()</CODE> with
   *   <CODE>skipLine()</CODE> called just before returning.
   **/
   public int intReadln()
   {
      int answer = intRead();
      skipLine();
      return answer;
   }


   /**
   * Read a long value.
   * @param none
   * @return
   *   a long value that has been read
   * <dt><b>Parsing details:</b>  Skip whitespace and then read 
   *   an optional sign and digits.  
   *   The first character not fitting this pattern is left in the input stream.
   *   The extracted string is converted using <CODE>Long.parseInt</CODE>.
   * <dt><b>Abort</b>
   *   if the conversion to a long causes an exception.
   **/
   public long longRead()
   {
      StringBuffer buffer = new StringBuffer(80);
      unread(findInteger(pastWhitespace(), buffer));
      long l = 0;
      try
      {
         l = Long.parseLong(buffer.toString());
      }
      catch (NumberFormatException e)
      {
         badExit("bad long format!");
      }
      return l;
   }

   /**
   * Read a long value from a complete line.
   * @param none
   * @return
   *   a long value that has been read
   * <dt><b>Note:</b><dd>
   *   This method is identical to <CODE>longRead()</CODE> with
   *   <CODE>skipLine()</CODE> called just before returning.
   **/
   public long longReadln()
   {
      long answer = longRead();
      skipLine();
      return answer;
   }

   /**
   * Read the next whitespace-delimited <CODE>String</CODE>.
   * @param none
   * @return
   *   a <CODE>String</CODE> of non-whitespace characters read
   * <dt><b>Abort</b>
   *   if there are no non-whitespace characters until end-of-file.
   **/
   public String stringRead()
   {
      StringBuffer buffer = new StringBuffer(80);

      int next = pastWhitespace();
      while (next != EOF && !Character.isWhitespace((char)next)) {
         buffer.append((char)next);
         next = read();
      }
      unread(next);
      if (buffer.length() == 0)
          badExit("expected non-whitespace char, not EOF!");
      return buffer.toString();
   }

   /**
   * Read the next whitespace-delimited <CODE>String</CODE>,
   * and skip the rest of the line it is on.
   * @param none
   * @return
   *   a <CODE>String</CODE> of non-whitespace characters read
   * <dt><b>Abort</b>
   *   if there are no non-whitespace characters until end-of-file.
   **/
   public String stringReadln()
   {
      String s = stringRead();
      skipLine();
      return s;
   }


   /**
   * Determine whether the last character of the file has been read.
   * @param none
   * @return
   *   true if all characters up to but not necessaily including EOF have been read.
   **/
   public boolean isEOF()
   {
      int next = read();
      unread(next);
      return next == EOF;
   }


   /**
   * Determine whether the next input character is an end of line or end of file.
   * @param none
   * @return
   *   true if the next input character is '\n' or '\r', 
   *   or if <CODE>isEOF()</CODE>
   **/
   public boolean isEOLN()
   {
      int next = read();
      unread(next);
      return (next == '\n') || (next == '\r' || next == EOF);
   }

//private input methods ------------------------------------------------------------
   private static void badExit(String errMsg) {  
      // abort with message
      System.err.println("Aborting -- " + errMsg);
      System.exit(-1);
   }

   private int read()
   // Read and return the next character or abort.
   {
      int next = 0;
      try
      {
         next = in.read();
      }
      catch (IOException e)
      {
         badExit("File reading error!  " + e.getMessage());
      }
      return next;
   }

   private void unread(int next)
   // Unread next or abort.
   {
      if (next == EOF) return;
      try
      {
         in.unread(next);
      }
      catch (IOException e)
      {
         badExit("File unreading error!  " + e);
      }
   }

   private int findDigits(int next, StringBuffer buffer)
   // append any digits, starting with next to buffer, return first non-digit
   {
      while (Character.isDigit((char)next)) {
         buffer.append((char)next);
         next = read();
      }
      return next;
   }

   private int findInteger(int next, StringBuffer buffer)
   // append any sign+digits, starting with next to buffer, 
   //   return first char not matching pattern
   {
      if (next == '+') next = read();
      if (next == '-') {
        buffer.append('-');
        next = read();
      }
      return findDigits(next, buffer);
   }

   private int pastWhitespace()
   // Read and discard whitespace: blanks, tabs, and newlines.
   // return first non-whitespace char
   {
      int next = read();
      while (Character.isWhitespace((char)next))
         next = read();
      return next;   
   }


// String formatting routines ----------------------------------------------

   private static NumberFormat numForm = NumberFormat.getNumberInstance();
   
   /**
   * Format a double as a </CODE>String</CODE> with a specified format.
   * @param <CODE>d</CODE>
   *   the number to be printed
   * @param <CODE>minimumWidth</CODE>
   *   |minimumWidth| is the minimum number of characters in the entire 
   *   output, and the positive or negative sign indicates right or left 
   *   justification.
   * @param <CODE>fractionDigits</CODE>
   *   the number of digits to print, with rounding, on the right side 
   *   of the decimal point.  A negatine fractionDigits is treated like 0.
   *   No decimal point is printed if <CODE>fractionDigits</CODE> is 0.
   **/
   public static String format(double d, int minimumWidth, int fractionDigits)
   {
      numForm.setGroupingUsed(false);  // no commas
      if (fractionDigits < 0) fractionDigits = 0;
      numForm.setMinimumFractionDigits(fractionDigits);
      numForm.setMaximumFractionDigits(fractionDigits);
      return format(numForm.format(d), minimumWidth);
   }

   /**
   * Create a left or right justified String from an <CODE>Object</CODE> .
   * @param <CODE>o</CODE>
   *   the Object to be printed
   * @param <CODE>minimumWidth</CODE>
   *   |minimumWidth| is the minimum number of characters in the entire 
   *   output, and the positive or negative sign indicates right or left 
   *   justification.
   **/
   public static String format(Object o, int minimumWidth)
   {
      String s = o.toString();
      int nBlanks = Math.abs(minimumWidth) - s.length();
      if (nBlanks <= 0) return s;
      String BLANK40 = "                                        ";
      String pad = "";
      while (nBlanks >= 40) {
          pad += BLANK40;
          nBlanks -= 40;
      }
      pad += BLANK40.substring(0,nBlanks);
      if (minimumWidth > 0)
        return pad+s;
      else
        return s+pad;
   }

   /**
   * Create a left or right justified String from a double value.
   * @param <CODE>d</CODE>
   *   the number to be printed
   * @param <CODE>minimumWidth</CODE>
   *   |minimumWidth| is the minimum number of characters in the entire 
   *   output, and the positive or negative sign indicates right or left 
   *   justification.
   **/
   public static String format(double d, int minimumWidth)
   {
      return format(""+ d, minimumWidth);
   }

   /**
   * Create a left or right justified String from a long value.
   * @param <CODE>n</CODE>
   *   the number to be printed
   * @param <CODE>minimumWidth</CODE>
   *   |minimumWidth| is the minimum number of characters in the entire 
   *   output, and the positive or negative sign indicates right or left 
   *   justification.
   **/
   public static String format(long n, int minimumWidth)
   {
      return format("" + n, minimumWidth);
   }

}

