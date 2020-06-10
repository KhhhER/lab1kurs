arg1=$1;
depth=0;

if [[ ! $2 ]]
then
    MAX_DEPTH=3;
    MAX_WIDTH=3;
    MAX_FILES=3;
elif [[ ! $3 ]]
then
    MAX_DEPTH=$2;
    MAX_WIDTH=3;
    MAX_FILES=3;
elif [[ ! $4 ]]
then
    MAX_DEPTH=$2;
    MAX_WIDTH=$3;
    MAX_FILES=3;
else
    MAX_DEPTH=$2;
    MAX_WIDTH=$3;
    MAX_FILES=$4;
fi

generation ()
{
    local i=0;
    local j=0;
    local k=0;
    local numOfLines=$(shuf -i 1-100 -n 1);
    local numOfDir;
    local numOfFiles;
    local countLines;
    local dirName;
    local fileName;

    if [[ ${arg1} == '-gr' ]]
    then
        if [[ $depth == 0 ]]
        then
            numOfDir=$(shuf -i 1-${MAX_WIDTH} -n 1);
        else
            numOfDir=$(shuf -i 0-${MAX_WIDTH} -n 1);
        fi
    else
        echo -n "Enter number of directories: "
    read numOfDir;
    fi
    if [[ ${numOfDir} == 0 ]]
    then
        let depth--;
        cd ..;
        return 0;
    else
        for ((; $i<${numOfDir}; i++))
        do
        if [[ ${arg1} == '-gr' ]]
        then
            if [[ $((${depth})) == $MAX_DEPTH ]]
            then
                let depth--;
                cd ..;
                return 0;
            fi
            let depth++;
            dirName=dir$RANDOM;
        else
            echo -n "Enter name of the directory: "
            read dirName;
        fi
        mkdir ${dirName};
        cd ${dirName};
        if [[ ${arg1} == '-gr' ]]
        then
            numOfFiles=$(shuf -i 0-${MAX_FILES} -n 1);
        else
            echo -n "Enter number of files: "
            read numOfFiles;
        fi
        for ((; $j<${numOfFiles}; j++))
        do
            if [[ ${arg1} == '-gr' ]]
            then
                    fileName=file$RANDOM$(shuf -e .h .cpp -n 1);
            else
                echo -n "Enter name of the file: "
                read fileName;
            fi
            touch ${fileName}
            for ((; $k<${numOfLines}; k++))
            do
                countLines=${countLines}'\n'
            done
            echo -en ${countLines} >> ${fileName}
            k=0;
        done
        j=0;
    generation;
    if [[ $i == $((${numOfDir}-1)) ]]
    then
        let depth--;
        cd ..;
    fi
    done
fi
}

if [[ $1 == '-g' && ! $2 ]]
then
    generation;
elif [[ $1 == '-g' && $2 ]]
then
    echo "Use parameter '-g' without others arguments."
    exit 0;
elif [[ $1 == '-gr' && ! $5 ]]
then
    generation;
elif [[ $1 == '-gr' && $5 ]]
then
    echo "Use parameter '-gr' with no more than 3 arguments."
    exit 0;
elif [[ $1 == '?' && ! $2 ]]
then
    echo "Usage: nof [OPTION]..."
    echo "Generate and find for files .cpp and .h."
    echo "With no argumets, find for files .cpp and .h in the current directory."
    echo
    echo "  -g             Manual file creation. Use the parameter without others arguments."
    echo "  -gr            Random file generation. You can use it with the arguments [MAX_DEPTH] or/and [MAX_WIDTH] or/and [MAX_FILES]."
    echo "                                                         Default values:  MAX_DEPTH = 3      MAX_WIDTH = 3      MAX_FILES = 3"
    echo "  ?              Display this help. "
elif [[ $1 == '?' && $2 ]]
then
    echo "Use parameter '?' without others arguments."
elif [[ ! $1 ]]
then
    temp=$( find -name '*.cpp' -o -name '*.h' )
    if [[ ! $temp ]]
    then
        echo "Directories don't contain .cpp and .h files."
    else
        wc `find -name '*.cpp' -o -name '*.h'` -l
    fi
else
    echo "Try 'nof ?' for more information."
fi
