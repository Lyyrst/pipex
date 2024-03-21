<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="logo/Redfox_coding.jpg" alt="Logo" width="160" height="160">
  </a>

  <h3 align="center">PIPEX</h3>



</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The pipex project is here to get us started with environment variable and command executions.
-> Pipe(), fork(), char **envp;

The programe take 4 arguments :

-> infile (a file to execute the first command on)

-> a first bash command execute from the outfile

-> a second bash command execute from the return of the first command

-> outfile (store the result of the second command in)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

This is a C library so you need to have gcc compiler.
  ```sh
  sudo apt-get install gcc -y
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Lyyrst/Libft.git
2. Makefile !
   ```sh
   make && make clean
   ```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Run the command like this :
```sh
./pipex infile cmd1 cmd2 outfile
```
for example :
```sh
./pipex Makefile cat "wc -l" outfile
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

[Discord : lyrst](https://discord.com/users/257192704537001984)

kurt.butorp@gmail.com

## Reminder

Please remember that this project is one of the first I did as a computer science learner, it does not reflect my actual skills but through which project I learned programming.
