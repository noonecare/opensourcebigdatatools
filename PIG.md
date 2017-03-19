### Pig

-  pig 非常类似 hive(从完成的功能上来说)， 也是一种常用的 ETL 开源工具， Pig 语句和 ETL 语句的不同之处， Hive 语句是 **Declartive** 的， 而 Pig 的语句是 **Procedure** 的。

- Pig 语句和语法非常类似  Bashshell。
- Pig reserved words
- Relations: 你可以把 relations 想象成是表。
> |Category|reserved word|description|
> |-------|--------------|-----------|
> |Load|LOAD|和 Hive 不同，Pig 把数据 move 到 表目录下|
> |load|STORE||
> |load|DUMPS||
> |Filter|GROUP BY||
> |Filter|FILTER BY||
> |FILTER|FOREACH GENERATE||
> |FILTER|DISTINCT||
> |FILTER|STREAM||
> |FILTER|MAPREDUCE|I FORGET|
> |FILTER|SAMPLE||
> |GROUP AND JOIN|GROUP BY||
> |GROUP AND JOIN|CROSS|
> |GORUP AND JOIN|COGROUP BY||
> |GROUP AND JOIN|JOIN||
> |SORT|SORT BY||
> |SORT|LIMIT|
> |COMBINE AND SPLIT|SPLIT||
> |COMBINE AND SPLIT|UNION||



- operator

|Category|operator|Description|
|--------|--------|-----------|
|Diagnostic|DESCRIBE||
|Diagnostic|EXPLAIN||
|Diagnostic|ILLUSTRATE||
|Arithmetic|+, -, *,/, %|--------|
|FIELD BY POSTITION|$n||
|FIELD BY NAME|f||
|Field(disambiguare)|r::f||
|Projection|c.$n,c.f||
|Map lookup|m#k||
|Cast|(t)f||
|Conditional|x?y:z||
|Comparsion|==, !=, <, >, >=, <=, matches, is null, is not null||
|Boolean|or, and, not||
|Functional|f(f_1,f_2...)||
|Flatten|FLATTEN(f)||


- commands

|Category|Command|Description|
|--------|-------|-----------|
|Hadoop FileSystem|ls|-------|
|Hadoop FileSystem|rm|-------|
|Hadoop FileSystem|put|------|
|Hadoop FileSytem|copyFromLocal||
|Hadoop FileSystem|cat||
|Hadoop FileSystem|cd||
|Hadoop FileSystem|fs||
|Hadoop FileSystem|rmf||
|hadoop FileSystem|cp||
|Hadoop FileSystem|mkdir||
|Hadoop FileSytem|mv||
|Hadoop FileSystem|pwd||
|Hadoop FileSystem|copyToLocal||
|Hadoop MapReduce Utility|exec||
|Hadoop MapReduce Utility|help||
|Hadoop MapReduce Utility|quit||
|Hadoop MapReduce Utility|run||
|Hadoop MapReduce Utility|set||
|Hadoop MapReduce Utitlity|sh||


- Types

|Category|Type|Description|
|--------|----|-----------|
|Numberic|int||
|Numberic|long||
|Numberic|float||
|Numberic|double||
|Text|chararray||
|Binary|bytearray||
|Complex|tuple||
|Complex|bag||
|Complex|map||





- User Defined Function

|Category|Function|Description|
|--------|--------|-----------|
|Eval|AVG||
|Eval|CONCAT||
|Eval|COUNT||
|Eval|COUNT_STAR||
|Eval|DIFF||
|Eval|SIZE||
|Eval|SUM||
|Eval|TOBAG||
|Eval|TOKENIZE||
|Eval|TOMAP||
|Eval|TOP||
|Eval|TOTUPLE||
|Filter|IsEmpty||
|Load/Store|PigStorage||
|Load/Store|BinStorage||
|Load/Store|TextLoader||
|Load/Store|JsonLoader, JsonStorage||
|Load/Store|HBaseStorage||


- Macros

```bashshell
DEFINE max_by_group(X, group_key, max_field) RETURNS Y{
	A = GROUP $X by $group_key;
    $Y = FOREACH A GENERATE group, MAX($X.$max_field);
}
```


- Stream

```bashshell
C = STREAM A THROUGH `cut -f 2`;
DUMP C;
```

- Invokator
```bashshell
DEFINE trim InvokeForString('org.apache.commons.lang.StringUtils.trim', 'String');
B = FOREACH A GENERATE trim(fruite);
DUMPS B;
```

Pig 是用于 ETL 的轻量级（语法不复杂）的 脚本语言。可能现在我已经可以看懂很多 Pig 脚本了，但是不实际写几个 Pig 脚本是无法熟练运用的。