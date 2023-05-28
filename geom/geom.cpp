#include <algorithm>
#include <cmath>
#include <vector>

constexpr double eps = 1e-6;

struct vec_t
{
	double x, y;

	vec_t() : x(0), y(0) {}
	vec_t(double x, double y) : x(x), y(y) {}

	vec_t &operator+=(const vec_t &v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}
	vec_t &operator-=(const vec_t &v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	vec_t &operator*=(double s)
	{
		x *= s;
		y *= s;
		return *this;
	}
	vec_t &operator/=(double s)
	{
		x /= s;
		y /= s;
		return *this;
	}

	vec_t operator+(const vec_t &v) const { return vec_t(*this) += v; }
	vec_t operator-(const vec_t &v) const { return vec_t(*this) -= v; }
	vec_t operator*(double s) const { return vec_t(*this) *= s; }
	vec_t operator/(double s) const { return vec_t(*this) /= s; }

	// 若 $\vec a = (x_1, y_1)$，$\vec b = (x_2, y_2)$
	// 则 $\vec a \cdot \vec b = x_1 x_2 + y_1 y_2$
	double dot(const vec_t &v) const { return x * v.x + y * v.y; }
	// 若 $\vec a = (x_1, y_1, z_1)$，$\vec b = (x_2, y_2, z_2)$
	// 则 $\vec a \times \vec b = (y_1 z_2 - y_2 z_1, x_2 z_1 - x_1 z_2, x_1 y_2 - x_2 y_1)$
	double cross(const vec_t &v) const { return x * v.y - v.x * y; }

	// 模长的平方
	double norm2() const { return x * x + y * y; }
	// 模长
	double norm() const { return std::sqrt(norm2()); }
	// 同方向的单位向量
	vec_t normalize() const { return *this / norm(); }
	// 顺时针旋转 $90\deg$
	vec_t rotate90() const { return vec_t(y, -x); }
	// 象限
	int ort() const
	{
		if (std::fabs(x) < eps && std::fabs(y) < eps)
			return 0; // 在坐标轴上
		if (y > 0) {
			if (x > 0) return 1;
			else return 2;
		} else {
			if (x > 0) return 4;
			else return 3;
		}
	}
};

struct line_t
{
	vec_t s, t;
	line_t() : s(0, 0), t(0, 0) {}
	line_t(vec_t s, vec_t t) : s(s), t(t) {}
	vec_t dir() const { return t - s; }
	vec_t normalize() const { return dir().normalize(); }
	double norm() const { return dir().norm(); }
	/* 判断一个点在直线的哪边
	 * +1: s-t,s-p : 逆时针
	 * -1: s-t,s-p : 顺时针
	 * +2: t-s-p
	 * -2: s-t-p
	 *  0: s-p-t */
	int ccw(const vec_t &p) const
	{
		if (dir().cross(p - s) > eps) return +1;
		if (dir().cross(p - s) < -eps) return -1;
		if (dir().dot(p - s) < -eps) return +2;
		if (dir().dot(t - p) < -eps) return -2;
		return 0;
	}

	// 判断两条线是否相交
	bool touch(const line_t &l) const
	{
		int a = ccw(l.s) * ccw(l.t), b = l.ccw(s) * l.ccw(t);
		return !a || !b || (a == -1 && b == -1);
	}
};

bool equal(double a, double b) { return std::fabs(a - b) < eps; }

struct circle_t
{
	vec_t o;
	double r;
	circle_t() : o(0, 0), r(0) {}
	circle_t(vec_t o, double r) : o(o), r(r) {}

	// 判断点 $p$ 是否在圆内部
	bool is_inside(const vec_t &p) const {
		return (p - o).norm() < r + eps;
	}

	// 求两个圆的交点
	std::vector<vec_t> crossPoint(const circle_t& c) {
		vec_t v = c.o-o;
		double l = v.norm();
		if (equal(l, 0)) return {};
		if (equal(l+r+c.r, std::max({l,r,c.r})*2)) {
			if (equal(l+r,c.r)) return {o - v*(r/l)};
			return {o + v*(r/l)};
		}
		if (l+r+c.r < std::max({l,r,c.r})*2) return {};
		double x = (l*l + r*r - c.r*c.r) / (2*l);
		double y = sqrt(r*r - x*x);
		vec_t mid = o + v*(x/l);
		v = v.rotate90();
		return {mid + v*(y/l), mid - v*(y/l)};
	}
};
