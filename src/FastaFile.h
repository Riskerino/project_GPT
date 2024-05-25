#ifndef FASTA_FILE_H
#define FASTA_FILE_H

#include "FastaFormat.h"
#include <vector>

class FastaFileDNA
{
public:
    FastaFileDNA() {}
    void addFastaFormatEntryDNA(FastaFormatDNA *fastaEntry)
    {
        fastaEntries.push_back(fastaEntry);
    }

private:
    std::vector<FastaFormatDNA *> fastaEntries;
};

#endif // FASTA_FILE_H
