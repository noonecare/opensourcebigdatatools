
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mrunit.mapreduce.MapDriver;
import org.junit.Test;


import java.io.IOException;


public class DemoMapperTest {

    @Test
    public void testDemoMapper() throws IOException, InterruptedException {

        Text value = new Text("Hello, How are you");

        new MapDriver<LongWritable, Text, LongWritable, LongWritable>()
                .withMapper(new DemoMapper())
                .withInputValue(value)
                .withInputKey(new LongWritable(1L))
                .withOutput(new LongWritable(1L), new LongWritable(value.getLength()))
                .runTest();
    }

}
