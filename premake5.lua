-- premake5.lua
workspace "kiwi"
   configurations { "Debug", "Release" }

project "kiwi"
   kind "WindowedApp"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.c", "**.hpp", "**.cpp", "**.cc", "**.cxx", "**.inl" }
   defines { "_WIN32", "WIN32" }
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"