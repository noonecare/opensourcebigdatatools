import java.util.*;
import org.apache.hadoop.hive.ql.exec.UDF;

//javac -classpath /opt/hive-0.11.0-bin/lib/hive-exec-0.11.0.jar exact_comment.java
//jar -cvf exact_comment.jar exact_comment.class

public class ExtractJsonUDF extends UDF{
    public static ArrayList<String> evaluate(String comments)
    {
        ArrayList<String> result = new ArrayList<String>();
        if ( comments == null ) return null;
        int count = 0;
        int quote_count = 0;
        int backslash_count = 0;
        int start = 0;
        int end = 0;
        int length = comments.length();
        int i;


        for (i = 0; i < length; i++)
        {

            if (comments.substring(i, i+1).equals("\"") && (backslash_count == 0))
            {
                quote_count += 1;
            }

            if (comments.substring(i, i+1).equals("\\"))
            {
                backslash_count += 1;
                backslash_count = backslash_count % 2;
            }
            else
            {
                backslash_count = 0;
            }



            if (quote_count % 2 == 0)
            {
                if (comments.substring(i, i + 1).equals("{"))
                {
                    count += 1;
                }
                if (comments.substring(i, i + 1).equals("}"))
                {
                    count -= 1;
                }


                if ((count == 0) && comments.substring(i, i + 1).equals(","))
                {
                    result.add(comments.substring(start, end));
                    start = end + 1;
                }
            }
            end += 1;

        }
        result.add(comments.substring(start, length));
        return result;
    }

}
