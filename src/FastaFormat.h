#ifndef FASTA_FORMAT_H
#define FASTA_FORMAT_H
#include <iostream>
#include "FastaHeader.h"
#include "Sequence.h"

class FastaFormatDNA
{
public:
    FastaFormatDNA(int id) : id(id), header(nullptr), sequence(nullptr) {}
    
    void setFastaHeader(FastaHeader *header) { this->header = header; }
    void setFastaSequence(NucleotideSequence *sequence) { this->sequence = sequence; }
    void printFastaFormatDNA() const
    {
        if (header)
            std::cout << header->getHeader() << std::endl;
        if (sequence)
            sequence->printSequence();
    }

private:
    int id;
    FastaHeader *header;
    NucleotideSequence *sequence;
};

#endif // FASTA_FORMAT_H
