double square(double s, double precision) {
	if (s == 0) return 0;

	int r = 1;
	int b = s;

	while (abs(s - r * r) <= precision) {
		r = (r + s / r) / 2;
	}

	return r;
}