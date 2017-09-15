配置文件采用ini格式。
由于json不便于注释，xml太重、解析开销大，所以均没有采用。
ini格式所包含的最基本的元素就是parameter；每一个parameter都有一个name和一个value，如下所示：
`name = value`
完整实例如下：
```
; last modified 1 April 2001 by John Doe
[owner]
name=John Doe
organization=Acme Widgets Inc.

[database]
; use IP address in case network name resolution is not working
server=192.0.2.62
port=143
file="payroll.dat"
```
在linux上多采用`#` 号作为注释开头。

