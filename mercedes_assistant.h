#if !defined(MERCEDES_ASSISTANT_H)
#define MERCEDES_ASSISTANT_H
#include "iohandler.h"
#include <vector>

class Mercedes_Assistant {
private:
  std::string user_command_;
  std::string assistant_answer_;
  const std::vector<std::pair<std::string, std::string>>
      predefined_user_commands_and_answers_ = {
          {"What is the weather like today", "Intent: Get Weather"},
          {"What is the weather like in Paris today",
           "Intent: Get Weather City"},
          {"What is the weather like in New York today",
           "Intent: Get Weather City"},
          {"Am I free at 13:00 PM tomorrow", "Intent: Check calendar"},
          {"Tell me an interesting fact", "Intent: Get Fact"}};

public:
  Mercedes_Assistant() = default;

  // Returns 0 if command is recognized and -1 if it is not
  int user_intent_recognition(const std::string &user_command);
  void print_assistant_answer();
  std::string get_assistant_answer() { return assistant_answer_;};
};

#endif /// MERCEDES_ASSISTANT_H