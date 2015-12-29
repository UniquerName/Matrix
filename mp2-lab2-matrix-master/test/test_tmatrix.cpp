#include "utmatrix.h"
#include "conio.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)//---------------------------//
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)//---------------------------//
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)//---------------------------//
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)//---------------------------//
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	m[1][1] = 13;
	TMatrix<int> m2 = m;
	EXPECT_EQ(m2, m);
  //ADD_FAILURE();
}

TEST(TMatrix, copied_matrix_has_its_own_memory)//---------------------------//
{
	TMatrix<int> m(5);
	TMatrix<int>  m2(m);
	EXPECT_NE(&m2, &m);
  //ADD_FAILURE();
}

TEST(TMatrix, can_get_size)//---------------------------//
{
	TMatrix<int> m(4);
	EXPECT_EQ(4, m.GetSize());
	//ADD_FAILURE();
}

TEST(TMatrix, can_set_and_get_element)//---------------------------//
{
	TMatrix<int> m(3);
	m[1][1] = 13;
	EXPECT_EQ(13, m[1][1]);
	//ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_negative_index)//---------------------------//
{
	TMatrix<int> a(3);
	ASSERT_ANY_THROW(a[-1][-1]);
	//ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)//---------------------------//
{
	TMatrix<int> a(3);
	ASSERT_ANY_THROW(a[4][4]);
	//ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrix_to_itself)//---------------------------//
{
	TMatrix<int> a(3);
	ASSERT_NO_THROW(a == a);
  //ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_equal_size)//---------------------------//
{
	TMatrix<int> m(3), m2(3);
	m[1][1] = 13;
	ASSERT_NO_THROW(m2 = m);

  //ADD_FAILURE();
}

TEST(TMatrix, assign_operator_change_matrix_size)//---------------------------//
{
	TMatrix<int> m(3), m2(4);
	m = m2;
	EXPECT_EQ(4, m.GetSize());
	//ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_different_size)//---------------------------//
{
	TMatrix<int> m(3), m2(4);
	m2[1][1] = 13;
	m = m2;
	ASSERT_NO_THROW(m = m2);
	//ADD_FAILURE();
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(3), m2(3);
	m2[1][1] = 13;
	m[1][1] = 13;
	EXPECT_TRUE(m == m2);
  //ADD_FAILURE();
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(3);
	m[1][1] = 13;
	EXPECT_TRUE(m == m);
  //ADD_FAILURE();
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(3), m2(4);
	//m = m2;
	EXPECT_TRUE(m != m2);
 // ADD_FAILURE();
}

TEST(TMatrix, can_add_matrices_with_equal_size)//---------------------------//
{
	TMatrix<int> a(3), b(3);
	ASSERT_NO_THROW(a + b);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)//---------------------------//
{
	TMatrix<int> a(3), b(4);
	ASSERT_ANY_THROW(a + b);
	//ADD_FAILURE();
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)//---------------------------//
{
	TMatrix<int> a(3), b(3);
	ASSERT_NO_THROW(a - b);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)//---------------------------//
{
	TMatrix<int> a(3), b(4);
	ASSERT_ANY_THROW(a - b);
	 //ADD_FAILURE();
}

