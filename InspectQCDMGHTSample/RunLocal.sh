echo ""
echo "=====START"
date
echo ""

SAMPLE="MC23_QCD_HT-2000"
python3 -u RunSelector.py --sample $SAMPLE  --cpus 2 --nfiles 3
# python3 -u RunSelector.py --sample $SAMPLE  --cpus 1 --nfiles -1

echo ""
echo ""
date
echo "=====END"
