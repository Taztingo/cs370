#ifndef KWIC_H_
	#define KWIC_H_

	#include <string>
	class Kwic
	{
		private:
			std::string _keyword;
			std::string _title;

		public:
			Kwic();
			Kwic(std::string keyword, std::string title);
			virtual ~Kwic();
			std::string& getKeyword();
			std::string& getTitle();
			bool operator<(Kwic& kwic);
	};
#endif
