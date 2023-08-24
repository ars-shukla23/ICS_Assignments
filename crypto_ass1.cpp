#include<iostream>
#include<string>


using namespace std;

char sample[26];

int is_a_letter(char c){
    int num=0;
    for(int i=0;i<26;i++){
        if(c==sample[i]){
            num=1;
        }
    }
    return num;
}

int addr_of_letter(char c){
    int val;
    for(int i=0;i<26;i++){
        if (sample[i]==c){
           val=i;
    }
    
 }
 return val;
}

string caesar_encrypt(string st,int shift){
    string final_string;
    for(int i=0;i<st.length();i++){
        char c=st[i];
        if (is_a_letter(c)==1){
             int add=addr_of_letter(c);
             char enc=sample[(add+shift) % 26];
             final_string.push_back(enc);
             
            
        }
        else if (is_a_letter(c)==0){
              final_string.push_back(c);
        }
    }
    return final_string;
}

string caesar_decrypt(string st,int shift){
  string final_string;
  for(int i=0;i<st.length();i++){
     char c=st[i];
     if (is_a_letter(c)==1){
      int add=addr_of_letter(c);
      char dec=sample[(add-shift+26) % 26];
      final_string.push_back(dec);
     }
     else if(is_a_letter(c)==0){
      final_string.push_back(c);

     }
  }
  return final_string;

}

int main(){
   for(int i=0;i<26;i++){
    sample[i]=char(97+i);
}
 
    
   int op;
   do{
     cout<<"Enter your choice(1 or 2):\n1)Caesar\n2)RailFence\n3)Exit\n";
     cin>>op;
     if (op==1){
          int ch1;
          cout<<"What do you want to perform(1 or 2):\n1)Encrypt\n2)Decrypt\n";
          cin>>ch1;
          if (ch1==1){
            string str;
            int shift;
            cout<<"Enter the shift value:";
            cin>>shift;
            cout<<"Enter the string you want to encrypt:";
            cin>>str;
            string encryted_str=caesar_encrypt(str,shift);
            cout<<"The encrypted string is:"<<encryted_str<<endl;
          }
          else if (ch1==2){
            string str;
            int shift;
            cout<<"Enter your shift value:";
            cin>>shift;
            cout<<"Enter the string value you want to decrpyt:";
            cin>>str;
            
           string decrypted_str=caesar_decrypt(str,shift);
           cout<<"The decrypted string is: "<<decrypted_str<<endl;
          }
     }
     else if (op==2){
         int ch2;
          cout<<"What do you want to perform(1 or 2):\n1)Encrypt\n2)Decrypt\n";
          cin>>ch2;
          if (ch2==1){
            cout<<"Rail Fence Encryption";
          }
          else if(ch2==2){
            cout<<"Rail Fence Decryption";
          }
     }
   }while (op!=3);
  



    return 0;
}