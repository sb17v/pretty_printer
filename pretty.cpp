// pretty.cpp generated by reflex 1.0.0 from pretty.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_flex                true
#define REFLEX_OPTION_lex                 yylex
#define REFLEX_OPTION_lexer               yyFlexLexer
#define REFLEX_OPTION_outfile             pretty.cpp
#define REFLEX_OPTION_prefix              yy

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top{ user code %}                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 1 "pretty.l"

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#define INDENT (4)


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FLEX-COMPATIBLE DEFINITIONS                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define INITIAL (0)
#define YY_NUM_RULES (20)

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FLEX-COMPATIBLE ABSTRACT LEXER CLASS                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/flexlexer.h>
typedef reflex::FlexLexer<reflex::Matcher> FlexLexer;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class yyFlexLexer : public FlexLexer {
#line 8 "pretty.l"

int line;
int column;
int paren;
int bracket;
std::map<std::string, int> symbol_table;
void write_indent();
void write_html_char(int c);
void write_html();
void write_char();
void write_string();
void write_oct();
void write_hex();
void write_int();
void write_fp();
void write_id();
void write_begin();
void write_end();
void write_open();
void write_close();
void write_bopen();
void write_bclose();
void write_sep();
void write_op();
void write_inline();
void write_comment();
void write_directive();


 public:
  yyFlexLexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream        *os    = NULL)
    :
      FlexLexer(input, os)
  {
#line 37 "pretty.l"

line = 1;
column = 4;
paren = 0;
bracket = 0;
symbol_table["auto"] = 1;
symbol_table["break"] = 1;
symbol_table["case"] = 1;
symbol_table["char"] = 1;
symbol_table["const"] = 1;
symbol_table["continue"] = 1;
symbol_table["default"] = 1;
symbol_table["do"] = 1;
symbol_table["double"] = 1;
symbol_table["else"] = 1;
symbol_table["enum"] = 1;
symbol_table["extern"] = 1;
symbol_table["float"] = 1;
symbol_table["for"] = 1;
symbol_table["goto"] = 1;
symbol_table["if"] = 1;
symbol_table["inline"] = 1;
symbol_table["int"] = 1;
symbol_table["long"] = 1;
symbol_table["register"] = 1;
symbol_table["restrict"] = 1;
symbol_table["return"] = 1;
symbol_table["short"] = 1;
symbol_table["signed"] = 1;
symbol_table["sizeof"] = 1;
symbol_table["static"] = 1;
symbol_table["struct"] = 1;
symbol_table["switch"] = 1;
symbol_table["typedef"] = 1;
symbol_table["union"] = 1;
symbol_table["unsigned"] = 1;
symbol_table["void"] = 1;
symbol_table["volatile"] = 1;
symbol_table["while"] = 1;
symbol_table["_Alignas"] = 1;
symbol_table["_Alignof"] = 1;
symbol_table["_Atomic"] = 1;
symbol_table["_Bool"] = 1;
symbol_table["_Complex"] = 1;
symbol_table["_Generic"] = 1;
symbol_table["_Imaginary"] = 1;
symbol_table["_Noreturn"] = 1;
symbol_table["_Static_assert"] = 1;
symbol_table["_Thread_local"] = 1;
symbol_table["alignas"] = 1;
symbol_table["alignof"] = 1;
symbol_table["atomic_bool"] = 1;
symbol_table["atomic_int"] = 1;
symbol_table["bool"] = 1;
symbol_table["complex"] = 1;
symbol_table["imaginary"] = 1;
symbol_table["noreturn"] = 1;
symbol_table["static_assert"] = 1;
symbol_table["thread_local"] = 1;


  }
  virtual int yylex();
  int yylex(
      const reflex::Input& input,
      std::ostream        *os = NULL)
  {
    in(input);
    if (os)
      out(*os);
    return yylex();
  }
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int yyFlexLexer::yylex()
{
  static const reflex::Pattern PATTERN_INITIAL("(?m)((?:')(?:(?:[^'])|(?:\\\\(?:')))*(?:'))|((?:\")(?:(?:[^\"])|\\\\(?:\"))*(?:\"))|((?:\\Q0\\E)(?:[0-7])+)|((?:\\Q0\\E)[Xx](?:(?:[0-9])|[A-Fa-f])+)|((?:[0-9])+)|((?:[0-9])*\\.(?:[0-9])*(?:(?:[Ee][\\x2b\\x2d]?(?:[0-9])+))?)|((?:[A-Z_a-z])(?:(?:[A-Z_a-z])|(?:[0-9]))*)|((?:\\Q{\\E))|((?:\\Q}\\E))|((?:\\Q(\\E))|((?:\\Q)\\E))|((?:\\Q[\\E))|((?:\\Q]\\E))|((?:\\Q;\\E))|((?:(?:::)|(?:\\.\\.\\.)|,|(?:\\.)|(?:\\*)+)|(?:(?:\\+\\+)|(?:--)|(?:==)|(?:!=)|(?:<=)|(?:>=)|(?:&&)|(?:\\|\\|)|(?:<<|>>)|(?:\\+=)|(?:-=)|(?:\\*=)|(?:/=)|(?:%=)|(?:<<=)|(?:>>=)|(?:&=)|(?:\\^=)|(?:\\|=)|(?:\\?)|(?::)|\\+|-|\\*|/|%|<|>|!|&|\\||\\^|~|=))|((?:/\\*(?:.|\\n)*?\\*/\\n)|(?:/\\*(?:.|\\n)*?\\*/))|((?://.*))|((?:#.*))|([\\x09-\\x0d\\x20])|(.)");
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
    YY_USER_INIT
  }
  while (true)
  {
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
              return 0;
            }
            else
            {
              output(matcher().input());
            }
            YY_BREAK
          case 1: // rule at line 116: (?:')(?:(?:[^'])|(?:\\(?:')))*(?:')
            YY_USER_ACTION
