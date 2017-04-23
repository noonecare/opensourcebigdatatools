import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;


public class DemoMapper extends Mapper<LongWritable, Text, LongWritable, LongWritable>{

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String line = value.toString();
        // 我只是要求最长的记录的长度
        context.write(new LongWritable(1L), new LongWritable(line.length()));
    }
}
