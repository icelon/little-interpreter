#include <cstdlib>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

enum symbol { NONEsym,
              PROGRAMsym,
              IFsym, 
              ELSEsym, 
              BEGINsym,
              ENDsym, 
              WHILEsym,
              IDENTsym, 
              NUMBERsym, 
              OPERATORsym,
              PRINTsym,
              PRINTLNsym,
              INPUTsym,
              OUTPUTsym };

char lookahead;

ifstream *input_stream;
int row = 1;

bool recording = false;
string record_buffer = "";

bool reproducing = false;
string reproduce_buffer = "";

symbol token;
string value;
int num_value;

map<string, symbol> keywords;
map<string, int> variables;

void abort(string error_message) 
{
        cerr << endl;
        cerr << "Error: " << error_message << "." << endl;
        cerr << "[row " << row << "]" << endl;
        exit(1);
}

void expected(string expected_message) 
{
        cerr << expected_message << " expected." << endl;
        cerr << "[row " << row << "]" << endl;
        exit(1);
}

void next_char() 
{
        if (reproducing) 
        {
                lookahead = reproduce_buffer[0];
                reproduce_buffer.erase(0, 1);
        } else 
        {
                lookahead = static_cast<char>(input_stream->get());
                if (lookahead == '\n') ++row;
        }
        if (recording) record_buffer += lookahead;
        
        if (lookahead == '#') while (lookahead != '\n') next_char();
}

void skip_white() 
{
        while (isspace(lookahead) && (lookahead != '\n')) next_char();
}

void skip_white_newline() 
{
        while (isspace(lookahead)) next_char();
}

void match(char to_match) 
{
        if (to_match == lookahead) 
        {
                next_char();
                skip_white();
        } else expected(string("\"") + to_match + "\"");
}

bool isaddop(char c) 
{
        return ((c == '+') || (c == '-'));
}

bool ismulop(char c) 
{
        return ((c == '*') || (c == '/')) || (c == '%');
}

bool isbop(char c) 
{
        return ((c == '|') || (c == '&'));
}

bool isrop(char c) 
{
        return ((c == '=') ||
                (c == '<') ||
                (c == '>'));
}

bool isop(char c) 
{
        return ((c == '+') ||
                (c == '-') ||
                (c == '*') ||
                (c == '/') ||
                (c == '%') ||
                (c == '(') ||
                (c == ')') ||
                (c == '<') ||
                (c == '>') ||
                (c == '|') ||
                (c == '&') ||
                (c == '!') ||
                (c == '<') ||
                (c == '>') ||
                (c == '='));
}

symbol get_keyword(string name) 
{
        map<string, symbol>::iterator i = keywords.find(name);
        return i != keywords.end() ? i->second : NONEsym;
}

void get_name_string() 
{
        value = "";
        if (lookahead!='"') expected("string");
        next_char();
        while (lookahead!='"')
        {
                value += (char)(lookahead);
                next_char();
        }
        skip_white();
        next_char();
        
        skip_white();
}

void get_name() 
{
        value = "";
        if (!isalpha(lookahead)) expected("Name");
        while (isalnum(lookahead) || (lookahead == '_')) 
        {
                value += (char)toupper(lookahead);
                next_char();
        }
        
        symbol k = get_keyword(value);
        if (k == NONEsym) token = IDENTsym;
        else token = k;
        
        skip_white();
}

void get_number() 
{
        value = "";
        num_value = 0;
        if (!isdigit(lookahead)) expected("Integer");
        while (isdigit(lookahead)) 
        {
                value += lookahead;
                
                num_value = num_value * 10 + lookahead - '0';
                
                next_char();
        }
        token = NUMBERsym;
        skip_white();
}

void get_operator() 
{
        value = "";
        if (!isop(lookahead)) expected("Operator");
        while (isop(lookahead)) 
        {
                value += lookahead;
                next_char();
        }
        token = OPERATORsym;
        skip_white();
}

void scan() 
{
        skip_white_newline();
        if (isalpha(lookahead)) get_name();
        else if (isdigit(lookahead)) get_number();
        else if (isop(lookahead)) get_operator();
        else abort("Unexpected token: '" + value + "'.");
        skip_white();
}

int get_var(string name) 
{
        map<string, int>::iterator i = variables.find(name);
        if (i == variables.end()) abort(name + " not found.");
        return i->second;
}

int relation();

int factor() 
{
        int result;
        if (lookahead == '(') 
        {
                match('(');
                result = relation();
                match(')');
        } 
        else if (lookahead == '!') 
        {
                match('!');
                return !factor();
        } 
        else 
        {
                scan();
                if (token == NUMBERsym) result = num_value;
                else result = get_var(value);
        }
        return result;
}

int term() 
        {
        int result = factor();
        while (ismulop(lookahead)) 
        {
                get_operator();
                if (value == "*") result *= factor();
                else if (value == "/") result /= factor();
                else if (value == "%") result %= factor();
        }
        return result;
}

