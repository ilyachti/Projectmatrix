#pragma once

#include <iostream>
#include <initializer_list>

namespace linalg {

	template <typename T>
	class Matrix {
		int m_capacity;
		T* m_ptr;
		int m_rows, m_columns;
	protected:
		class ProxyConst;
		class Proxy;
	public:
		class ProxyConst
		{
			const Matrix<T>& M;
			int i;
		public:
			inline ProxyConst(const Matrix<T>& M, int i);
			inline T operator [] (int j) const;
		};

		class Proxy
		{
			Matrix& M;
			int i;
		public:
			inline Proxy(Matrix<T>& M, int i);
			inline T& operator [] (int j);
		};

		int capacity() const noexcept { return m_capacity; }
		void shrink_to_fit();
		void clear() noexcept { m_rows = 0; m_columns = 0; for (int i = 0; i < m_capacity; i++) m_ptr[i].~T(); }
		void reserve(int n);
		inline Matrix(int rows = 1, int columns = 1) ;
		inline Matrix(std::initializer_list<T> il) ;
		inline Matrix(std::initializer_list <std::initializer_list<T>> il) ;
		template <typename U>
		inline Matrix(std::initializer_list<U> il) ;
		template <typename U>
		inline Matrix(std::initializer_list <std::initializer_list<U>> il) ;

		inline Matrix(const Matrix<T>& orig) noexcept;

		inline Matrix(Matrix&& orig) noexcept;
		inline ~Matrix();
		inline T* ptr() const;
		inline int rows() const;
		inline int	columns() const;
		inline bool empty() const;



		void operator = (const Matrix<T>& orig);

		template <typename U>
		void operator = (const Matrix<U>& orig);

		template <typename U> inline Matrix<T> operator - (Matrix<U>& orig) const;
		template <typename U> inline Matrix<T> operator += (Matrix<U>& orig);
		template <typename U> inline Matrix<T> operator -= (Matrix<U>& orig);
		inline T& operator()(int i, int j);
		inline T operator()(int i, int j) const;

		ProxyConst operator[](int i) const {
			return ProxyConst(*this, i);
		}
		Proxy operator[](int i) {
			return Proxy(*this, i);
		}

		inline Matrix<T> operator * (double n)const noexcept;

		inline Matrix<T> operator *= (double n) noexcept;

		template <typename U>
		inline Matrix<T> operator *= (Matrix<U>& other);

		template <typename U>
		inline Matrix<T> operator + (Matrix<U>& other) const;

		template <typename U>
		inline Matrix<decltype(T()* U())> operator * (Matrix<U>& other) const;

		template <typename U>
		inline bool operator == (Matrix<U>& other);

		template <typename U>
		inline bool operator != (Matrix<U>& other);



		inline Matrix<T>& reshape(int rows, int cols);

		inline double norm();
		inline double trace();

		inline Matrix<T> gauss_forward();
		inline Matrix<T> gauss_backward();
		inline int rank();
		inline T det();
	};


	template <typename U>
	U calculateDeterminant(U* matrix, int size);

	template <typename U, typename T>
	Matrix<T> concatenate(Matrix<T>& matr1, Matrix<U>& matr2);

	template <typename U>
	Matrix<U> transpose(Matrix<U>& matr1);

	template <typename U>
	Matrix<U> invert(Matrix<U>& matr);

	template <typename U>
	Matrix<U> power(Matrix<U>& matr, int power);

	template <typename U, typename T>
	Matrix<U> solve(Matrix<U>& matr_a, Matrix<T>& matr_f);

	template <typename U>
	Matrix<U> algebraAddition(int i, int j, Matrix<U>& matr);

	/*template <typename U, typename T>
	Matrix<T> operator * (U a, Matrix<T>& matr) noexcept;*/

	template <typename T>
	std::ostream& operator << (std::ostream& out, const Matrix<T>& M);

	template <typename T>
	inline Matrix<T> operator * (double a, Matrix<T>& matr) noexcept;
}
