#include "Problem1.h"


/*
* 이상 이하 짝대기 그려서 겹치는 부분만 새로 구간으로 만들어서 출력하면 됨
*/
void Problem1::Run() const
{
	//구간 입력값
	vector<int>Input = {1,3,7,10,2,6,15,20,2,4,7,8};

	vector<pair<int, int>> Sections;
	vector<pair<int, int>> Results;
	//구간을 나눈다
	//첫번째 두번째 구간 값
	int first = 0, second = 0;
	//값을 읽는 작업
	for (int i = 0; i < Input.size(); ++i)
	{
		//홀수인지 검사 홀수라면 1(true)로 나올 것
		bool bIsOdd = i % 2;
		//홀수인 경우, 1,3,5,...
		if (bIsOdd)
		{
			second = Input[i];
			Sections.push_back(pair<int, int>(first, second));
			first = 0, second = 0;
		}
		//짝수인 경우, 0,2,4,...
		else
		{
			first = Input[i];

		}
	}
	//구간을 정렬. first 값 기준으로 오름차순
	sort(Sections.begin(), Sections.end(), [](pair<int,int>left,pair<int,int>right)->bool{
		return left.first < right.first;
		});

	//입력된 구간을 출력해준다.
	cout << "초기 입력 구간 : 정렬됨\n";
	for (auto it : Sections)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
	cout << "=====================================\n";


	//겹치는 구간을 검사한다
	/*
	* 전체 순회
	* 현재 값 기준으로 다음 값과 비교
	* 
	*/
	int forward = 1;
	for (int i = 0; i < Sections.size(); ++i)
	{
		auto now = Sections[i];
		//다음 노드들의 idx 조정 값
		forward = 1;

		int curNext = i + forward;
		if (curNext == Sections.size()) 
		{
			Results.push_back(now);
			break; 
		}
		auto next = Sections[curNext];

		//범위가 겹치지 않는 경우, 현재 구간을 넣어주고 다음으로 넘어간다
		if (now.second < next.first) 
		{
			//cout << "case1" << endl;
			Results.push_back(now);
			continue; 
		}
		
		//겹치는 경우
		do {
			//now의 범위를 다음 idx의 second로 확장 시켜서 하나로 만들어준다.
			//단, next의 second가 더 크다면
			if(now.second<next.second)
				now.second = next.second;

			//next는 다음 idx를 가리키게 한다
			++forward;
			curNext= i + forward;
			if (curNext == Sections.size())break;
			next = Sections[curNext];
			
		} while (now.second >= next.first);

		//cout << "Case2\n";
		// 
		//합쳐진 결과나 now 자신을 넣어준다
		Results.push_back(now);
		//i를 합쳐버린 구간 만큼 건너 띄어준다.
		i += forward-1;
	}

	cout << "결과\n";
	for (auto it : Results)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
	

}
