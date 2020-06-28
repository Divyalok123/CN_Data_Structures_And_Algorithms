// Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.


#include <iostream>
using namespace std;

void swap(char*a, char*b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void reverse(char* begin, char* end) 
{ 
	while (begin < end) { 
		swap(begin, end); 
        begin++;
        end--;
	} 
} 

 
void reverseStringWordWise(char* s) 
{ 
	char* word_begin = s; 
	char* temp = s; 
	while (*temp) { 
		temp++; 
		if (*temp == '\0') { 
			reverse(word_begin, temp - 1); 
		} 
		else if (*temp == ' ') { 
			reverse(word_begin, temp - 1); 
			word_begin = temp + 1; 
		} 
	}  
	reverse(s, temp - 1); 
}

// void reverseStringWordWise(char input[])
// {
//     int length = len(input);
//     reverse(input, 0, length);
//     int i = 0;
//     int j = 0;
//     while (input[i])
//     {
//         j++;
//         if (input[j] == '\0')
//         {
//             reverse(input, i, j);
//         }
//         else if (input[j] == ' ')
//         {
//             reverse(input, i, j);
//             i = j + 1;
//         }
//     }

//     reverse(input, i, length + 1);
// }

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
