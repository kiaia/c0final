#include "fmt/core.h"
#include "tokenizer/tokenizer.h"
#include "analyser/analyser.h"

namespace fmt {
	template<>
	struct formatter<miniplc0::ErrorCode> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::ErrorCode &p, FormatContext &ctx) {
			std::string name;
			switch (p) {
			case miniplc0::ErrNoFunciton:
				name "no funciotn";
				break;
			case miniplc0::ErrNeedReturnValue:
					name= "no return";
					break;
				case miniplc0::ErrVoid:
						name = "no void";
						break;
				case miniplc0::ErrNeedRightCurly:
					name = "uncom";
					break;
				case miniplc0::ErrNeedLeftCurly:
					name = "uncom";
					break;
				case miniplc0::ErrNeedLeftBracket:
					name = "uncom";
					break;
				case miniplc0::ErrType:
					name = "uncom";
					break;
				case miniplc0::ErrNoType:
					name = "uncom";
					break;
			case miniplc0::ErrNoError:
				name = "No error.";
				break;
			case miniplc0::ErrStreamError:
				name = "Stream error.";
				break;
			case miniplc0::ErrEOF:
				name = "EOF";
				break;
			case miniplc0::ErrInvalidInput:
				name = "The input is invalid.";
				break;
			case miniplc0::ErrInvalidIdentifier:
				name = "Identifier is invalid";
				break;
			case miniplc0::ErrIntegerOverflow:
				name = "The integer is too big(int64_t).";
				break;
			case miniplc0::ErrNoBegin:
				name = "The program should start with 'begin'.";
				break;
			case miniplc0::ErrNoEnd:
				name = "The program should end with 'end'.";
				break;
			case miniplc0::ErrNeedIdentifier:
				name = "Need an identifier here.";
				break;
			case miniplc0::ErrConstantNeedValue:
				name = "The constant need a value to initialize.";
				break;
			case miniplc0::ErrNoSemicolon:
				name = "Zai? Wei shen me bu xie fen hao.";
				break;
			case miniplc0::ErrInvalidVariableDeclaration:
				name = "The declaration is invalid.";
				break;
			case miniplc0::ErrIncompleteExpression:
				name = "The expression is incomplete.";
				break;
			case miniplc0::ErrNotDeclared:
				name = "The variable or constant must be declared before being used.";
				break;
			case miniplc0::ErrAssignToConstant:
				name = "Trying to assign value to a constant.";
				break;
			case miniplc0::ErrDuplicateDeclaration:
				name = "The variable or constant has been declared.";
				break;
			case miniplc0::ErrNotInitialized:
				name = "The variable has not been initialized.";
				break;
			case miniplc0::ErrInvalidAssignment:
				name = "The assignment statement is invalid.";
				break;
			case miniplc0::ErrInvalidPrint:
				name = "The output statement is invalid.";
				break;
			}
			return format_to(ctx.out(), name);
		}
	};

	template<>
	struct formatter<miniplc0::CompilationError> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::CompilationError &p, FormatContext &ctx) {
			return format_to(ctx.out(), "Line: {} Column: {} Error: {}", p.GetPos().first, p.GetPos().second, p.GetCode());
		}
	};
}

namespace fmt {
	template<>
	struct formatter<miniplc0::Token> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::Token &p, FormatContext &ctx) {
			return format_to(ctx.out(),
				"Line: {} Column: {} Type: {} Value: {}",
				p.GetStartPos().first, p.GetStartPos().second, p.GetType(), p.GetValueString());
		}
	};

	template<>
	struct formatter<miniplc0::TokenType> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::TokenType &p, FormatContext &ctx) {
			std::string name;
			switch (p) {
			case miniplc0::NULL_TOKEN:
				name = "NullToken";
				break;
			case miniplc0::UNSIGNED_INTEGER:
				name = "UnsignedInteger";
				break;
			case miniplc0::IDENTIFIER:
				name = "Identifier";
				break;
			case miniplc0::BEGIN:
				name = "Begin";
				break;
			case miniplc0::END:
				name = "End";
				break;
			case miniplc0::VAR:
				name = "Var";
				break;
			case miniplc0::CONST:
				name = "Const";
				break;
			case miniplc0::PRINT:
				name = "Print";
				break;
			case miniplc0::PLUS_SIGN:
				name = "PlusSign";
				break;
			case miniplc0::MINUS_SIGN:
				name = "MinusSign";
				break;
			case miniplc0::MULTIPLICATION_SIGN:
				name = "MultiplicationSign";
				break;
			case miniplc0::DIVISION_SIGN:
				name = "DivisionSign";
				break;
			case miniplc0::EQUAL_SIGN:
				name = "EqualSign";
				break;
			case miniplc0::SEMICOLON:
				name = "Semicolon";
				break;
			case miniplc0::LEFT_BRACKET:
				name = "LeftBracket";
				break;
			case miniplc0::RIGHT_BRACKET:
				name = "RightBracket";
				break;
			}
			return format_to(ctx.out(), name);
		}
	};
}

