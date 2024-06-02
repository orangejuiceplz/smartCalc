> [!NOTE]
> Should be almost done with the graphing GUI.

<p align="center"><img src="https://github.com/orangejuiceplz/smartCalc/blob/main/SmartCalculator.ico" height="200"></p>

<h1 align="center">🧮 smartCalc: a nice introduction to new C++ concepts and a refresher on old</h1>


Hey! Welcome to **smartCalc**, a personal project (not really) born out of a desire to master C++ concepts (somewhat true). It's more than just a calculator—it's a smart calculator where I experiment with various math concepts and functionalities, all accessible through a ~~ugly~~ pretty command-line interface (CLI). 


## Why smartCalc?

### The motivation behind the code

~~I was forced to for a comp sci project.~~ I started on this to create a multipurpose tool that could handle everything from basic calculations to complex mathematical operations. Whether it's calculating the surface area of a sphere or finding the roots of a quadratic equation, smartCalc aims to be my Ti-84 PLUS CE when it's not in reach.

### Choosing C++ Over Python

## So, whats the deal? Why write it in C++ instead of like py?

While py might seem like the obvious choice for such a project due to its simplicity and extensive library support, I chose C++ for a very specific reason **learning** the syntax and functions because its hell to pick up later.  This project serves as a practical platform to dive deeper into my understanding of C++, exploring its capabilities in a real world situations.

## Developer Roadmap:

| Day | Progress |
| --- | -------- |
|  1  | I decided on the idea of building a smart calculator (a calculator with lots of inbuilt functions) in C++. I have initialized a GitHub repo with all of the files and will start building   the.cpp file. I have all of the necessary libraries on my main computer and will use vscode as my IDE of choice. Features should include but not be limited to: basic addition, subtraction, multiplication, division, simplifying radicals, (hopefully adding currency APIs), statistical functions, complex numbers, surface area/arc length, formula 'cheat sheet', prime factorization (number theory). |
|  2  | Everything was approved, beginning research into the wxWidgets libs. View Action plan for more information to continue on from there.  We can now ~~continue~~ start offically working on the project!        |
|  3  | I'm slowly breaking everything apart for the ease of readibility, simplicity, whatever. I split the SmartCalculator into SmartCalculator.h and SmartCalculator.cpp. These will handle their respective operations. I've also began experimenting with the SFML Graphing library before I begin with the wxWidgets. So far, it seems to be compiling fine on my system, however, I will need to do more things to make this universal. Good progress so far in my opinion. Header files make it easier to work with the project because I don't need to scroll for a thousand years.       |
|  4  | I was trying to work with SFML, but it seems like to hell to deal with. I've literally tried all options (maybe not reinstalling MSYS2 or GCC). I might just straight go into just using wxWidgets instead of experimentng with SFML anymore. It seems easy to install using vcpkg which I've had preinstalled on my system before. I also think some of the syntax is a litle more intuitive and its support team/discord is a lot mroe active relative to SFML. I wont get the hours working trying to install SFML on my system back, but I can certainly make it up with the graphing. I still need to update the files in the repo with some on my local changes since I've made notable changes without comitting them to the repository. (I didn't feel like pushing changes just because I was using something I knew wasn't going to work, but oh well.        |
|  5  |          |
|  6  |          |
|  7  |          |
|  8  |          |
|  9  |          |
| 10  |          |
| 11  |          |

## Getting setup with the calculator:

In the build folder, if you're using VS17, just build the Release x64 solution. If not, use CMAKE.

## Sidenotes

> ## Reflections on the project initally.

Working on smartCalc for the short amount of time so far has been an incredibly ~~painful~~ amazing experience. From dealing with the complexities of C++ to integrating APIs for the first time, every challenge that I will encounter along the way has contributed to a deeper understanding of software development

> ---
>> if you're some random feel free to explore the code, contribute, or reach out if you're interested in making some suggestions

