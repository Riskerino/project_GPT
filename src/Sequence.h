#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include "Nucleotide.h"
#include <vector>

class NucleotideSequence
{
public:
    void addNucleotideToSequence(Nucleotide *nucleotide)
    {
        sequence.push_back(nucleotide);
    }

    void printSequence() const
    {
        for (const auto &nucleotide : sequence)
        {
            std::cout << nucleotide->getType();
        }
        std::cout << std::endl;
    }

private:
    std::vector<Nucleotide *> sequence;
};

#endif // SEQUENCE_H