namespace fmt {
	template<>
	struct formatter<miniplc0::Operation> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::Operation &p, FormatContext &ctx) {
			std::string name;
			switch (p) {

			
			case miniplc0::IRET:
				name = "IRET";
				break;
			case miniplc0::JE:
				name = "JE";
				break;
			case miniplc0::JNE:
				name = "JNE";
				break;
			case miniplc0::JL:
				name = "JL";
				break;
			case miniplc0::JGE:
				name = "JGE";
				break;
			case miniplc0::JG:
				name = "JG";
				break;
			case miniplc0::JLE:
				name = "JLE";
				break;
			case miniplc0::LOADA:
				name = "LOADA";
				break;
			case miniplc0::LOADC:
				name = "LOADC";
				break;
			case miniplc0::IPUSH:
				name = "IPUSH";
				break;
			case miniplc0::BIPUSH:
				name = "BIPUSH";
				break;
			case miniplc0::NEW:
				name = "NEW";
				break;
			case miniplc0::SNEW:
				name = "SNEW";
				break;
			case miniplc0::POP:
				name = "POP";
				break;
			case miniplc0::DUP:
				name = "DUP";
				break;
			case miniplc0::I2D:
				name = "I2D";
				break;
			case miniplc0::I2C:
				name = "I2C";
				break;
			case miniplc0::D2I:
				name = "D2I";
				break;
			case miniplc0::JMP:
				name = "JMP";
				break;
			case miniplc0::CALL:
				name = "NAME";
				break;
			case miniplc0::RET:
				name = "RET";
				break;
			case miniplc0::TRET:
				name = "";
				break;
			case miniplc0::ILOAD:
				name = "ILOAD";
				break;
			case miniplc0::ISTORE:
				name = "ISTORE";
				break;
			case miniplc0::IALOAD:
				name = "IALOAD";
				break;
			case miniplc0::IADD:
				name = "IADD";
				break;
			case miniplc0::ISUB:
				name = "ISUB";
				break;
			case miniplc0::IMUL:
				name = "IMUL";
				break;
			case miniplc0::IDIV:
				name = "IDIV";
				break;
			case miniplc0::INEG:
				name = "INEG";
				break;
			case miniplc0::ICMP:
				name = "ICMP";
				break;
			case miniplc0::IPRINT:
				name = "IPRINT";
				break;
			case miniplc0::SPRINT:
				name = "SPRINT";
				break;
			case miniplc0::PRINTL:
				name = "PRINTL";
				break;
			case miniplc0::ISCAN:
				name = "ISCAN";
				break;
		
				break;

			}
			return format_to(ctx.out(), name);
		}
	};
	template<>
	struct formatter<miniplc0::Instruction> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const miniplc0::Instruction &p, FormatContext &ctx) {
			/*std::string name;
			switch (p.GetOperation())
			{
			case miniplc0::ILL:
			case miniplc0::ADD:
			case miniplc0::SUB:
			case miniplc0::MUL:
			case miniplc0::DIV:
			case miniplc0::WRT:
				return format_to(ctx.out(), "{}", p.GetOperation());
			case miniplc0::LIT:
			case miniplc0::LOD:
			case miniplc0::STO:
				return format_to(ctx.out(), "{} {}", p.GetOperation(), p.GetX());
			}
			return format_to(ctx.out(), "ILL");*/
		}
	};
}