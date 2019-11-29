#!bin/bash 

if [[ `uname -n` == *"lxplus"* ]]; then 

    ROOT_VERSION=6.18.04
    GCC_VERSION=4.8.4
    OPT_VERSION=x86_64-centos7-gcc48-opt
    LCG=/cvmfs/sft.cern.ch/lcg/
    
    ## start ROOT/GCC
    ROOTSYS=$LCG/app/releases/ROOT/${ROOT_VERSION}/${OPT_VERSION}/
    . $LCG/external/gcc/${GCC_VERSION}/${OPT_VERSION}/setup.sh
    . $ROOTSYS/bin/thisroot.sh

    ## add python lib
    . /opt/rh/python27/enable
    export LD_LIBRARY_PATH=/opt/rh/python27/root/usr/lib64/:$LD_LIBRARY_PATH
fi

export PYTHONPATH=.:$PYTHONPATH
