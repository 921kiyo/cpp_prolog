cerr :: error 

lsof: list open file

putback : changing the value of the buffer that OS uses to read it

peek: return the next character in the input sequence, without exgtracting it from the stream.

instread of eof, you could use fail or good, or 
while(in_stream)
while(!input.fail())


By default, it skips all the whitespace
input.unsetf(ios::skipws)

while((input>> number).good()){
    cout << number;
}


ostream : cout

ifstream& in, ostream& out : have to be reference, because OS is monitoring only one file.


ostream is more general version of ofstream. ofstream only works for output FILE