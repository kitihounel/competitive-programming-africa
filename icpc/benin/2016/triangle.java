import java.io.*;

public class triangle {
  static int[] rot   = new int[6]; // rot[i] is current rotation of tri[i],
                                   // 0-2 sides.

  static int[][] tri = new int[6][3];  // The six triangles' edge values.

  static int maxScore; // Set by fit method.
  
  static int getEdge(int n, int shift) {
    // Return data for triangle n.
    // Shift sides from the current rotation, 
    //     shift 0: side against previous triangle
    //     shift 1: side against next triangle
    //     shift 2: outer side used in score
    return tri[n][(rot[n] + shift) % 3];
  }
  
  static boolean matchNext(int n) {
    // True if current rotation of triangle n fits with next triangle,
    // n = 0 - 5.
    return getEdge(n, 1) == getEdge((n + 1) % 6, 0);
  }
  
  static void swap(int i, int j) {
    // Swap triangle[i] and triangle[j].
    int[] temp = tri[i];
    tri[i] = tri[j];
    tri[j] = temp;
  }
  
  static void fit(int n) {
    // Triangles < n fit together, try the rest n = 1 - 6.
    // if n = 6, just check match of tri[5] with tri[0].
    // Uses and sets static rot array at indices >= n.
    // Swaps and unswaps triangles in static tri array.
    // Updates static maxScore
    int i;
    if (n == 6) {
      // No more triangles.
      if (matchNext(5)) {
        int score = 0;
        for (i = 0; i < 6; i++)
          score += getEdge(i,2);
        // System.out.print(" " + score);  // Check solutions.
        maxScore = Math.max(score, maxScore);
      }
    }
    else {
      // Fit next triangle.
      for(i = n; i < 6; i++) {
        // Swap in next remaining triangle.
        swap(n, i);
        for (int r = 0; r < 3; r++) { // Try all 3 rotations.
          rot[n] = r;
          if (matchNext(n-1))
            fit(n+1);
        }
        swap(n,i); // Undo swap so calling method sees no change.
      }
    }
  } 
         
  public static void main(String[] args) {
    String FILE = "triangle";
    ACMIO in = new ACMIO(FILE + ".in");
    PrintWriter out = null;
    try {
      out = new PrintWriter(new BufferedWriter(new FileWriter(FILE + ".out"))); 
    } catch(Exception e) {
      System.out.println("can't open output");
    }

    // Read all data sets.
    do {
      int r;
      for (int n = 0; n < 6; n++)
        for (r = 0; r < 3; r++)
          tri[n][r] = in.intRead();
      maxScore = 0;
      for (r = 0; r < 3; r++) {
        rot[0] = r;
        fit(1);
      }
      // System.out.println();
      if (maxScore == 0)
         out.println("none");
      else
         out.println(maxScore);
    } while (in.charReadln() == '*');
    out.close();
  }
}

