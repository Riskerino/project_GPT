#ifndef FASTA_PARSER_H
#define FASTA_PARSER_H
#include <iostream>
#include "FastaFile.h"
#include <sstream>
#include <string>

namespace Utility
{
    std::string readNextCSString(std::stringstream &ss);
    void parseStringToNucleotideSequence(const std::string &seqLineAsString, NucleotideSequence *subseq);
    void readDNAFastaFormatFromFile(const std::string &i_strFileName, FastaFileDNA *newFastaFile);
}

#endif // FASTA_PARSER_H
