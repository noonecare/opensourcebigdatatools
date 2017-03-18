from unittest import TestCase
from unittest.mock import patch
from io import StringIO

import sys


class TestSigmoid(TestCase):
    test_sample = [u"0\t1\t-1\t2\t-2"]

    def test_sigmoid(self):
        with patch("sys.stdout", new=StringIO()) as fake_out:
            sys.stdin = self.test_sample
            # 感觉这样做测试很不规范，但是没有想到更好的做测试的办法
            import sigmoid
            a = fake_out.getvalue().split("\t")
            self.assertEqual(a[0], '0.5')
            pass
