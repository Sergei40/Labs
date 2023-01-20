#include <iostream>
using namespace std;

class DataMiner
{
public:
	void mine(const std::string& path)
	{
		std::string file = openFile(path);
		std::string rawData = extractData(file);
		std::string data = parseData(rawData);
		std::string analysis = analyzeData(data);
		sendReportData(analysis);
		closeFile(file);
	}

	virtual std::string openFile(const std::string& path) = 0;

	virtual std::string extractData(const std::string& file)
	{
		cout << "extract data from " + file << std::endl; return "raw data";
	}
	virtual std::string parseData(const std::string& rawData)
	{
		cout << "parse " + rawData << std::endl; return "data";
	}
	virtual std::string analyzeData(const std::string& data)
	{
		cout << "analysis " + data << std::endl; return "analysis";
	}	
	virtual void sendReportData(const std::string& analysis)
	{
		cout << "send report " + analysis << std::endl;
	}

	virtual virtual void closeFile(const std::string& file) = 0;
};

class PDFDataMiner : public DataMiner
{
	std::string openFile(const std::string& path)
	{
		cout << "open file " + path << std::endl; return "PDFfile";
	}
	std::string extractData(const std::string& file)
	{
		cout << "extract data from " + file << std::endl; return "PDF raw data";
	}
	std::string parseData(const std::string& rawData)
	{
		cout << "parse " + rawData << std::endl; return "PDF data";
	}
	void closeFile(const std::string& file)
	{
		cout << "close " + file << std::endl;
	}
};

class XMLDataMiner : public DataMiner
{
	std::string openFile(const std::string& path)
	{
		cout << "open file " + path << std::endl; return "XMLfile";
	}
	std::string extractData(const std::string& file)
	{
		cout << "extract data from " + file << std::endl; return "XML raw data";
	}
	std::string parseData(const std::string& rawData)
	{
		cout << "parse " + rawData << std::endl; return "XML data";
	}
	void closeFile(const std::string& file)
	{
		cout << "close " + file << std::endl;
	}
};


int main()
{
	std::cout << "PDF:\n";
	DataMiner* dataMiner = new PDFDataMiner();
	dataMiner->mine("path/to/PDFfile");
	delete dataMiner;

	std::cout << "\n\nXML:\n";
	dataMiner = new XMLDataMiner();
	dataMiner->mine("path/to/XMLfile");
	delete dataMiner;
}
