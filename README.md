# Hello C++ Durban

Hello C++ Durban is a set of code samples for learning purposes made by members of the C++ Durban community.

The two examples are:

* Hello JSON: [examples/hello-json](examples/hello-json)
* Hello TOML: [examples/hello-toml](examples/hello-toml)
* Hello HTTP Server: [examples/hello-http-server](examples/hello-http-server)
* GUI examples:
  * Hello wxWidgets: [examples/hello-wx-widgets](examples/hello-wx-widgets)
  * Hello ImGui + SFML: [examples/hello-imgui-sfml](examples/hello-imgui-sfml)
  * Hello Wt: [examples/hello-wt](examples/hello-wt)

Go into the directory of each to find the readme describing how they work.

## Setup
To compile and run each example, you will need Python installed as well as a C++ compiler.

To make sure that **conan install** and **conan build** work correctly, you need a OS default toolchain installed.

The below instructions should apply, in most cases, in setting up your default toolchain.

* For Windows:
    * Chocolately is the easiest way to get started: https://chocolatey.org/install
    * With Chocolatey installed, run the following in an admin shell: ```choco install visualstudio2019buildtools --package-parameters "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended --passive"```
* For GNU/Linux:
    * Some distributions come with GCC by default. You can verify by typing ```where gcc``` into your shell and checking the result.
    * Depending on your distro, you can type:
        * ```sudo apt-get install build-essential```
        * ```sudo pacman -S base-devel```
        * Any other related package manager command for installing a C++ compiler toolchain
* For MacOS:
    * Try the following: https://www.ics.uci.edu/~pattis/common/handouts/macclion/clang.html
    