#line 116 "pretty.l"
write_char();
            YY_BREAK
          case 2: // rule at line 117: (?:")(?:(?:[^"])|\\(?:"))*(?:")
            YY_USER_ACTION
#line 117 "pretty.l"
write_string();
            YY_BREAK
          case 3: // rule at line 118: (?:\Q0\E)(?:[0-7])+
            YY_USER_ACTION
#line 118 "pretty.l"
write_oct();
            YY_BREAK
          case 4: // rule at line 119: (?:\Q0\E)[Xx](?:(?:[0-9])|[A-Fa-f])+
            YY_USER_ACTION
#line 119 "pretty.l"
write_hex();
            YY_BREAK
          case 5: // rule at line 120: (?:[0-9])+
            YY_USER_ACTION
#line 120 "pretty.l"
write_int();
            YY_BREAK
          case 6: // rule at line 121: (?:[0-9])*\.(?:[0-9])*(?:(?:[Ee][\x2b\x2d]?(?:[0-9])+))?
            YY_USER_ACTION
#line 121 "pretty.l"
write_fp();
            YY_BREAK
          case 7: // rule at line 122: (?:[A-Z_a-z])(?:(?:[A-Z_a-z])|(?:[0-9]))*
            YY_USER_ACTION
#line 122 "pretty.l"
write_id();
            YY_BREAK
          case 8: // rule at line 123: (?:\Q{\E)
            YY_USER_ACTION
#line 123 "pretty.l"
write_begin();
            YY_BREAK
          case 9: // rule at line 124: (?:\Q}\E)
            YY_USER_ACTION
#line 124 "pretty.l"
write_end();
            YY_BREAK
          case 10: // rule at line 125: (?:\Q(\E)
            YY_USER_ACTION
#line 125 "pretty.l"
write_open();
            YY_BREAK
          case 11: // rule at line 126: (?:\Q)\E)
            YY_USER_ACTION
#line 126 "pretty.l"
write_close();
            YY_BREAK
          case 12: // rule at line 127: (?:\Q[\E)
            YY_USER_ACTION
#line 127 "pretty.l"
write_bopen();
            YY_BREAK
          case 13: // rule at line 128: (?:\Q]\E)
            YY_USER_ACTION
#line 128 "pretty.l"
write_bclose();
            YY_BREAK
          case 14: // rule at line 129: (?:\Q;\E)
            YY_USER_ACTION
#line 129 "pretty.l"
write_sep();
            YY_BREAK
          case 15: // rule at line 130: (?:(?:::)|(?:\.\.\.)|,|(?:\.)|(?:\*)+)|(?:(?:\+\+)|(?:--)|(?:==)|(?:!=)|(?:<=)|(?:>=)|(?:&&)|(?:\|\|)|(?:<<|>>)|(?:\+=)|(?:-=)|(?:\*=)|(?:/=)|(?:%=)|(?:<<=)|(?:>>=)|(?:&=)|(?:\^=)|(?:\|=)|(?:\?)|(?::)|\+|-|\*|/|%|<|>|!|&|\||\^|~|=)
            YY_USER_ACTION
#line 130 "pretty.l"
write_op();
            YY_BREAK
          case 16: // rule at line 131: (?:/\*(?:.|\n)*?\*/\n)|(?:/\*(?:.|\n)*?\*/)
            YY_USER_ACTION
