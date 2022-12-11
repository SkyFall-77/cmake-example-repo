#include <gtest/gtest.h>
#include "bmstu_string.h"


TEST(Operator, CopyPrisvaivanie) {
    bmstu::basic_string str1 = "virtual studio cod";
    bmstu::basic_string<char> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str2.c_str(), "virtual studio cod");
    ASSERT_STREQ(str1.c_str(), "virtual studio cod");
}

TEST(Operator, RuCopyPrisvaivanie) {
    bmstu::basic_string str1 = L"Платон строит город";
    bmstu::basic_string<wchar_t> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str1.c_str(), L"Платон строит город");
    ASSERT_STREQ(str2.c_str(), L"Платон строит город");


}

TEST(Operator, MovePrisvaivanie) {
    bmstu::basic_string str1 = "top gun Maverik";
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), "top gun Maverik");
}

TEST(Operator, RuMovePrisvaivanie) {
    bmstu::basic_string<wchar_t> str1 = L"я верю в бога";
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), L"я верю в бога");
}

TEST(Operator, MoveSamoPrisvaivanie) {
    bmstu::basic_string str1 = "tanki online";
    str1 = std::move(str1);
    ASSERT_STREQ(str1.c_str(), "tanki online");
}

TEST(Operator, RuMoveSamoPrisvaivanie) {
    bmstu::basic_string<wchar_t> str1 = L"ошибка в баре";
    str1 = std::move(str1);
    ASSERT_EQ(str1.size(), 16);
    ASSERT_STREQ(str1.c_str(), L"ошибка в баре");
}

TEST(Operator, PrisvaivaniyaCStr) {
    bmstu::basic_string<char> str;
    str = "really hard";
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "really hard");
}

TEST(Operator, RuPrisvaivaniyaCStr) {
    bmstu::basic_string<wchar_t> str;
    str = L"Я могу летать";
    ASSERT_EQ(str.size(), 13);
    ASSERT_STREQ(str.c_str(), L"Я могу летать");
}

TEST(Operator, Concatinacii) {
    bmstu::basic_string str1("Dead ");
    bmstu::basic_string str2("Inside");
    bmstu::basic_string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 11);
    ASSERT_STREQ(str3.c_str(), "Dead Inside");
}

TEST(Operator, RuConcotenacii) {
    bmstu::basic_string str1 = L"Торетто ";
    bmstu::basic_string str2 = L"сильный";
    bmstu::basic_string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 13);
    ASSERT_STREQ(str3.c_str(), L"Торетто сильный");
}

TEST(Operator, KonkotinirushiyPrisvaivania) {
    bmstu::basic_string str1 = "Jlexa Jlepexa";
    bmstu::basic_string str2 = "torchok";
    str1 += str2;
    ASSERT_EQ(str1.size(), 14);
    ASSERT_STREQ(str1.c_str(), "Jlexa Jlepexa torchok");
}

TEST(Operator, RuKonkotinirushiyPrisvaivania) {
    bmstu::basic_string str1 = L"кипиш ";
    bmstu::basic_string str2 = L"магия";
    str1 += str2;
    ASSERT_EQ(str1.size(), 13);
    ASSERT_STREQ(str1.c_str(), L"кипиш магия");
}

TEST(Operator, PribavleniyaSimvola) {
    bmstu::basic_string str = "Poydem v zags ";
    str += 'l';
    ASSERT_EQ(str.size(), 14);
    ASSERT_STREQ(str.c_str(), "Poydem v zags");
}

TEST(Operator, RuPribavleniyaSimvola) {
    bmstu::basic_string<wchar_t> str = L"зов";
    str += L'в';
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), L"зо");
}

TEST(Operator, SimvolaPoIndexu) {
    bmstu::basic_string str = "dayte sto derxam";
    ASSERT_EQ(str[2], 'i');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, RuSimvolaPoIndexu) {
    bmstu::basic_string<wchar_t> str = L"праздновать новый год";
    ASSERT_EQ(str[6], L'н');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, cout) {
    bmstu::basic_string str = "pubg mobile";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, RuCout) {
    bmstu::basic_string str = "я хочу спать";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, cin) {
    std::stringstream str;
    str.str("lol");
    bmstu::basic_string str2("tutorial");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "God");
}

TEST(Operator, RUcin) {
    std::stringstream str;
    str.str("Рокки Бальбоа сильнейший боксер");
    bmstu::basic_string str2("Никита сдал норматив по физкультуре");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "Рокки Бальбоа сильнейший боксер");
}

TEST(Getters, c_sring) {
    bmstu::basic_string str("Anrey slab");
    ASSERT_STREQ(str.c_str(), "Andrey slab");
}

TEST(Getters, ru_c_sring) {
    bmstu::basic_string<wchar_t> str(L"ДАндрей очень очень слаб");
    ASSERT_STREQ(str.c_str(), L"Андрей очень очень слаб");
}

TEST(Getters, SizeOfStr) {
    bmstu::basic_string str = "rofl ufc";
    ASSERT_EQ(str.size(), 21);
}

TEST(Getters, RuSizeOfStr) {
    bmstu::basic_string<wchar_t> str = L"я Никита";
    ASSERT_EQ(str.size(), 68);
}

TEST(Constructor, DefaultConstructor) {
    bmstu::basic_string<char> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(Constructor, WideStrDefaultConstructor) {
    bmstu::basic_string<wchar_t> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"");
}

TEST(Constructor, en_c_string) {
    bmstu::basic_string str("ia Jlublu progu");
    const char *c_str = "ia Jlublu progu";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST(Constructor, ru_c_string) {
    bmstu::basic_string<wchar_t> str(L"Преподаватель Эгэ");
    const wchar_t *c_str = L"Преподаватель Эгэ";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST (Constructor, WithCStringParametrsNullptr) {
    bmstu::basic_string str = "";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "\0");
}

TEST (Constructor, WideWithCStringParametrsNullptr) {
    bmstu::basic_string<wchar_t> str = L"";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"\0");
}

TEST (Constructor, WithCstringParametrs) {
    bmstu::basic_string str("ugrau v pubg");
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "ugrau v pubg");
}

TEST (Constructor, RuWithCstringParametrs) {
    bmstu::basic_string<wchar_t> str(L"большая рука");
    ASSERT_EQ(str.size(), 30);
    ASSERT_STREQ(str.c_str(), L"большая рука");
}

TEST(Constructor, CopyConstructor) {
    bmstu::basic_string str1("pomogite");
    bmstu::basic_string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, RuCopyConstructor) {
    bmstu::basic_string<wchar_t> str1(L"практически завершенный");
    bmstu::basic_string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, MoveConstructor) {
    bmstu::basic_string str1 = "skyfall chilit";
    bmstu::basic_string<char> str2;
    str2 += str1;
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}
TEST(Constructor, RuMoveConstructor) {
    bmstu::basic_string<wchar_t> str1 = L"я хочу спать";
    bmstu::basic_string<wchar_t> str2;
    str2 += str1;
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}