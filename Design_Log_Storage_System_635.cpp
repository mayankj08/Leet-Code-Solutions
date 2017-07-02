#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cassert>
#include<map>

class LogSystem {
	public:
		LogSystem() {
		}

		std::vector<std::string> parse(std::string s){
			std::stringstream ss(s);
			std::string token;
			std::vector<std::string> ret;
			while(std::getline(ss,token,':')){
				ret.push_back(token);
			}

			return ret;
		}

		void put(int id, std::string timestamp) {

			if(data.find(timestamp) == data.end()){
				//std::cout << " Adding new row in data\n";
				std::vector<int> newVec;
				newVec.push_back(id);
				data[timestamp] = newVec;
			}
			else{
				//std::cout << " Appending to row in data\n";
				data[timestamp].push_back(id);
			}
		}

		std::vector<int> retrieve(std::string s, std::string e, std::string gra) {
			std::vector<int> ret;	
			std::string fmt;

			auto stimeVec = parse(s);
			auto etimeVec = parse(e);

			if(gra == "Year"){
				s = stimeVec[0] + ":" + "01:01:00:00:00";
				e = etimeVec[0] + ":" + ":12:31:23:59:59";
			}
			else if(gra ==  "Month"){
				s = stimeVec[0] + ":" + stimeVec[1] + ":01:00:00:00";
				e = etimeVec[0] + ":" + etimeVec[1] + ":31:23:59:59";
			}
			else if(gra == "Day"){
				s = stimeVec[0] + ":" + stimeVec[1] + ":" + stimeVec[2] + ":00:00:00";
				e = etimeVec[0] + ":" + etimeVec[1] + ":" + etimeVec[2] + ":23:59:59";
			}
			else if(gra == "Hour"){
				s = stimeVec[0] + ":" + stimeVec[1] + ":" + stimeVec[2] + ":" + stimeVec[3] + ":00:00";
				e = etimeVec[0] + ":" + etimeVec[1] + ":" + etimeVec[2] + ":" + etimeVec[3] + ":59:59";
			}
			else if(gra ==  "Minute"){
				s = stimeVec[0] + ":" + stimeVec[1] + ":" + stimeVec[2] + ":" + stimeVec[3] + ":" + stimeVec[4] + ":00";
				e = etimeVec[0] + ":" + etimeVec[1] + ":" + etimeVec[2] + ":" + etimeVec[3] + ":" + stimeVec[4] + ":59";
			}
			else if (gra == "Second"){
			}

			for(auto elem : data){

				std::cout
					<< " s: " << s
					<< " e: " << e
					<< " elem.first: " << elem.first << '\n';

				if(s <= elem.first and elem.first <= e){
					for(auto p : elem.second)
						ret.push_back(p);
				}

			}	

			return ret;
		}

	private:
		std::map<std::string,std::vector<int> > data;

};

int main(){
	{
		LogSystem *obj = new LogSystem();
		obj->put(1,"2017:01:01:23:59:59");
		obj->put(2, "2017:01:01:22:59:59");
		obj->put(3, "2016:01:01:00:00:00");
		std::vector<int> param_2 = obj->retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");
		assert(param_2.size() == 3);
	}

	{
		LogSystem *obj = new LogSystem();
		obj->put(1,"2017:01:01:23:59:59");
		obj->put(2, "2017:01:01:22:59:59");
		obj->put(3, "2016:01:01:00:00:00");
		std::vector<int> param_2 = obj->retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
		assert(param_2.size() == 2);
	}

	{
		LogSystem *obj = new LogSystem();
		obj->put(1,"2017:01:01:23:59:59");
		obj->put(4,"2017:01:01:23:59:59");
		obj->put(2, "2017:01:01:22:59:59");
		obj->put(3, "2016:01:01:00:00:00");
		std::vector<int> param_2 = obj->retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
		assert(param_2.size() == 3);
	}


	{
		LogSystem *obj = new LogSystem();
		obj->put(1,"2017:01:01:23:59:59");
		obj->put(4,"2017:01:01:23:59:59");
		obj->put(2, "2017:01:01:22:59:59");
		obj->put(3, "2016:01:01:00:00:00");
		std::vector<int> param_2 = obj->retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
		assert(param_2.size() == 3);
	}

	{
		LogSystem *obj = new LogSystem();
		obj->put(1,"2017:01:01:23:59:59");
		obj->put(2,"2017:01:02:23:59:59");
		std::vector<int> param_2 = obj->retrieve("2017:01:01:23:59:59","2017:01:02:23:59:59","Month");
		for(auto elem : param_2){
			std::cout << elem << " " ;
		}
	}

}
