# DevSet06
-------------
##IntSetArray
**1. Sorting**
기존의 Array에 for loop 을 이용하여 값을 추가할 경우에 Insert 시 매번 값의 중복여부를 
체크하고, 값이 들어갈 위치를 찾고 더나아가 Shifting 을 하는 경우가 빈번히 발생한다. 
이는 결과적으로 time complexity(시간 복잡도)의 증가를 유도하고 실제 execution time
(실행 시간)의 증가를 초래한다.

이러한 상황을 방지하기 위해, 우리 팀은 space complexity(공간 복잡도)와 time complexity
(시간 복잡도) 사이에서 타협을 보아야 했다. 우리 팀이 구현한 IntSetArray 의 경우 결과적으로 
높은 space complexity 를 가지지만 동시에 time complexity 를 줄임으로서 더욱 효과적이고
빠른 Sorting 을 구현할 수 있었다. 

```
arr = new bool[max_value];
```
가장 큰 max_value 값의 크기를 가진 boolean 형 arr 배열을 선언한다. 이 경우에 sparsity problem
(희소 문제)가 발생하지만, time complexity 와 execution time 을 실질적으로 감소시키는데에는
매우 효과적으로 작용한다.

```
void insert(int num) {
	/*
	Checking whether incoming number 'n' is already in array
	This process takes only the time complexity of O(1),
	*/
	if (!arr[num]){	
		arr[num] = true;
		n++;
	}
}
```

값을 insert 할 때, 값의 중복 여부를 체크하기 위하여 배열을 처음부터 훑어볼 필요없이, 
O(1) 의 time complexity 로 중복 여부를 체크하고 별도의 값 shift 없이 O(1) 의 time complexity
로 값을 insert 할 수 있다. 값의 중복 여부는 num 값을 배열의 인덱스로 사용하여 접근한 뒤, 
값이 false 인 경우 추가하고 그렇지 않은 경우에는 skip 하는 과정으로 진행한다.

```
void report(int *v) {
	int j = 0;
	for (int i = 0; i < get_maxval() + 1; i++) {
		if (arr[i]) v[j++] = i;
	}
}
```

기존 arr 배열에 있는 값을 sorting 하는 알고리즘은 위와 같이 간단하다. 단순히 O(n + k) (k: 
max_value) 만큼 for loop 을 통해 배열을 훑어 가면서 값이 true 일 경우에 배열 v 에 값을
하나씩 넣어주는 과정으로 진행한다.

**2. Algorithm Test**

![default](/img/UnitTestArray.png)

알고리즘의 유효성 테스트는 다음과 같이 크게 두가지 부분으로 나누어 진행하였다.

**1) Insert Time Test**
오름차순, 내림차순, 랜덤 값을 Insert 하는 방식으로 테스트를 진행하였다.

```
TEST_METHOD(Array_Insert_Desc)
{
	// Inserting values in descending order
	IntSetArray test(max_e, max_v);
	j = 0;
	for (i = max_e - 1; i >= 0; i--) {
		test.insert(max_v - j);
		j++;
	}
}

TEST_METHOD(Array_Insert_Asce)
{
	// Inserting values in ascending order
	IntSetArray test(max_e, max_v);
	for (i = 0; i < max_e + 1; i++) {
		test.insert(max_e + i);
	}
}

TEST_METHOD(Array_Insert_Rand)
{
	// Inserting random values
	IntSetArray test(max_e, max_v);
	for (i = 0; i < max_e + 1; i++) {
		test.insert(bigrand(max_v));
	}
}
```

**2) Sorting Correct**

제대로 값들이 sort 되는지 알아보기 위하여 다음과 같이 테스트를 진행하였다.
기대값을 저장하는 expect 배열을 별도로 만들어서 같은 값을 insert 하고 C 에서 기본 
라이브러리로 제공되는 sort() 함수를 이용하여 expect 배열을 sorting 하고 값을 비교하였다.

```
TEST_METHOD(Array_Report_Desc)
{
	// Inserting values in descending order
	IntSetArray test(max_e, max_v);
	j = 0;
	for (i = max_e - 1; i >= 0; i--) {
		test.insert(max_v - j);
		expect[i] = max_v - j;
		j++;
	}

	test.report(v);
	std::sort(expect, expect + max_e);

	// Comparing expected values and result values
	for (i = 0; i < max_e; i++) {
		if (expect[i] != v[i]) {
			result_equal = false;
			break;
		}
	}

	Assert::AreEqual(true, result_equal);
}

TEST_METHOD(Array_Report_Asce)
{
	// Inserting values in ascending order
	IntSetArray test(max_e, max_v);

	for (i = 0; i < max_e; i++) {
		test.insert(max_e + i);
		expect[i] = max_e + i;
	}

	test.report(v);
	std::sort(expect, expect + max_e);

	// Comparing expected values and result values
	for (i = 0; i < max_e; i++) {
		if (expect[i] != v[i]) {
			result_equal = false;
			break;
		}
	}

	Assert::AreEqual(true, result_equal);
}

TEST_METHOD(Array_Report_Rand)
{
	j = 0;
	// Inserting random values
	IntSetArray test(max_e, max_v);
	for (i = 0; i < max_e; i++) {
		temp = bigrand(max_v);
		test.insert(temp);

		if (dupCheck(temp, max_e, expect)) continue;

		expect[j++] = temp;
	}

	test.report(v);
	std::sort(expect, expect + j);

	// Comparing expected values and result values
	for (i = 0; i < j; i++) {
		if (expect[i] != v[i]) {
			result_equal = false;
			break;
		}
	}

	Assert::AreEqual(true, result_equal);
}
```