int expression() 
{
        int result;
        if (isaddop(lookahead)) result = 0;
        else result = term();
        while (isaddop(lookahead)) 
        {
                get_operator();
                if (value == "+") result += term();
                else if (value == "-") result -= term();
        }
        return result;
}

int b_expression() {
        int result = expression();
        while (isbop(lookahead)) 
        {
                get_operator();                
                if (value == "|") result = expression() || result;
                else if (value == "&") result = expression() && result;
        }
        return result;
}

int relation() 
{
        int result = b_expression();
        while (isrop(lookahead)) 
        {
                get_operator();
                if (value == "<") result = result < b_expression();
                else if (value == ">") result = result > b_expression();
                else if (value == "<=") result = result <= b_expression();
                else if (value == ">=") result = result >= b_expression();
                else if (value == "==") result = result == b_expression();
                else if (value == "<>") result = result != b_expression();
        }
        return result;
}

void assignment() 
{
        string var = value;
        match('=');
        variables[var] = relation();
}

void input() 
{
        get_name();
        cout << "INPUT(" << value << "): ";
        int n;
        cin >> n;
        variables[value] = n;
}

void output() 
{
        get_name();
        cout << "ans = " << value << " -> " << get_var(value) << endl;
}


void print() 
{
        string nl="\\n";

        skip_white();
        //cout << "# ";
        if (lookahead=='"')
           {
           get_name_string();
           if (value.compare(nl) == 0)
              {
              cout << endl;
              }
           else
              {
              //cout << "[" << value << "]";
              cout << value;
              }
           }
        else
           {
           get_name();
           cout << value << "= " << get_var(value) << " ";
           //cout << endl;
           }

        /*
         * something more to print
         */
        if (lookahead==',')
           {
           next_char();
           print();
           }
}

void println() 
{
              print();
              cout << endl;
}


void avoid_internal_blocks() 
{
        int count = -1;
        while ((token != ENDsym) || (count > 0)) 
        {
                if (token == BEGINsym) ++count;
                else if (token == ENDsym) --count;
                skip_white_newline();
                scan();
        }
}

void block();

void conditional() 
{
        if (token != IFsym) expected("If");
        else 
        {
                int truth = relation();
                if (truth) block();
                else avoid_internal_blocks();
                skip_white_newline();
                get_name();
                if (token == ELSEsym) 
                {
                        if (truth) avoid_internal_blocks();
                        else block();
                        skip_white_newline();
                        get_name();
                }
        }
}

void repetition_exec(string saved) 
{
        int truth = 1;
        while (truth) 
        {
                string old_buffer = reproduce_buffer;
                reproduce_buffer = saved;
                reproducing = true;
                next_char();
                truth = relation();
                if (truth) block();
                else avoid_internal_blocks();
                if (old_buffer == "") reproducing = false;
                reproduce_buffer = old_buffer;
        }
}

void repetition() 
{
        if (token != WHILEsym) expected("While");
        else {
                record_buffer = "";
                recording = true;
                record_buffer = lookahead + record_buffer;
                int truth = relation();
                avoid_internal_blocks();
                recording = false;
                if (truth) repetition_exec(record_buffer);
        }
}

void block() 
{
        skip_white_newline();
        get_name();
        if (token != BEGINsym) expected("Begin");
        bool ifsym;
        while (token != ENDsym)  
        {
                ifsym = false;
                switch (token) 
                {
                case BEGINsym: break;
                case IFsym: conditional(); ifsym = true; break;
                case WHILEsym: repetition(); break;
                case PRINTsym: print(); break;
                case PRINTLNsym: println(); break;
                case OUTPUTsym: output(); break;
                case INPUTsym: input(); break;
                case IDENTsym: assignment(); break;
                default: abort("\"" + value + "\": undefined symbol.");
                }
                if(!ifsym) scan();
        }
}

void program() {
        skip_white_newline();
        next_char();
        get_name();
        if (token != PROGRAMsym) expected("Program");
        get_name();
        if (token != IDENTsym) abort("Incorrect program name");
        cout << "Running " << value << endl << endl;
        block();
        cout << endl << "Bye bye... Thank you for using me!" << endl;
}

int main(int argc, char *argv[]) 
{
        
        if (argc == 2) 
        {
                input_stream = new ifstream();
                input_stream->open(argv[1]);
                if (input_stream->fail()) 
                {
                        delete input_stream;
                        abort("Unable to open input file.");
                }
        } 
        else abort("You must specify the input file.");
        
        keywords["PROGRAM"] = PROGRAMsym;
        keywords["IF"] = IFsym;
        keywords["ELSE"] = ELSEsym;
        keywords["BEGIN"] = BEGINsym;
        keywords["END"] = ENDsym;
        keywords["WHILE"] = WHILEsym;
        keywords["INPUT"] = INPUTsym;
        keywords["OUTPUT"] = OUTPUTsym;
        keywords["PRINT"] = PRINTsym;
        keywords["PRINTLN"] = PRINTLNsym;
        
        program();

        input_stream->close();
        delete input_stream;

return 0;
}

