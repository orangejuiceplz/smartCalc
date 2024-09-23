> [!IMPORTANT]
> This project will not be updated anytime soon as the core fucntionality is fine as is.
> I will continue to work on other things in the meantime.

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
|  5  | I sucessfully got wxWidgets to work and built the project using cmake, thats why there is some C and some CMakeList languages located in the respository. After linking the libs and getting the graphing GUI to work, I might just start converting everything to have a GUI element. I finally have some hope. Although I haven't really dealt with API's yet, and I probably should start doing that before I convert everything to a GUI, I should be okay. The current version today, v1.6.0, was built with Visual Studio 17 (2022) for x64 architectures. I've just been looking into the wxWidgets stuff and I might rewrite/rework how the GUI works right now, as you can only graph a limited amount of stuff right now. I think I already wrote the logic for normal functions, All I need to do is incorporate it. I might also use NSIS to help with the distribution of the exe. However, the only issue is that I spent about a good amount of time having to convert everything into main.cpp insteaad of breaking it into multiple files since I don't like linking the files and everything.       |
|  6  | I'm going to test headerfiles again. I think after reading up a lot more on the documentation, I think I can probably successfully link these files without any issues. CMake GUI should make it a whole lot easier since I really don't like terminals (even though I have arch linux). So rightnow I've created a new branch called 'dev' or something which will slowly document all of these changes. Other than that, not a whole lot of progress. I guess I am starting to slowly convert everything to a GUI function instead of CLI. I- think I can do this with the short amount of time I have left. API's may be truncated in the worst case scenario.     |
|  7  | Good news is that everything worked as expected. Code compiled and everything and I'm a very happy person. One issue, though. I had to switch from using VSC to using VS. Its not ideal, and I do like using VSC as my primary code editor, followed by neovim (and vim ofc), but it gets the job done faster and I only really have to configure one time. Thats great. I added all of the GUI featurse for what methods I have right now in my files, so thats good. The UI looks really bad though, and I'm dissapointed with myself that I made something that bad (to be fair, it is my first time using wxWidgets so my UI knowledge with this library is pretty scarce.           |
|  8  | I haven't done a whole lot to pretty up the GUI's. I'll be okay so its fine. I managed to add currency conversion so we don't have to cut that. I will just add better graphing logic and finish unit conversions. Not a whole lot today, I'll do the GUI stuff when I get home so I can see the changes in real time. I will also use NSIS now to actually get a distributable exe or just use whatever visual studio has in their arsenal.      |
|  9  | No longer in use         |
| 10  | No longer in use         |
| 11  | No longer in use         |

## Getting setup with the calculator:

In the folder, if you're using VS17, just build the Release x64 solution. You actually need 

Steps:

Clone the repository
Double click SmartCalculator.sln (MUST HAVE VS17 (2022) INSTALLED)
On the dropdown, click "Release".
Make sure the Arch is set to x64.
Press Control + Shift + B to build the solution
Open the build folder, click releases, click x64 or smth, then the exe should be there.
Enjoy.

## Sidenotes

> ## Reflections on the project.

SmartCalc is something I have somewhat enjoyed working on. I'm also planning on using parts of the code for some logic in a couple other things that I am working on, such as my game I'm developing. I feel like it was just a good challenge to my C++ skills over a short amount of days, similar to like fizzbuzz but just longer. I also got to properely experiment with some new libraries that I wasn't exactly familar with, such as wxWidgets. I feel like I learned a lot from this project, even if most of it was just a refresher for me because I've done some C++ work before. I'm not exactly happy with how it looks and just works, it was probably just better to code my own library instead of having to create a whole bunch of classes for it, but oh well, I don't really care anyway.

> ---
>> if you're some random feel free to explore the code, contribute, or reach out if you're interested in making some suggestions

