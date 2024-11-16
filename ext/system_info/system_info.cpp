#include <iostream>
#include <string>
#include <sys/sysctl.h>

std::string get_cpu_info()
{
  char cpu_name[128];
  size_t size = sizeof(cpu_name);
  sysctlbyname("machdep.cpu.brand_string", &cpu_name, &size, NULL, 0);
  return std::string(cpu_name);
}

std::string get_memory_info()
{
  int64_t mem;
  size_t size = sizeof(mem);
  sysctlbyname("hw.memsize", &mem, &size, NULL, 0);
  return "Total RAM: " + std::to_string(mem / 1024 / 1024) + " MB";
}

extern "C" const char *get_system_info()
{
  static std::string info = "CPU: " + get_cpu_info() + "\n" + get_memory_info();
  return info.c_str();
}
