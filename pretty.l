%top{
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#define INDENT (4)
%}
%class{
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

%}
%init{
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

%}

quote							\'
notquote					[^\']
ditto						\"
notditto					[^\"]
digit 						[0-9]
oct 						[0-7]
exp 						[eE][+-]?{digit}+
hex 						{digit}|[a-fA-F]
alpha 						[a-zA-Z_]
operator 					(\+\+)|(\-\-)|(==)|(!=)|(<=)|(>=)|(&&)|(\|\|)|(<<|>>)|(\+=)|(\-=)|(\*=)|(\/=)|(%=)|(<<=)|(>>=)|(&=)|(\^=)|(\|=)|(\?)|(\:)|\+|\-|\*|\/|%|<|>|!|&|\||\^|~|=
punctuation 				(\:\:)|(\.\.\.)|,|(\.)|(\*)+
multiline_comment 			\/\*(.|\n)*?\*\/
inline_multiline_comment	\/\*(.|\n)*?\*\/\n
inline_comment 				\/\/.*
directive 					\#.*

%%
{quote}({notquote}|(\\{quote}))*{quote}					write_char();
{ditto}({notditto}|\\{ditto})*{ditto}					write_string();
"0"{oct}+												write_oct();
"0"[xX]{hex}+											write_hex();
{digit}+												write_int();
{digit}*\.{digit}*({exp})?								write_fp();
{alpha}({alpha}|{digit})*								write_id();
"{"														write_begin();
"}"														write_end();
"("														write_open();
")"														write_close();
"["														write_bopen();
"]"														write_bclose();
";"														write_sep();
{punctuation}|{operator}								write_op();
{inline_multiline_comment}|{multiline_comment}										write_comment();
{inline_comment}										write_inline();
{directive}												write_directive();
[ \t\v\n\r\f]											
.														{printf("Character_Not_Known");}

%%
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
