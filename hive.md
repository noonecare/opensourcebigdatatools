# Hive

Hive 能把 HiveQL 转成 Map-Reduce 任务去查询数据。也就是说支持用 **HiveQL** 去**查询和操作数据**。HiveQL 非常类似 SQL， 这样只要掌握 SQL 就可以使用 Map-Reduce 任务去查询数据，降低了使用 Map-Reduce 任务的门槛。

----------


### Transform/Map-Reduce Scripts

可以用任何语言写script，只要这个script 接受 stdin 输入，并且往 stdout 输出。这其实就是 hadoop map-reduce 中的 stream script。

- Hive Transform
> - 一般不需要自己写 Scripts 的，一般用的 Scripts 都是现成的工具，比如 cat, grep, awk, sed 等现成的文本操作工具。
> - 我用 python 写了个示例的 mapper script（完成 map job 的功能）， 在 HiveScripts/sigmoid.py。
> - reducer script 的输入是排好序的（使用下面介绍的sort by, order by 和 cluster by 做排序的）字符串。 使用 reducer script 时一定会出现 sort by, order by 和 cluster by。
> - reducer script 的输入是 \t 分割的字符串，输出也是 \t 分割的字符串。

- HiveQL 中 [sort by, order by, distributed by 和 cluster by](https://cwiki.apache.org/confluence/display/Hive/LanguageManual+SortBy)
> - Distribued By 保证如果两条记录具有相同的键(Distributed By 的列)，那么这两条记录一定会被分到同一个 reducer 处理。
> - Sort By 保证在同一个 reducer 中数据是按照键值的大小顺序排列，但是如果有多个 reducer 就不能保证在整体上，键值是按照大小顺序排列的。Order By 可以保证在整体上数据是按键值的大小顺序排列的。
> - CULSTER BY is a short-cut for both Distribute By and Sort By.
> - Hive 的 reducer 数目
>> - 在你要执行的 HiveQL 操作之前，加上 SET mapreduce.job.reduces=<reduces_number> 即可指定执行这句 HiveQL 时的reducer 数目。
>> - hive 的 mapreduce.job.reduces 的 default value 是 -1。如果 mapreduce.job.reduces 的值为 -1， hive 会自动计算出 reduces 的值。自动计算reduces 的值时，reduces 数和 hive.exec.reduces.max 和 hive.exec.reduces.bytes.per.reducer 两个 property 有关。

---------

### UDF
- Hive UDF 中有哪几类函数，没类函数有什么特点。
- Hive UDF 中如何创建自定义的 UDF。



