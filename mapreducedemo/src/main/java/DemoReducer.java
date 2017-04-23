import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;


public class DemoReducer extends Reducer<LongWritable, LongWritable, LongWritable, LongWritable>{

    @Override
    protected void reduce(LongWritable key, Iterable<LongWritable> values, Context context) throws IOException, InterruptedException {
        long max = 0;
        for (LongWritable value: values) {
            long temp = value.get();
            if ( temp > max ){
                max = temp;
            }
        }
        context.write(null, new LongWritable(max));
    }
}
