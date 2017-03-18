# coding: utf-8
import sys
import math


# 机器学习中常用的 sigmoid 函数
def sigmoid(x):
    return 1 / (1 + math.exp(x))

for line in sys.stdin:
    # hive 输出结果默认是以 \t 区分各个列的
    print("\t".join([str(sigmoid(float(field))) for field in line.split("\t")]))
