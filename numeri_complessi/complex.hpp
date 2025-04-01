#pragma once

/* Templates: recall that where you see `template<typename T>` you should
 * read `for all T`.
 * C++20 introduces a feature called "concepts", which in some way allows
 * you to put constraints on the universal quantifier. For example, when you
 * see
 *
 *      template<typename T> requires std::integral<T>
 *
 * you should read it as
 *
 *      for all T   such that   std::integral<T> is true
 *
 * In addition, std::integral<T> is true if and only if the type T is some
 * kind of integer (short, int, long...)
 */

/* A class modeling a rational number. Remember that a class is the same of
 * a struct but all of its members are private by default. */
template<typename I> //requires std::integral<I>
class complex
{
    /* Private members */
    I n_re, n_im;
	
public:
    /* Default constructor */
    complex()
        : n_re(0), n_im(0)
    {}
    
    /* User-defined constructor. This is marked `explicit` to avoid
     * making a "converting constructor". Without `explicit`, if we
     * assign an object of type I (which is real in our case) to a
     * rational, the "converting constructor" gets called. Take a
     * look to the point (3) in complex.cpp.
     */
    explicit complex(I n)
        : n_re(n), n_im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    /* User-defined constructor. Takes two parameters, real and
     * imaginary part */
    complex(I n, I m)
        : n_re(n), n_im(m)
    {}
    
    /* Return the numerator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I real(void) const {
        return n_re;
    }
    
    /* Return the denominator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I imag(void) const {
        return n_im;
    }
    
    /* return the complex conjugate number */
    complex<I> conj(void) const {
	    return complex(n_re,-n_im);
	}
	
    /* Define the += operator between complex numbers. When you do
     * 
     *  z1 += z2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    complex& operator+=(const complex& other) {
        I a = n_re;
        I b = n_im;
        I c = other.n_re;
        I d = other.n_im;
        n_re = a+c;
        n_im = b+d;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a complex on the left
     * and an I on the right. When you do
     * 
     *  z1 += i
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
     complex& operator+=(const I& other) {
        n_re += other;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex operator+(const I& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }
    
    /* This is the UNARY minus. It computes the opposite: r2 = -r1; Notice
     * that the UNARY minus does not modify the instance on which is called,
     * therefore it is marked const.
     */
    complex operator-() const {
        return complex(-n_re,-n_im);
    }
    
    /* Define the *= operator between complex numbers. When you do
     * 
     *  z1 *= z2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    complex& operator*=(const complex& other) {
        I a = n_re;
        I b = n_im;
        I c = other.n_re;
        I d = other.n_im;
        n_re = a*c-b*d;
        n_im = b*c+a*d;
        return *this;
	}
	/* Define the *= operator between a complex on the left
     * and an I on the right. When you do
     * 
     *  z1 *= i
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
     complex& operator*=(const I& other) {
        n_re *= other;
        n_im *= other;
        return *this;
	}
	
	/* Define operator* in terms of operator *=. Notice that * does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex operator*(const I& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }

	complex operator*(const complex& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }
};

/* This operator is defined outside the complex class and is needed
 * to compute the sum of an I on the left and a complex<I> on the
 * right. */
template<typename I>
complex<I>
operator+(const I& i, const complex<I>& z)
{
    return z + i;
}

/* This operator is defined outside the complex class and is needed
 * to compute the product of an I on the left and a complex<I> on the
 * right. */
template<typename I>
complex<I>
operator*(const I& i, const complex<I>& z)
{
    return z * i;
}

/* free function to compute the conjugate of a complex */
template<typename I>
complex<I> conj(const complex<I>& z) {
    return z.conj();  // richiama il metodo della classe
}

/* Overload of <<, to make the complex numbers printable. */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const complex<I>& z) {
    if (z.imag() > 0)
        os << z.real() << "+" << z.imag() << "i";
    else if (z.imag() < 0)
        os << z.real() << "-" << -z.imag() << "i";
    else
        os << z.real();
    return os;
}

