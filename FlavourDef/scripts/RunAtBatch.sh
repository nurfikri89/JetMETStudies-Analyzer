#!/bin/bash

export X509_USER_PROXY=/afs/cern.ch/user/n/nbinnorj/myProxy
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd ${JOBWORKDIR}
source ../SetupLCGStack.sh

echo ""
echo "=====START"
date
echo ""

python3 RunAnaPhysDef.py --sample ${1} --analysis ${2} --cpus ${3}

echo ""
echo ""
date
echo "=====END"
