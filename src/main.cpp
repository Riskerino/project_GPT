#include "FastaFile.h"
#include "FastaParser.h"
#include <iostream>

int main()
{
    FastaFileDNA fastaFile;
    Utility::readDNAFastaFormatFromFile("../data/example.fasta", &fastaFile);
    return 0;
}
