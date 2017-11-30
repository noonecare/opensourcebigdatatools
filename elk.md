### ElasticSearch

ElasticSearch 是使用 REST API（开发者观点）分析日志的工具。从 [issue](https://github.com/ameizi/elasticsearch/issues/5) 中能大致了解 ElasticSearch 的 REST API(基本也是增删改查)。这些 REST API 和 MongoDB 的接口很像。


### LogStash

需要写配置文件，配置 input, ouput, 然后 logStash 就会接受 input 的 Event Data, 并把 Event Data 保存到 output 中。
为了应对各种各样不同的 input, LogStash 社区提供了很多 plugin。非常有名的比如 http plugin， 配置 input（让 input 使用 http plugin 接受 http 类型的 Event Data）， logStash 就可以接受 post 请求，并把 post 请求保存到 output 中。

所以，使用 LogStash 最大的难点，就在于：

- 写 logStash 配置文件（使用 Domain Specified Language 来写配置文件。每个配置文件一定会配置， input, filter, output 三个 section。）


- 了解常用的 plugin

参看[介绍如何写 logStash 配置文件的文章](https://logz.io/blog/logstash-tutorial/)，[介绍 http plugin 的文章](http://www.elastic.co/blog/introducing-logstash-input-http-plugin) 和 [介绍 elasticsearch plugin 的文章](https://www.elastic.co/guide/en/logstash/current/plugins-outputs-elasticsearch.html)。


### Kibana

Kibana 是使用 Web UI(普通用户的观点)分析日志的工具。


### Summary

ELK 是 ElasticSearch, LogStash 和 Kibana 的首字母缩写。 ELK 提供了收集日志，分析日志的一整套的解决办法。ELK 的设计理念（解决的问题）可以参考[introduction-elk-stack](https://www.elastic.co/webinars/introduction-elk-stack) 页面中的视频。