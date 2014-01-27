#ifndef KWIC_H_
	#define KWIC_H_

	class string;
	class Kwic
	{
		private:
			std::string _keyword;
			std::string _title;
			uint priority;

		public:
			Kwic();
			Kwic(std::string keyword, std::string title);
			virtual ~Kwic();
			const std::string& getKeyword() const;
			const std::string& getTitle() const;
			std::string& getKeyword();
			std::string& getTitle();
			bool operator<(const Kwic& kwic) const;
	};
#endif
