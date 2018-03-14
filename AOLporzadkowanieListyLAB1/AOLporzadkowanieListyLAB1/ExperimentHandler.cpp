#include "stdafx.h"
#include "ExperimentHandler.h"

#include <fstream>
#include <iostream>
#include <algorithm>


void ExperimentHandler::RunTests()
{
	std::ofstream file("wyniki.txt");
	if (!file.good())
		return;
	for (auto spProbability : m_probabilites)
	{
		file << "probability: " << spProbability.second << ", ";
		std::cout << "probability: " << spProbability.second << ", ";
		for (auto spOrganizeIter : m_organizingLists)
		{
			file << "organize method: " << spOrganizeIter.second << std::endl;
			std::cout << "organize method: " << spOrganizeIter.second << std::endl;
			//int iLabel = 1;
			for (int iTestsCount : m_testCount)
			{
				long double lCost = 0;
				for (int i = 0; i < iTestsCount; ++i)
				{
					lCost += spOrganizeIter.first->Access(spProbability.first->GetDistribution());
				}
				spOrganizeIter.first->EmptyList();
				lCost /= iTestsCount;
				//file << iTestsCount << "\t" << iLabel << "\t" << lCost << "\n";
				file << iTestsCount << "\t" << lCost << "\n";
				//++iLabel;
				std::cout << "Number of tests: " << iTestsCount << ", avg Access cost: " << lCost << std::endl;
			}
		}
		file << "\n";
	}
	file.close();
}