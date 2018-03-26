/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:18:42 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 18:42:58 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H
# define LINUX

# ifdef LINUX

#  define KEY_ESC			65307
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_F				102
#  define KEY_H				104
#  define KEY_G				103
#  define KEY_Z				122
#  define KEY_X				120
#  define KEY_C				99
#  define KEY_V				118
#  define KEY_B				198
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_R				114
#  define KEY_Y				121
#  define KEY_T				116
#  define KEY_ONE			49
#  define KEY_TWO			50
#  define KEY_THREE			51
#  define KEY_FOUR			52
#  define KEY_SIX			54
#  define KEY_FIVE			53
#  define KEY_NINE			57
#  define KEY_SEVEN			55
#  define KEY_EIGHT			56
#  define KEY_ZERO			48
#  define KEY_BRACE_R		93
#  define KEY_O				111
#  define KEY_U				117
#  define KEY_BRACE_L		91
#  define KEY_I				105
#  define KEY_P				112
#  define KEY_L				108
#  define KEY_J				106
#  define KEY_K				107
#  define KEY_SEMI			39
#  define KEY_N				110
#  define KEY_M				109
#  define KEY_TAB			65289
#  define KEY_PLUS			61
#  define KEY_MINUS			45
#  define KEY_LEFT			65361
#  define KEY_RIGHT			65363
#  define KEY_DOWN			65364
#  define KEY_UP			65362

# elif MACOS

#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_F				3
#  define KEY_H				4
#  define KEY_G				5
#  define KEY_Z				6
#  define KEY_X				7
#  define KEY_C				8
#  define KEY_V				9
#  define KEY_B				11
#  define KEY_Q				12
#  define KEY_W				13
#  define KEY_E				14
#  define KEY_R				15
#  define KEY_Y				16
#  define KEY_T				17
#  define KEY_ONE			18
#  define KEY_TWO			19
#  define KEY_THREE			20
#  define KEY_FOUR			21
#  define KEY_SIX			22
#  define KEY_FIVE			23
#  define KEY_NINE			25
#  define KEY_SEVEN			26
#  define KEY_EIGHT			28
#  define KEY_ZERO			29
#  define KEY_BRACE_R		30
#  define KEY_O				31
#  define KEY_U				32
#  define KEY_BRACE_L		33
#  define KEY_I				34
#  define KEY_P				35
#  define KEY_L				37
#  define KEY_J				38
#  define KEY_K				40
#  define KEY_SEMI			41
#  define KEY_N				45
#  define KEY_M				46
#  define KEY_TAB			48
#  define KEY_PLUS			69
#  define KEY_MINUS			78
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_DOWN			125
#  define KEY_UP			126

# endif
#endif