#line 131 "pretty.l"
write_comment();
            YY_BREAK
          case 17: // rule at line 132: (?://.*)
            YY_USER_ACTION
#line 132 "pretty.l"
write_inline();
            YY_BREAK
          case 18: // rule at line 133: (?:#.*)
            YY_USER_ACTION
#line 133 "pretty.l"
write_directive();
            YY_BREAK
          case 19: // rule at line 134: [\x09-\x0d\x20]
            YY_USER_ACTION
#line 134 "pretty.l"
            YY_BREAK
          case 20: // rule at line 135: .
            YY_USER_ACTION
#line 135 "pretty.l"
{printf("Character_Not_Known");}

            YY_BREAK
        }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 138 "pretty.l"
int main()
{
	printf("<html><pre>\n");
	yyFlexLexer().yylex();
	printf("\n</pre></html>\n");
	return 0;
}

void yyFlexLexer::write_indent()
{
	printf("\n%-*d", column, line++);
}

void yyFlexLexer::write_html_char(int c)
{
	switch (c)
	{
		case '<': printf("&lt;"); break;
		case '>': printf("&gt;"); break;
		case '"': printf("&quot;"); break;
		case '&': printf("&amp;"); break;
		case '\n': break; // we don't want newlines to show up in HTML PRE blocks
		default: putchar(c);
	}
}

void yyFlexLexer::write_html()
{
	char *s = yytext;
	while (*s)
		write_html_char(*s++);
}

void yyFlexLexer::write_char(){
	printf("<u><font color = \"brown\">");
	write_html();
	printf("</font></u>");
	putchar(' ');
}

void yyFlexLexer::write_string(){
	printf("<font color = \"red\">");
	write_html();
	printf("</font>");
	putchar(' ');
}

void yyFlexLexer::write_oct(){
	printf("<i><font color = \"brown\">");
	write_html();
	printf("</font></i>");
	putchar(' ');
}

void yyFlexLexer::write_hex(){
	printf("<i><font color = \"brown\">");
	write_html();
	printf("</font></i>");
	putchar(' ');
}

void yyFlexLexer::write_int(){
	printf("<font color = \"brown\">");
	write_html();
	printf("</font>");
	putchar(' ');
}

void yyFlexLexer::write_fp(){
	printf("<font color = \"brown\">");
	write_html();
	printf("</font>");
}

void yyFlexLexer::write_id(){
	std::string yyString = yytext;
	if(symbol_table.find(yytext) == symbol_table.end()){
		symbol_table[yyString] = 2;

		printf("<a name = \"%s\"><font color = \"blue\">", yytext);
		write_html();
		printf("</font></a>");
	}else{
		if(symbol_table[yyString] == 1){
			printf("<b><font color = \"blue\">");
			write_html();
			printf("</font></b>");
		} else{
			printf("<a href = \"#%s\"><font color = \"blue\">", yytext);
			write_html();
			printf("</font></a>");
		}
	}
	putchar(' ');
}

void yyFlexLexer::write_op(){
	printf("<b><font color = \"black\">");
	write_html();
	printf("</font></b>");
	putchar(' ');
}

void yyFlexLexer::write_sep()
{
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	if (!paren && !bracket)
		write_indent();
	else
		putchar(' ');
}

void yyFlexLexer::write_begin()
{
	write_indent();
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	column += INDENT;
	write_indent();
}

void yyFlexLexer::write_end()
{
	column -= INDENT;
	write_indent();
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	write_indent();

}

void yyFlexLexer::write_open()
{
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	putchar(' ');
	paren++;
}

void yyFlexLexer::write_close()
{
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	putchar(' ');
	paren--;
}

void yyFlexLexer::write_bopen(){
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	putchar(' ');
	bracket++;
}
void yyFlexLexer::write_bclose(){
	printf("<b><font color=\"black\">");
    write_html();
    printf("</font></b>");
	putchar(' ');
	bracket--;
}

void yyFlexLexer::write_inline(){
	if(line == 1){
		write_indent();
	}
	printf("<font color = \"green\">");
	printf(yytext);
	printf("</font>");
	write_indent();
}

void yyFlexLexer::write_comment(){
	if(line == 1){
		write_indent();
	}

	if(yytext[yyleng-1] == '\n'){
		printf("<font color = \"green\">");
		printf("%.*s",(int)(yyleng-1),yytext);
		printf("</font>");
		write_indent();
	}else{
		printf("<font color = \"green\">");
		printf(yytext);
		printf("</font>");
	}

}

void yyFlexLexer::write_directive(){
	if(line == 1){
		write_indent();
	}
	printf("<b><font color = \"magenta\">");
	write_html();
	printf("</font></b>");
	write_indent();
}
