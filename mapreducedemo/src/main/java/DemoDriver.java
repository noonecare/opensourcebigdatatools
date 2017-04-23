import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;

import org.apache.hadoop.fs.Path;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;


public class DemoDriver extends Configured implements Tool {

    public int run(String[] args) throws Exception {


        // initialize a job
        // 如何去写 MapReduce Job 的配置
        Configuration conf = new Configuration();
        Job job = new Job(conf, "Map Reduce Demo");

        // 这一句是干吗的
        job.setJarByClass(getClass());

        // specify input file
        FileInputFormat.addInputPath(job, new Path(args[0]));

        // specify output file
        FileOutputFormat.setOutputPath(job, new Path(args[1]));


        // specify mapper
        job.setMapperClass(DemoMapper.class);
        // 减小中间结果的大小
        //job.setCombinerClass();
        // specify reducer
        job.setReducerClass(DemoReducer.class);

        // output 设了为什么 input 不用 设置
        job.setOutputKeyClass(LongWritable.class);
        job.setOutputValueClass(LongWritable.class);

        // 这一句全都一样
        return job.waitForCompletion(true) ? 0: 1;
    }

    // main 函数也都一样， 不过 Driver 的写法，并没有反应出太多 map reduce 执行的细节。
    // jobtracker, tasktracker, nodemanager, resourcemanager 这些类的使用都被隐藏了。
    public static void main(String[] args) throws Exception {
        int exitCode = ToolRunner.run(new DemoDriver(), args);
        System.exit(exitCode);
    }



}
