#include "stdafx.h"
#include "ExperimentHandler.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

void ExperimentHandler::RunTests()
{
	for (auto spProbability : m_probabilites)
	{
		std::cout << "probability: " << spProbability.second << ", ";
		for (auto spCacheStrategy : m_cacheOrganizationStrategies)
		{
			std::cout << "cache strategy: " << spCacheStrategy.second << std::endl;
			for (int pagesNumDivider : m_cachePageAmountDivider)
			{				
				std::string prefix = "plots//";
				std::string strFileName = prefix + spCacheStrategy.second + spProbability.second + "KDIV=" + std::to_string(pagesNumDivider) + ".tsv";
				std::ofstream file(strFileName.c_str());
				if (!file.good())
				{
					std::cout << "cannot open file: " << strFileName << std::endl;
					return;
				}
				for (int numPages : m_amountOfPages)
				{
					int cacheSize = numPages / pagesNumDivider;
					std::cout << "cache size: " << cacheSize << "\t";
				
					long double lCost = 0;

					spCacheStrategy.first->SetCacheSize(cacheSize);
					for (int i = 0; i < m_testCount; ++i)
					{						
						lCost += spCacheStrategy.first->FindPage(spProbability.first->GetDistribution());
					}
					spCacheStrategy.first->EmptyCache();

					lCost /= m_testCount;
					file << numPages << "\t" << lCost << "\n";
					std::cout << "avg Access cost: " << lCost << std::endl;
				}
				file.close();
			}
		}
	}
}