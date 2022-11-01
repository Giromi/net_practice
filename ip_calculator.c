/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:34:07 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/02 02:00:19 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// int count_num()
// {
//     int i;
//     while (num)
//         num /= 10;
//     return (cnt);:
// }
//
// char	*my_putdec_char(char *const dec, const char *bin)
// {
//     unsigned char	num = 0;
//     int				idx = 2;
//
//
//     printf("len : %lu\n", strlen(bin));
//     for (char i = strlen(bin) - 1, mask = 1; i >= 0; i--, mask <<= 1) {
//         printf("bit : %d\n", (bin[i] == '1') * mask);
//         num |= (bin[i] == '1') * mask;
//     }
//     printf("num : %d\n", num);
//     num /
//     while (idx >= 0) {
//         printf("idx : %d\n", idx);
//         dec[idx--] = num % 10 + '0';
//         num /= 10;
//     }
//     dec[3] = '\0';
//     return (dec);
// }
//
// int is_bin(char *str)
// {
//     while (*str) {
//         if (*str != '0' && *str != '1')
//             return (0);
//         str++;
//     }
//     return (1);
// }
//
// unsigned char	*my_putbin_char(unsigned char *const bit, int num)
// {
//     for (char i = 7, mask = 1; i >= 0; i--, mask <<= 1)
//         bit[i] = !!(num & mask) + '0';
//     return (bit);
// }
//
// void	print_out_dec_bin(void)
// {
//     int				num = 0;
//     unsigned char	byte_bit[9] = "00000000";
//     char	str[12];
//
//     do {
//         printf("변환할 10 진수 또는 이진수를 적어주세요(0 ~ 255 or 0bXX) or (-1) : ");
//         scanf(" %[^\n]", str);
//         str[11] = '\0';
//         if (strlen(str) > 10) {
//             printf("ERROR: unsigned char 범위 이내로 적어주세요.\n");
//             continue ;
//         }
//         if (!strncmp(str, "0b", 2) || !strncmp(str, "0B", 2)) {
//             if (!is_bin(&str[2])) {
//                 printf("ERROR: 이진법 형태를 제대로 적어주세요.\n");
//                 continue ;
//             }
//             else
//                 printf("변환 결과 : %3s -> %s\n", str, my_putdec_char(str, &str[2]));
//         }
//         else {
//             num = atoi(str);
//             if (0 <= num && num <= 255)
//                 printf("변환 결과 : %3d -> %s\n", num, my_putbin_char(byte_bit, num));
//         }
//     } while (num != -1);
// }

// void	print_out_dec2bin(void)
// {
//     int				num = 0;
//     unsigned char	byte_bit[9] = "00000000";
//
//     do {
//         printf("변환할 10 진수를 적어주세요(0 ~ 255) or (-1) : ");
//         scanf("%d", &num);
//         if (0 <= num && num <= 255)
//             printf("변환 결과 : %3d -> %s\n", num, my_putbin_char(byte_bit, num));
//     } while (num != -1);
// }

unsigned char	*get_bin_ip(unsigned char *const int_bit, int ea) // no space
{
	/*
	 0  1  2  3  4  5  6  7  8
	 9 10 11 12 13 14 15 16 17
	18 19 20 21 22 23 24 25 26
	27 28 29 30 31 32 33 34 35
	*/
	for (int j = 0; j < 32; j++)
		int_bit[j] = (ea-- > 0) + '0';
	return (int_bit);
}

// unsigned char	*my_putip_dec(unsigned char *const str, const unsigned char *int_bit, int ea)
// {
//     unsigned int mask = 1;
//     /*
//      0  1  2  3  4  5  6  7  8
//      9 10 11 12 13 14 15 16 17
//     18 19 20 21 22 23 24 25 26
//     27 28 29 30 31 32 33 34 35
//     */
//     for (int i = 0; i < 4; i++) {
//         for (int j = i * 9; j < 9 * i + 8; j++, mask <<= 1)
//             int_bit[j];
//     }
//     int_bit[35] = '\0';
//     printf("mask : %d\n", mask);
//     return (int_bit);
// }

