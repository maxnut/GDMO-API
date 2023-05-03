#pragma once
#include <functional>
#include <string>
#include <vector>

namespace GDMO
{
void addImGuiFunc(std::function<void()> func);

//most of these are wrapper function for imgui with added functionality,
//you can check out how imgui works here https://github.com/ocornut/imgui/tree/master/docs

void ImBegin(const char* name);
void ImEnd();
void ImText(const char* text);

void Marker(const char* marker, const char* desc);
bool ImHotkey(const char* label, int* k);
bool ImCheckbox(const char* label, bool* v, bool canMakeShortcut = true);
bool ImButton(const char* label, bool canMakeShortcut = true);
bool ImInputFloat(const char* label, float* v);
bool ImInputInt(const char* label, int* v, int step = 1);
bool ImInputInt2(const char* label, int* v);
bool ImInputText(const char* label, char* buf, size_t buf_size);
bool ImCombo(const char* label, int* current_item, const char* const* items, int items_count);
bool ImColorEdit3(const char* label, float* col, int flags);

//basic memory writing functions

template <class T> void WriteRef(uint32_t vaddress, const T& value);
template <class T> bool Write(uint32_t vaddress, const T& value);
std::vector<uint8_t> ReadBytes(uint32_t vaddress, size_t size);
template <class T> T Read(uint32_t vaddress);
bool writeBytes(std::uintptr_t const address, std::vector<uint8_t> const& bytes);

//debug funcs to write to output.txt
void writeOutput(std::string out);
void writeOutput(int out);
void writeOutput(float out);
void writeOutput(double out);

//save and load functions
void SaveInt(const char* filename, const char* key, int value);
void SaveBool(const char* filename, const char* key, bool value);
void SaveFloat(const char* filename, const char* key, float value);
void SaveDouble(const char* filename, const char* key, double value);
void SaveString(const char* filename, const char* key, const char* value);
void ReadInt(const char* filename, const char* key, int* value);
void ReadBool(const char* filename, const char* key, bool* value);
void ReadFloat(const char* filename, const char* key, float* value);
void ReadDouble(const char* filename, const char* key, double* value);
void ReadString(const char* filename, const char* key, std::string *value);

void Init(std::string name, std::function<void()> openCallback, std::function<void()> closeCallback);
};