#ifndef CLA_H
# define CLA_H

typedef union u_vec2i {
	struct {
		int	x;
		int	y;
	};
	int	raw[2];
}	t_vec2i;

static inline t_vec2i	vec2i(int x, int y) { return (t_vec2i){{ x, y }}; }
static inline t_vec2i	vec2i_adds(t_vec2i v, int x) { return (t_vec2i){{ v.x + x, v.y + x }}; }
static inline t_vec2i	vec2i_subs(t_vec2i v, int x) { return (t_vec2i){{ v.x - x, v.y - x }}; }
static inline t_vec2i	vec2i_muls(t_vec2i v, int x) { return (t_vec2i){{ v.x * x, v.y * x }}; }
static inline t_vec2i	vec2i_divs(t_vec2i v, int x) { return (t_vec2i){{ v.x / x, v.y / x }}; }
static inline t_vec2i	vec2i_add(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x + v2.x, v1.y + v2.y }}; }
static inline t_vec2i	vec2i_sub(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x - v2.x, v1.y - v2.y }}; }
static inline t_vec2i	vec2i_mul(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x * v2.x, v1.y * v2.y }}; }
static inline t_vec2i	vec2i_div(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x / v2.x, v1.y / v2.y }}; }

#define			vec2i_scale vec2i_muls

#endif // CLA_H
