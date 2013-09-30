/*
    Pattern Matching 
---------------- 
Characters: a to z 
Operators: * + 
* -> matches zero or more (of the character that occurs previous to this operator) 
+ -> matches one or more (of the character that occurs previous to this operator) 

Output if a given pattern matches a string. 
Example: 
pattern:a*b 
string:aaab b, ab, aab, aaab, ab 
output:1 

pattern:a+aabc 
string:ab aabc, aaabc, aaaabc .. 
output:0 

pattern:aa*b*ab+ 
string:aab aab, aabab, aaaabbab 
output:1 

pattern: a+a*b* 
string: a ab, aab, aaabb 
output: 1 

Valid Assumptions: Please assume that both the pattern and string input are valid
 */

int patternMatching(string &s, string &p) {
	int m = s.size();
	int n = p.size();

	string pp = p;

	int i = 0, j = 0;

	char prev = ' ';

	while (i < m && j < n) {
		if (s[i] == pp[j]) {
			i++;
			if (j < n - 1 && pp[j + 1] == '+')
				pp[j + 1] = '*';
			if (j >= n - 1 || (pp[j + 1] != '+' && pp[j + 1] != '*')) {
				j++;
			}
		} else if (j < n - 1 && pp[j + 1] == '*'){
			j += 2;
		} else return 0;
	}

	if (i < m) return 0;
	while (j + 1 < n && pp[j + 1] == '*') j += 2;
	if (j < n) return 0;

	return 1;
}