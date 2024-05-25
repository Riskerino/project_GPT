#include "FastaParser.h"
#include "Nucleotide.h"
#include "FastaHeader.h"
#include "Sequence.h"
#include "FastaFormat.h"
#include "FastaFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace Utility;

std::string Utility::readNextCSString(std::stringstream &ss)
{
    std::string strField;
    getline(ss, strField, ',');

    auto start = strField.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    auto end = strField.find_last_not_of(" \t");
    return strField.substr(start, end - start + 1);
}

void Utility::parseStringToNucleotideSequence(const std::string &seqLineAsString, NucleotideSequence *subseq) {
    std::cout << "\n>> Parsing string to Seq-Object : " << seqLineAsString << std::endl;
    for (auto n : seqLineAsString) {
        if (n == 'A') { 
            auto adenin = new Adenin("0");
            subseq->addNucleotideToSequence(adenin);
        }
        if (n == 'T') { 
            auto thymin = new Thymin("0");
            subseq->addNucleotideToSequence(thymin);
        }
        if (n == 'G') { 
            auto guanin = new Guanin("0");
            subseq->addNucleotideToSequence(guanin);
        }
        if (n == 'C') { 
            auto cytosin = new Cytosin("0");
            subseq->addNucleotideToSequence(cytosin);
        }
    }
}

void Utility::readDNAFastaFormatFromFile(const std::string &i_strFileName, FastaFileDNA *newFastaFile)
{
    std::ifstream fFasta(i_strFileName);
    char seperator = '>';
    if (fFasta.is_open())
    {
        std::string strLine;
        std::string currentSequence;
        std::string currentHeader;

        while (getline(fFasta, strLine))
        {
            if (strLine[0] == seperator)
            {
                if (!currentSequence.empty() && !currentHeader.empty())
                {
                    auto *fasta = new FastaFormatDNA(0);
                    auto *head = new FastaHeader();
                    auto *seq = new NucleotideSequence();
                    parseStringToNucleotideSequence(currentSequence, seq);

                    head->setHeader(currentHeader);
                    fasta->setFastaHeader(head);
                    fasta->setFastaSequence(seq);
                    newFastaFile->addFastaFormatEntryDNA(fasta);

                    currentSequence.clear();
                }

                currentHeader = strLine;
            }
            else
            {
                currentSequence += strLine;
            }
        }

        // Add the last sequence
        if (!currentSequence.empty() && !currentHeader.empty())
        {
            auto *fasta = new FastaFormatDNA(0);
            auto *head = new FastaHeader();
            auto *seq = new NucleotideSequence();
            parseStringToNucleotideSequence(currentSequence, seq);

            head->setHeader(currentHeader);
            fasta->setFastaHeader(head);
            fasta->setFastaSequence(seq);
            newFastaFile->addFastaFormatEntryDNA(fasta);
        }

        fFasta.close();
    }
    else
    {
        std::cout << "Could not find file" << std::endl;
    }
}
