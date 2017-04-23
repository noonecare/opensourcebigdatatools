import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapred.ClusterMapReduceTestCase;

import java.io.File;
import java.io.FileWriter;


public class DemoTest extends ClusterMapReduceTestCase{
    @Override
    protected void setUp() throws Exception {
        super.setUp();
        FileWriter fileWriter = new FileWriter("test.txt");
        int count = 100;
        int i = 0;
        while (i < count) {
            fileWriter.write("Hello, good luck\n");
            i += 1;
        }
        fileWriter.close();

    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
        File file = new File("test");
        file.delete();
    }

    public void test() throws Exception {

        Configuration conf = new Configuration();
        conf.set("fs.default.name", "file:///");
        conf.set("mapred.job.tracker", "local");

        FileSystem fs = FileSystem.getLocal(conf);


//        Path localInput = new Path("test");
//        Path input = getInputDir();
//        Path output = getOutputDir();

        // copy Data into HDFS
        // getFileSystem().copyFromLocalFile(localInput, input);
        DemoDriver driver = new DemoDriver();
        driver.setConf(conf);
        Path input = new Path("test.txt");
        Path output = new Path("ouput");
        int exitCode = driver.run(new String[]{input.toString(), output.toString()});
        assert (exitCode == 0);

    }
}
