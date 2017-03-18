# coding: utf-8
import sys
import math

"""
写好这个脚本之后，在 hive 中，首先需要 add file, 把脚本添加到 hive 的 cache 中
ADD FILE "$LOCAL_DIR/sigmoid.py";
然后使用 TRANSFORM USING 语句指定使用这个脚本，转换数据
SELECT TRANSFORM(a, b) USING "python sigmoid.py" FROM wangmeng.test;
"""


# 机器学习中常用的 sigmoid 函数
def sigmoid(x):
    return 1 / (1 + math.exp(x))

for line in sys.stdin:
    # hive 输出结果默认是以 \t 区分各个列的
    print("\t".join([str(sigmoid(float(field))) for field in line.split("\t")]))
