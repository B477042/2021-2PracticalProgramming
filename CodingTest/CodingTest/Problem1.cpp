#include "Problem1.h"


/*
* �̻� ���� ¦��� �׷��� ��ġ�� �κи� ���� �������� ���� ����ϸ� ��
*/
void Problem1::Run() const
{
	//���� �Է°�
	vector<int>Input = {1,3,7,10,2,6,15,20,2,4,7,8};

	vector<pair<int, int>> Sections;
	vector<pair<int, int>> Results;
	//������ ������
	//ù��° �ι�° ���� ��
	int first = 0, second = 0;
	//���� �д� �۾�
	for (int i = 0; i < Input.size(); ++i)
	{
		//Ȧ������ �˻� Ȧ����� 1(true)�� ���� ��
		bool bIsOdd = i % 2;
		//Ȧ���� ���, 1,3,5,...
		if (bIsOdd)
		{
			second = Input[i];
			Sections.push_back(pair<int, int>(first, second));
			first = 0, second = 0;
		}
		//¦���� ���, 0,2,4,...
		else
		{
			first = Input[i];

		}
	}
	//������ ����. first �� �������� ��������
	sort(Sections.begin(), Sections.end(), [](pair<int,int>left,pair<int,int>right)->bool{
		return left.first < right.first;
		});

	//�Էµ� ������ ������ش�.
	cout << "�ʱ� �Է� ���� : ���ĵ�\n";
	for (auto it : Sections)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
	cout << "=====================================\n";


	//��ġ�� ������ �˻��Ѵ�
	/*
	* ��ü ��ȸ
	* ���� �� �������� ���� ���� ��
	* 
	*/
	int forward = 1;
	for (int i = 0; i < Sections.size(); ++i)
	{
		auto now = Sections[i];
		//���� ������ idx ���� ��
		forward = 1;

		int curNext = i + forward;
		if (curNext == Sections.size()) 
		{
			Results.push_back(now);
			break; 
		}
		auto next = Sections[curNext];

		//������ ��ġ�� �ʴ� ���, ���� ������ �־��ְ� �������� �Ѿ��
		if (now.second < next.first) 
		{
			//cout << "case1" << endl;
			Results.push_back(now);
			continue; 
		}
		
		//��ġ�� ���
		do {
			//now�� ������ ���� idx�� second�� Ȯ�� ���Ѽ� �ϳ��� ������ش�.
			//��, next�� second�� �� ũ�ٸ�
			if(now.second<next.second)
				now.second = next.second;

			//next�� ���� idx�� ����Ű�� �Ѵ�
			++forward;
			curNext= i + forward;
			if (curNext == Sections.size())break;
			next = Sections[curNext];
			
		} while (now.second >= next.first);

		//cout << "Case2\n";
		// 
		//������ ����� now �ڽ��� �־��ش�
		Results.push_back(now);
		//i�� ���Ĺ��� ���� ��ŭ �ǳ� ����ش�.
		i += forward-1;
	}

	cout << "���\n";
	for (auto it : Results)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
	

}
