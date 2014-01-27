#ifndef KWIC_H_
	#define KWIC_H_

	class string;
	class Kwic
	{
		private:
			std::string _keyword;
			std::string _title;
			uint _priority;

		public:
			Kwic();
			Kwic(std::string keyword, std::string title, int id);
			virtual ~Kwic();
			const std::string& getKeyword() const;
			const std::string& getTitle() const;
			const uint getPriority() const;
			uint getPriority();
			std::string& getKeyword();
			std::string& getTitle();
			bool operator<(const Kwic& kwic) const;
	};
#endif
