# DevSet06
-------------

##IntSetBST  
###**1. Sorting**  
![default](https://user-images.githubusercontent.com/34343170/41650795-d83ad2de-74b9-11e8-9488-b36ec00595b9.PNG)  
BST로 정렬하는 것은 Tree를 만드는 것과 같다. Tree를 만들면서 데이터를 정렬하기 때문이다.  
위 그림과 같이 키 값과 같거나 보다 작으면 Left Child를 만들고 반대라면 Right Child를 만들며 정렬한다.   
![default](https://user-images.githubusercontent.com/34343170/41651060-943c2834-74ba-11e8-9d55-3491f35e7905.PNG)  
이후 출력할 때는 inorder로 트리를 순회하여 배열에 값을 오름차순으로 입력하였다.  

###**2. Algorithm Test**  
![default](https://user-images.githubusercontent.com/34343170/41651348-5160ecce-74bb-11e8-9e9f-81d6c1b7e5aa.PNG)  
테스트는 크게 2가지로 나누어 하였다.  
첫 번째는 Tree를 구현하는 데 걸리는 시간을 측정하였고 두 번째는 정렬된 값이 정확한지 체크하였다.  

####**1) Insert Time Test**  
![default](https://user-images.githubusercontent.com/34343170/41651504-afbec016-74bb-11e8-92f8-95d91c3717b4.PNG)  
Tree에 Key들을 Insert하는 시간을 검증하는 코드이다. 각각 Worst Case로 내림차순 된 Input, 오름차순 된 Input, 일반적인 Random Input을 가지고 테스트하였다. 결과는 내림차순,오름차순으로 정렬되있는 Input을 받으면 약 1초의 시간이 걸린다. 왜냐하면 Tree를 구현하는 데 한 쪽으로만(Left,Right) Tree가 생성되기 때문에 Tree의 높이가 입력개수인 n이 되기 때문이다. 그렇다면 한 개의 Key Node를 생성하기 위해서 n개의 Node를 전부 확인해봐야한다. 반면에 Random Input을 넣어주는 경우에는 적절하게 배분이 된다면 log(n)만큼만 검사하면 되어 훨씬 빠르다. 이는 n의 값이 커질 수 록 더욱 확연한 차이를 확인 할 수 있다.  

####**2) Sorting Correct**  
![default](https://user-images.githubusercontent.com/34343170/41651927-c1532906-74bc-11e8-9c85-68f21819678c.PNG)  
내림차순으로 정렬된 Input을 받았을 경우 정확히 정렬하는 지 테스트한 코드이다. expect 배열에 기댓값을 넣었고 정렬하면서 다른 부분이 있으면 result_equal을 false로 만들고 결과 AreEqual메소드로 true인지 검사하였다.  
![default](https://user-images.githubusercontent.com/34343170/41653299-94bfc738-74c0-11e8-8cfe-6c0e1ce4d98f.PNG)  
오름차순으로 진행된 Input이다. 위와 동일하게 진행된다.  
![default](https://user-images.githubusercontent.com/34343170/41653328-b0230468-74c0-11e8-88ad-81d5e565b5b8.PNG)  
Random Input을 정렬하는 코드이다. 기댓값은 "Algorithm.h"에 선언되어있는 기본 sorting 메소드를 사용하여 정렬하였고 그 값과 일치하는지 검사하였다.  

결과는 맨위의 사진에서 볼 수 있드시 성공하였다.  

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
