#ifndef MP4READER_H
#define MP4READER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
class MP4Box;

class MP4Reader
{
private:
    unsigned int      m_currentLocation;
    MP4Box           *m_topNode;
    char             *m_bytes;
    unsigned int      m_length;
    unsigned int      m_nextBoxAt;
public:
    MP4Reader(char *bytes, unsigned int length, MP4Box *parent);
    void readBoxes();
    void readHeader(unsigned int &length, string &type);
    void readBytes(int numBytes, void *destination);
    void skipBytes(int numBytes);
    int readInt();
    unsigned int readUInt();
    short readShort();
    unsigned short readUShort();
    char readChar();
    unsigned char readUChar();
    string read4Chars();
    void readPString();
    string readUTF8(int length);
    void readUIntArray(int length, unsigned int *array);
    void newBoxLength(unsigned int length);
    void skipRemainingBytes();
    unsigned int remainingBytes();
    MP4Reader *subReader(MP4Box *parent);
};

class MP4FileReader
{
private:
    string   m_filename;
    ifstream m_file;
    int      m_totalNumberOfBytes;
    char    *m_bytes;

    bool open();
    void ensureOpen();
    void readBytesFromFile(int numBytes);
public:
    MP4FileReader(string filename, int totalNumberOfBytes);
    void read();
};

#endif // MP4READER_H
