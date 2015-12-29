#include "utmatrix.h"

#include "conio.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)//---------------------------//
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)//---------------------------//
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)//---------------------------//
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)//---------------------------//
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)//---------------------------//
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)//---------------------------//
{
	TVector<int> v(3);
	TVector<int> v1(v);
	 EXPECT_EQ(v1, v);
  //ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory)//---------------------------//
{
	TVector<int> v(3);
	TVector<int> v1(v);
	EXPECT_NE(&v1, &v);
  //ADD_FAILURE();
}

TEST(TVector, can_get_size)//---------------------------//
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)//---------------------------//
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)//---------------------------//
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)//---------------------------//
{
  TVector<int> v(4);
   ASSERT_ANY_THROW(v[-1]=0);
	//ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index)//---------------------------//
{
 TVector<int> v(4);
   ASSERT_ANY_THROW(v[5]=0);
	// ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself)//---------------------------//
{
	TVector<int> a(3);
	a = a;
	EXPECT_EQ(a, a);
	
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)//---------------------------//
{
	TVector<int> a(3), b(3);
	b = a;
	EXPECT_EQ(a, b);
 
	//ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size)//---------------------------//
{
	TVector<int> a(3), b(4);
	a = b;
	EXPECT_EQ(4, a.GetSize());
  
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size)//---------------------------//
{
	TVector<int> a(3), b(4);
	a = b;
	EXPECT_EQ(a, b);
  
	//ADD_FAILURE();
}

TEST(TVector, compare_equal_vectors_return_true)//---------------------------//
{ 
	TVector<int> a(3), b(3);
	b = a;
	EXPECT_TRUE(a == b);
 // ADD_FAILURE();
}

TEST(TVector, compare_vector_with_itself_return_true)//---------------------------//
{
	TVector<int> a(3);
	EXPECT_TRUE(a == a);
	//ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)//---------------------------//
{
	TVector<int> a(3), b(4);
	EXPECT_FALSE(a == b);
	//ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector)//---------------------------//
{
	TVector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a = a + 1;
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 3);
	EXPECT_EQ(a[2], 4);
//ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector)//---------------------------//
{
	TVector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a = a - 1;
	EXPECT_EQ(a[0], 0);
	EXPECT_EQ(a[1], 1);
	EXPECT_EQ(a[2], 2);
	//ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)//---------------------------//
{
	TVector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a = a * 2;
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 4);
	EXPECT_EQ(a[2], 6);
  //ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)//---------------------------//
{
	TVector<int> a(3), b(3), c(3);
	//a[0] = 1; b[0] = 4;
	//a[1] = 2; b[1] = 5;
	//a[2] = 3; b[2] = 6;
	c = a + b;
	//EXPECT_EQ(5, c[0]);
	//EXPECT_EQ(7, c[1]);
	//EXPECT_EQ(9, c[2]);
	EXPECT_EQ(c, (a+b));
	//ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)//---------------------------//
{
	TVector<int> a(3), b(4);
	ASSERT_ANY_THROW(a + b);
 // ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)//---------------------------//
{
	TVector<int> a(3), b(3), c(3);
	c = a - b;
	EXPECT_EQ(c, (a - b));
  
	//ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)//---------------------------//
{
	TVector<int> a(3), b(4);
	ASSERT_ANY_THROW(a - b);
  //ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)//---------------------------//
{
	TVector<int> a(3), b(3);
	int c;
	a[0] = 1; b[0] = 4;
	a[1] = 2; b[1] = 5;
	a[2] = 3; b[2] = 6;
	c = a * b;
	EXPECT_EQ(32, c);
	//ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)//---------------------------//
{
	TVector<int> a(3), b(4);
	ASSERT_ANY_THROW(a * b);
	//ADD_FAILURE();
}

TEST(SHOWDOWN)//---------------------------//
{
	getch();
	SUCCEED();
}
