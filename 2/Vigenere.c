#include <stdio.h>

int j_string(char*);
void change(char*,char*,int);

// Vigenere
// ��ƥ[�K --- key: �r��
int main(int argc, char *argv[])
{
    char *key = argv[1];
    
    if( argc == 2 && j_string(key)== 1 )
    {
        printf("\nVigenere\nKey:%s\nPlaintext:\t",key);
    
        int size = 50;
        char p_c [size];
        char *p_text = p_c;
    
        // ��J���
        scanf("%[^\n]", p_text);
     
        // �[�K����
        printf("Ciphertext:\t");
		change(key,p_text,size);
    }
    return 0;
}

// �P�_�O�_�����r��
// �ư������Ʀr
int j_string(char *j_key)
{
	int judge = 1;
	
	int j_length =0;
	while(*j_key != '\0')
	{
		if((int)*j_key >= 48 && (int)*j_key <= 57)
		{
			judge = 0;
			break;
		}
		j_key ++;
		j_length ++;
	}	
	j_key -= j_length;
	
	return judge;
}

// �첾
void change(char *s_key,char *c_c,int c_size)
{
	// �p�� key ����
    int s_length =0;
	while(*s_key != '\0')
	{
		s_key++;
		s_length++;	
	}	
	s_key -= s_length;
	
	// key �q�r����Ʀr
	int code[s_length];
	int i =0;
	for(i = 0;i<s_length;i++)
	{
		// 97 �� a
		code[i] = (int) *s_key - 97;
		s_key ++;
	}
	s_key -= s_length;
	
	
	// ��ƥ[�K
	int check =0;
	int code_index = 0;
	for(i = 0;i<c_size;i++)
	{
		// �P�_�j�p�g
		check = (int)*c_c;
		if( (check >= 65 && check <= 90) || (check >= 97 && check <= 122) )
		{
			// �P�_�j�p�g
			if(check >= 97)
			{
				// �p�g
				check -= 96;
			}
			else if(check >= 65)
			{
				// �j�g
				check -= 64;
			}
			
			// �P�_�O�_�W�X�d��
			if (check + code[code_index%s_length] >26)
			{
				*c_c += code[code_index%s_length]-26;
			}
			else
			{
				*c_c += code[code_index%s_length];
			}
			code_index ++;
		}
		c_c ++;
	}
	c_c -= c_size;
	
	printf("%s\n",c_c);

}