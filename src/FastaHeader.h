#ifndef FASTA_HEADER_H
#define FASTA_HEADER_H
#include <iostream>
#include <string>

class FastaHeader
{
public:
    void setHeader(const std::string &header) { this->header = header; }
    std::string getHeader() const { return header; }

private:
    std::string header;
};

#endif // FASTA_HEADER_H
