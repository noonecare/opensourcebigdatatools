Questions:

- Hive 和 Impala 是如何共享数据的
- Hive 中的 Analytic function
- Hive Serde
> - Serde 负责 **序列化** 和 **反序列化**。序列化指的是把 InputFormat 得出的 记录 转成 java 对象， 反序列指的是把 java 对象 转成 一条条记录，这些记录一般又会经 outputformat 写成某种特定格式的文件。

- Hive InputFormat/OutputFormat
