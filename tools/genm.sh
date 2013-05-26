#! /bin/bash

# declare an array
declare -a features=()

detectFeatures()
{
      source=$1
      suffix=$2
      if [ $suffix = "cpp" -o $suffix = "cxx" ]; then
            if ! [ -z "`grep "#include <thread>" "$source"`" ]; then
                  features["thread"]="true"
            fi
            flags="`head -1 $source | grep "// FLAGS:"`"
            if [ -z "$flags" ]; then
                  flags="// FLAGS: -g"
            fi
            flags=`echo "$flags" | sed "s#// FLAGS: ##"`
            features["flags"]=$flags
      fi
}

getParams()
{
      detectFeatures $1 $2
      params=""
      if [ "${features["thread"]}" = "true" ]; then
            params+=" -pthread"
      fi
      params+=${features["flags"]}
      echo $params
}

suf="`echo $1 | awk -F. '{print $NF}'`"
pre=`echo $1 | awk -F. '{ for(i=1;i<NF;i++) { if ( i > 1 ) printf "."; printf "%s", $i; } print "" }'`
rm -f .makefile
if [ $suf = "c" ]; then
cat << End > .makefile
CFLAGS=-Wall -g
End
elif [ $suf = "cpp" ]; then
cat << End > .makefile
CXX=g++
# CPPFLAGS=-Wall $(getParams $1 $suf)
# CXX=~/fbcode/third-party/centos5.2-native/gcc/gcc-4.6.0/bin/g++
CXX=~/fbcode/third-party/centos5.2-native/gcc/gcc-4.7.1/cc6c9dc/bin/g++
# CPPFLAGS=-Wall $(getParams $1 $suf)
CPPFLAGS=-Wall -std=gnu++0x $(getParams $1 $suf)
# CPPFLAGS=-Wall -std=c++0x $(getParams $1 $suf)
End
elif [ $suf = "cxx" ]; then
cat << End > .makefile
$pre : $pre.cxx
	/opt/local/bin/g++-mp-4.6 -std=c++0x -Wall -g -o $pre $pre.cxx
End
elif [ $suf = "java" ]; then
cat << End > .makefile
$pre : $pre.java
	javac $pre.java
End
else
echo "Not supported type"
exit 1
fi
