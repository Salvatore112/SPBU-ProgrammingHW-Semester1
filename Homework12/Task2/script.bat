echo off

echo Hi

start dot -Tpng graph.dot -o image.png

timeout 1

start image.png




