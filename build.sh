#!/bin/bash
#------------------#
#      CONFIG      #
#------------------#
# JDK 8 location
JDK_LOCATION="/usr/lib/jvm/java-8-oracle"
#-------------------#
#       BUILD       #
#-------------------#
# Compile jni interface
mkdir -p dist/production
javac -d dist/production src/main/java/sk/lataa/linux/LinuxEnv.java
# Generate jni header
cd dist
javah -cp production -d production sk.lataa.linux.LinuxEnv

# Generate jar & native library
jar cvf LinuxEnv.jar production/sk/lataa/linux/LinuxEnv.class
g++ -I"$JDK_LOCATION/include" -I"$JDK_LOCATION/include/linux" -o liblinuxenv.so -shared ../src/main/native/sk_lataa_linux_LinuxEnv.cc -fPIC -lstdc++