특별히, 랜덤 값을 expect 배열에 insert 할 때, 값의 중복 여부를 체크하는 dubCheck() 함수를
따로 만들어서 매번 값 입력시 중복 체크를 할 수 있도록 만들었다.
배열 expect 와 v 를 Sorting 한 후에는 for loop 을 이용하여 서로의 값을 비교한다. 이 과정에서 
값이 다를 경우 for loop 을 break 로 종료하게 된다.

##IntSetBST
**1. Sorting**
![default](https://user-images.githubusercontent.com/34343170/41650795-d83ad2de-74b9-11e8-9488-b36ec00595b9.PNG)
BST로 정렬하는 것은 Tree를 만드는 것과 같다. Tree를 만들면서 데이터를 정렬하기 때문이다.  
위 그림과 같이 키 값과 같거나 보다 작으면 Left Child를 만들고 반대라면 Right Child를 만들며 정렬한다.  
![default](https://user-images.githubusercontent.com/34343170/41651060-943c2834-74ba-11e8-9d55-3491f35e7905.PNG)
이후 출력할 때는 inorder로 트리를 순회하여 배열에 값을 오름차순으로 입력하였다.  

**2. Algorithm Test**
![default](https://user-images.githubusercontent.com/34343170/41651348-5160ecce-74bb-11e8-9e9f-81d6c1b7e5aa.PNG)
테스트는 크게 2가지로 나누어 하였다.
첫 번째는 Tree를 구현하는 데 걸리는 시간을 측정하였고 두 번째는 정렬된 값이 정확한지 체크하였다.  

 **1) Insert Time Test**
![default](https://user-images.githubusercontent.com/34343170/41651504-afbec016-74bb-11e8-92f8-95d91c3717b4.PNG)
Tree에 Key들을 Insert하는 시간을 검증하는 코드이다. 각각 Worst Case로 내림차순 된 Input, 오름차순 된 Input, 일반적인 Random Input을 가지고 테스트하였다. 결과는 내림차순,오름차순으로 정렬되있는 Input을 받으면 약 1초의 시간이 걸린다. 왜냐하면 Tree를 구현하는 데 한 쪽으로만(Left,Right) Tree가 생성되기 때문에 Tree의 높이가 입력개수인 n이 되기 때문이다. 그렇다면 한 개의 Key Node를 생성하기 위해서 n개의 Node를 전부 확인해봐야한다. 반면에 Random Input을 넣어주는 경우에는 적절하게 배분이 된다면 log(n)만큼만 검사하면 되어 훨씬 빠르다. 이는 n의 값이 커질 수 록 더욱 확연한 차이를 확인 할 수 있다.

 **2) Sorting Correct**
![default](https://user-images.githubusercontent.com/34343170/41651927-c1532906-74bc-11e8-9c85-68f21819678c.PNG)
내림차순으로 정렬된 Input을 받았을 경우 정확히 정렬하는 지 테스트한 코드이다. expect 배열에 기댓값을 넣었고 정렬하면서 다른 부분이 있으면 result_equal을 false로 만들고 결과 AreEqual메소드로 true인지 검사하였다.
![default](https://user-images.githubusercontent.com/34343170/41653299-94bfc738-74c0-11e8-8cfe-6c0e1ce4d98f.PNG)
오름차순으로 진행된 Input이다. 위와 동일하게 진행된다.
![default](https://user-images.githubusercontent.com/34343170/41653328-b0230468-74c0-11e8-88ad-81d5e565b5b8.PNG)
Random Input을 정렬하는 코드이다. 기댓값은 "Algorithm.h"에 선언되어있는 기본 sorting 메소드를 사용하여 정렬하였고 그 값과 일치하는지 검사하였다.

결과는 맨위의 사진에서 볼 수 있드시 성공하였다.
=======

## Bucket 테스트
1>------ 모두 다시 빌드 시작: 프로젝트: DevSet, 구성: Debug Win32 ------
2>------ 모두 다시 빌드 시작: 프로젝트: UnitTestBucket, 구성: Debug Win32 ------
2>stdafx.cpp
1>IntSet.cpp
1>IntSetArray.cpp
2>unittest1.cpp
1>IntSetBins.cpp
2>   C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBucket.lib 라이브러리 및 C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBucket.exp 개체를 생성하고 있습니다.
1>IntSetBitVec.cpp
2>UnitTestBucket.vcxproj -> C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBucket.dll
1>IntSetBST.cpp
1>IntSetList.cpp
1>main.cpp
1>util_func.cpp
1>코드를 생성하고 있습니다...
1>DevSet.vcxproj -> C:\Users\csw9507\Desktop\DevSet6\Debug\DevSet.exe
3>------ 모두 다시 빌드 시작: 프로젝트: UnitTestBST, 구성: Debug Win32 ------
3>stdafx.cpp
3>unittest1.cpp
3>   C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBST.lib 라이브러리 및 C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBST.exp 개체를 생성하고 있습니다.
3>UnitTestBST.vcxproj -> C:\Users\csw9507\Desktop\DevSet6\Debug\UnitTestBST.dll
========== 모두 다시 빌드: 성공 3, 실패 0, 생략 0 ==========
