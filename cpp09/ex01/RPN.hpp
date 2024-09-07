#ifndef RPN_HPP
#define RPN_HPP

#define ERR_INPUT "Error: Invalid RPN input, please check your expression"
#define ERR_NBR "Error: Invalid number"
#define ERR_OPERATION "Error: Unknown operation"
#define ERR_NBR_MAX "Error: Number too big"
#define ERR_SYMBOL "Error: Invalid symbol"
#define ERR_STACK "Error: Not all numbers were used"

#include <stack>
#include <string>

enum e_op {
	DIV,
	MULT,
	SUB,
	SUM,
	DIGIT,
	ERROR
};

class RPN {
public:
	RPN(void);
	RPN(RPN const &obj);
	RPN &operator=(RPN const &obj);
	~RPN(void);

	void run(std::string const &str);

private:
	std::stack<int> stack;

	bool	  isValidChar(char c);
	enum e_op parseInput(std::string &str);
	void	  doOperation(int &a, int &b, enum e_op op);
	bool	  isValidInput(std::string const &str);
	void	  print(void);
};

#endif
