# Hadoop

--------

###  HDFS
> - 容量很大
> - 容错，因为有备份。一份数据（文件），实际上是存了好几份，有少数几份数据 corrupt 了， 照样不影响数据（文件）的读写
> - HDFS 集群中，大部分机器扮演 datanode 的角色，有少数几台机器扮演 namenode 的角色，真正 active 的namenode 只有一台（其他的 namenode 是为了应对 namenode 挂机而准备的热备或者冷备）
> - 你可以认为 namenode 是个索引，记录了所有文件的保存位置，比如文件保存在了那个 Block 上， Block 在那些 DataNode 上。你访问一个文件，首先 namenode 会帮你找到文件在那些 DataNode, 然后你去相应的 DataNode 上进行读写。
> - 上面这句话，说的正式一点就是： 所有文件的 metadata(namespace img 和 edit log) 会被保存到 namenode 主机的内存中，如果文件太多， namenode 主机的内存会不够用，所以不要保存太多的小文件。
> - namenode 是HDFS性能的瓶颈，为了保证 namenode 可靠地运行，人们提出了很多的方案。最常用的是 HA 部署。就是有个热备的 namenode 称为 standby namenode。 standby namenode 会不断对 activenamenode 的 namespace img 和 edit log 做备份。如果 active namenode 出现故障，activenamenode 马上会停止运行，standby namenode 立马变成 active namenode(这个过程被称为 failover)。




------------

### Interface

##### Command Line Interface
- hadoop 以 POSIX 接口的形式把 HDFS 呈现给用户，用起来就像是在用 Linux 一样。下面我主要介绍比较有特点的几个命令。
> - 本地文件系统和HDFS文件系统传输文件
```shell
# 把本地文件系统中的文件复制到一个 HDFS 文件系统的指定目录下
hadoop fs -copyFromLoacl input/docs/quangle.txt hdfs://<namenode_ip_or_domain>/user/tom/
# 把 一个HDFS文件系统中的文件复制到本地
hadoop fs -copyToLocal hdfs://<namenode_ip_or_domain>/user/tom/quangle.txt input/docs/
# 把本地文件复制到 HDFS 系统，我更喜欢用 put
hadoop fs -put input/docs/quangle.txt hdfs://<namenode_ip_or_domain>/user/tom/
```
配置默认 HDFS 文件系统： core-site.xml 中配置 fs.default.name 参数。如果你向这个参数指定的 hdfs上传数据，不需要写 hdfs:://<namenode_ip_or_domain> 直接写目录就行了。
```shell
hadoop -fs -copyFromLocal input/docs/quangle.txt /user/tom/
```

> - replication factor: 数据（文件）实际保存了多少份儿
```shell
hadoop fs -ls .
Found 2 items
drwxr-xr-x - tom supergroup 0 2009-04-02 22:41 /user/tom/books
-rw-r--r-- 3 tom supergroup 118 2009-04-02 22:29 /user/tom/quangle.txt
```
输出结果的第二列表示 replication factor。3 表示文件被保存了三份。目录是 metadata 只保存在 namenode 上，不会在 datanode 上保存，所以 directory 的 replication factor 是 -

> - Block Size
```shell
hadoop fs -stat %o <data>
```
可以得到文件 <data> 的 Block Size
```shell
hadoop fs -du <data>
```
可以得到文件 <data> 的文件大小。有文件大小和 Block Size 可以算出文件被保存成了多少个 Block（就是 partition number）。 partition number 决定了 mapreduce 和 spark 程序运行时的并发度。

> - HDFS 文件的权限机制和 Linux 的权限机制一样。


##### WebHDFS
- 如果你所在的机器上没有装 hadoop 你就不能用上面的 hadoop 提供的 POSIX 接口去传输文件。这时，你可以用 WebHDFS 传输文件。
- WebHDFS 是 HDFS 对访问 HDFS 提供的 **RestFul 接口**。可以用 curl 来访问。WebHDFS 的使用，还是查看[官档](https://hadoop.apache.org/docs/r1.0.4/webhdfs.html)。WebHDFS 默认运行在 50070 端口上。

- 特别说一句， 如果访问 HDFS 需要通过 kerberos 认证，那么 curl 需要支持 SPENGO 才能通过 kerberos 认证。
