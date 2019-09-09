export QUAKEDIR="./game"

if [ -z $QUAKEDIR ]; then
	echo "ERROR: Please set QUAKEDIR to your quake install directory"
	exit
fi

if [ -f "./bin/linux64/engine" ]; then
	echo "Running engine..."
	./bin/linux64/engine -basedir "$QUAKEDIR"
	exit
fi

if [ -f "./bin/linux32/engine" ]; then
	echo "Running engine..."
	./bin/linux32/engine -basedir "$QUAKEDIR"
	exit
fi
