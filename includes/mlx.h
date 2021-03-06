/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:57:49 by bemoreau          #+#    #+#             */
/*   Updated: 2020/10/11 14:59:33 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7
# define A_KEY 0
# define B_KEY 11
# define C_KEY 8
# define D_KEY 2
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 1
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 13
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6
# define W_KEY_L 119
# define A_KEY_L 97
# define S_KEY_L 115
# define D_KEY_L 100
# define ESC_KEY_L 65307
# define W_KEY_M 13
# define A_KEY_M 0
# define S_KEY_M 1
# define D_KEY_M 2
# define ESC_KEY_M 53
# define K1_KEY 18
# define K2_KEY 19
# define K3_KEY 20
# define K4_KEY 21
# define K5_KEY 23
# define K6_KEY 22
# define K7_KEY 26
# define K8_KEY 28
# define K9_KEY 25
# define K0_KEY 29
# define SP_KEY 49
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44
# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY_L 65363
# define LEFT_KEY_L 65361
# define RIGHT_KEY_M 124
# define LEFT_KEY_M 123
# define ESC_KEY 53
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71
# define NK1_KEY 83
# define NK2_KEY 84
# define NK3_KEY 85
# define NK4_KEY 86
# define NK5_KEY 87
# define NK6_KEY 88
# define NK7_KEY 89
# define NK8_KEY 91
# define NK9_KEY 92
# define NK0_KEY 82
# define NKEQ_KEY 81
# define NKSL_KEY 75
# define NKWC_KEY 67
# define NKMN_KEY 78
# define NKPL_KEY 69
# define NKPT_KEY 65
# define NKNTR_KEY 76
# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3

void			*mlx_init();
void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,\
				char *title);
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr,\
				int x, int y, int color);
void			*mlx_new_image(void *mlx_ptr, int width, int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
				int *size_line, int *endian);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,\
				void *img_ptr,
				int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),\
				void *param);

int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				mlx_string_put(void *mlx_ptr, void *win_ptr,\
				int x, int y, int color,
				char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
				int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				int *width, int *height);
void			*mlx_png_file_to_image(void *mlx_ptr, char *file,\
				int *width, int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
				int (*funct)(), void *param);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				mlx_mouse_hide();
int				mlx_mouse_show();
int				mlx_mouse_move(void *win_ptr, int x, int y);
int				mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

#endif
