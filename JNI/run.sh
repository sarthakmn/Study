javac -h . HelloJNI.java
export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libhello.so HelloJNI.cpp
java -Djava.library.path=. HelloJNI