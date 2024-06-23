
最后更新时间：
	24.06.23

建立时间：
	24.03.23


生成物：
	icCore.dll（Win32）、icCore.so（UnixLike）- MacOS的.dylib暂不支持。

约束：
	icCore有最少的特定于平台的函数，尽可能做到不依赖其他动态库的内容。
icCore是精简的IC C Part。对于其他语言，动态调用的开销很低。
	对于任何违背约束的内容，放置到icPlatforms和ic之中。