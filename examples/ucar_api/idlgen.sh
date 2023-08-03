# --client 指定生成客户端代码 --server 指定生成服务端代码。默认生成客户端+服务端代码。
# -replace 生成替换原来文件
# -d 指定输出目录
../../fastrpcgen/scripts/rpcddsgen UCar.idl -replace -d .
clang-format -i *.h *.cpp *.cxx *.hpp