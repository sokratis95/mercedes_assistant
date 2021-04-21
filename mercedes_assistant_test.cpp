#include "mercedes_assistant.h"
#include "gtest/gtest.h"


TEST(Intent_Recognition_Test, intent_wrong_command) {
  
  std::string user_command = "Wrong command given";
  Mercedes_Assistant hey_mercedes;

  ASSERT_EQ(-1, hey_mercedes.user_intent_recognition(user_command));
}

TEST(Intent_Recognition_Test, intent_correct_command) {
  
  std::string user_command = "What is the weather like today";
  Mercedes_Assistant hey_mercedes;

  ASSERT_EQ(0, hey_mercedes.user_intent_recognition(user_command));
}

TEST(Intent_Recognition_Test, intent_get_weather) {
  
  std::string user_command = "What is the weather like today";
  Mercedes_Assistant hey_mercedes;
  hey_mercedes.user_intent_recognition(user_command);
  std::string expected_intent_recognition = "Intent: Get Weather";

  ASSERT_EQ(expected_intent_recognition, hey_mercedes.get_assistant_answer());
}

TEST(Intent_Recognition_Test, intent_get_weather_city) {
  
  std::string user_command = "What is the weather like in Paris today";
  Mercedes_Assistant hey_mercedes;
  hey_mercedes.user_intent_recognition(user_command);
  std::string expected_intent_recognition = "Intent: Get Weather City";

  ASSERT_EQ(expected_intent_recognition, hey_mercedes.get_assistant_answer());
}

TEST(Intent_Recognition_Test, intent_check_calendar) {
  
  std::string user_command = "Am I free at 13:00 PM tomorrow";
  Mercedes_Assistant hey_mercedes;
  hey_mercedes.user_intent_recognition(user_command);
  std::string expected_intent_recognition = "Intent: Check calendar";

  ASSERT_EQ(expected_intent_recognition, hey_mercedes.get_assistant_answer());
}

TEST(Intent_Recognition_Test, intent_get_fact) {
  
  std::string user_command = "Tell me an interesting fact";
  Mercedes_Assistant hey_mercedes;
  hey_mercedes.user_intent_recognition(user_command);
  std::string expected_intent_recognition = "Intent: Get Fact";

  ASSERT_EQ(expected_intent_recognition, hey_mercedes.get_assistant_answer());
}