// unsigned char	*my_putbin_int(unsigned char *const int_bit, int ea)
// {
//     unsigned int mask = 1 << 31;
//     /*
// 1	 0  1  2  3     4     5  6  7  8    9
// 3	10 11 12 13    14    15 16 17 18   19
// 5	20 21 22 23    24    25 26 27 28   29
// 7	30 31 32 33    34    35 36 37 38   39
//     */
//     for (int i = 0; i < 8; i++) {
//         int_bit[5 * i + 4] = !(i % 2) ?  ' ' : '.';
//         for (int j = 5 * i ; j < 5 * i + 4; j++, mask >>= 1)
//             int_bit[j] = (ea-- > 0) + '0';
//     }
//     int_bit[39] = '\0';
//     printf("mask : %d\n", mask);
//     return (int_bit);
// }
//

void	slash_subnet(const char *str, char *const int_bit)
{
	int		cnt_one;

	cnt_one = atoi(&str[1]);
	if (cnt_one < 0 || 32 < cnt_one) {
		printf("ERROR: 알맞은 서브넷 마스크를 기입해주세요.\n");
		return ;
	}
	printf("입력 형태    : %s\n", str);
	printf("이진수 형태  : %s\n", get_bin_ip(int_bit, cnt_one));
	printf("ip 주소 형태 : %s\n", str);
}

char *strchr_last(const char *str, const char chr) {
	if (!str)
		return (NULL);
	while (*str && *str++ != chr);
	return (str);
}

int ip_address_subnet(const char *str, int *const ip_ad)
{
	int		num;
	int		i;

	i = 0;
	while (str) {
		ip_ad[i] = atoi(str);
		if (ip_ad[i] < 0 || 255 < ip_ad[i]) {
			printf("ERROR: 알맞은 서브넷 마스크를 기입해주세요.\n");
			return ;
		}
		str = strchr_last(str, '.');
		str += !!(*str);
	}
}

void print_out_subnet_mask(void)
{
	unsigned char	int_bit[33]; //	32 + 32/8 - 1 + 1 = 32 + 4 = 36 or 40
	char			str[17];
	int				ip_ad[4];

	do {
		printf("서브넷 마스크 주소를 적어주세요(X.X.X.X or /X) or (-1) : ");
		scanf(" %[^\n]", str);
		str[16] = '\0';
		if (strlen(str) > 15) {
			printf("ERROR: 15 글자 이내로 적어주세요.\n");
			continue ;
		}
		if ((str[0] == '/' && slash_subnet(str, int_bit) == -1)  || ip_address_subnet() == -1)
		if (check == -1)
			continue ;
		printf("ip 형태 : %d.%d.%d.%d\n", );
		printf("/  형태 : %s\n", str);
		printf("0B 형태 : %s\n", get_bin_ip(int_bit, ea));
	} while (strcmp(str, "-1"));
}

int main(void)
{
	int		mode;

	do {
		printf("사용할 mode를 입력해주세요.\n");
		printf("% d : ip 주소 출력\n", 1);
		printf("% d : unsigned char 범위 이진수 계산\n", 2);
		printf("% d : ip 주소 &연산\n", 3);
		printf("% d : 프로그램 종료\n", -1);
		printf("------------------------------------\n");
		printf("mode  : ");
		scanf(" %d", &mode);		// 앞 개행, 공백 무시
		// getchar();					// 버퍼 지우기
		// rewind(stdout);
		switch (mode) {
			case 1:
				print_out_ip2bin();
				break ;
			case 2:
				break ;
			case 3:
				break ;
			case -1:
				printf("안녕히 가십시다?... 휴먼... \n");
				break ;
			default:
				printf("잘못된 입력입니다.\n");
		}
	} while (mode != -1);
	return (0);
}
		// for (int i = 0; i <= atoi(argv); i++)
