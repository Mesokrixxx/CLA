#ifndef CLA_H
# define CLA_H

# include <stdbool.h>
# include <stdint.h>

typedef union u_vec2i {
	struct {
		int	x;
		int	y;
	};
	int	raw[2];
}	t_vec2i;

typedef union u_vec2 {
	struct {
		float	x;
		float	y;
	};
	float	raw[2];
}	t_vec2;

typedef union u_vec4 {
	struct {
		float	x;
		float	y;
		float	z;
		float	w;
	};
	float	raw[4];
}	t_vec4;

typedef union u_mat4 {
	struct {
		float	m00, m01, m02, m03;
    		float	m10, m11, m12, m13;
    		float	m20, m21, m22, m23;
    		float	m30, m31, m32, m33;
	};
	float raw[16];
}	t_mat4;

static inline t_vec2i	vec2i(int x, int y) { return (t_vec2i){{ x, y }}; }

static inline t_vec2i	vec2i_adds(t_vec2i v, int x) { return (t_vec2i){{ v.x + x, v.y + x }}; }
static inline t_vec2i	vec2i_subs(t_vec2i v, int x) { return (t_vec2i){{ v.x - x, v.y - x }}; }
static inline t_vec2i	vec2i_muls(t_vec2i v, int x) { return (t_vec2i){{ v.x * x, v.y * x }}; }
static inline t_vec2i	vec2i_divs(t_vec2i v, int x) { return (t_vec2i){{ v.x / x, v.y / x }}; }

static inline t_vec2i	vec2i_add(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x + v2.x, v1.y + v2.y }}; }
static inline t_vec2i	vec2i_sub(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x - v2.x, v1.y - v2.y }}; }
static inline t_vec2i	vec2i_mul(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x * v2.x, v1.y * v2.y }}; }
static inline t_vec2i	vec2i_div(t_vec2i v1, t_vec2i v2) { return (t_vec2i){{ v1.x / v2.x, v1.y / v2.y }}; }

static inline bool	vec2i_eq(t_vec2i v1, t_vec2i v2) { return (v1.x == v2.x && v1.y == v2.y); }

static inline bool	vec2is_contains(const t_vec2i *vs, uint64_t vcount, t_vec2i v) {
	for (uint64_t i = 0; i < vcount; i++) {
		if (vec2i_eq(vs[i], v)) {
			return true;
		}
	}
	return false;
}

static inline t_vec2	vec2(float x, float y) { return (t_vec2){{ x, y }}; }

static inline t_vec4	vec4(float x, float y, float z, float w) { return (t_vec4){{ x, y, z, w }}; }

static inline t_mat4	mat4_identity(void) {
	t_mat4	m = {0};

	m.m00 = 1;
	m.m11 = 1;
	m.m22 = 1;
	m.m33 = 1;
	return m;
}
static inline t_mat4	mat4_ortho(t_vec2 width, t_vec2 height, t_vec2 z) {
	t_mat4	m = {0};
	float	rl = width.y - width.x;
	float	tb = height.y - height.x;
	float	fn = z.y - z.x;

	m.m00 = 2 / rl;
	m.m11 = 2 / tb;
	m.m22 = -(2 / fn);
	m.m30 = -((width.x + width.y) / rl);
	m.m31 = -((height.x + height.y) / tb);
	m.m32 = -((z.x + z.y) / fn);
	m.m33 = 1;
	return m;
}

#endif // CLA_H
