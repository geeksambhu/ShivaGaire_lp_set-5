# Shiva_LP_5
This repository contains solution to some computer science problems in most effecient ways I could. It also introduces you to 
**TDD (Test Driven Development)** approach of software development which is well known to minimize bugs and security vulnerabilities. In this project I tried to use `Single Responsibility Principle` to make functions and objects more comprehensible and reusable, following OOD techniques.

## Q1. 
The four adjacent digits in the 1000-digit numerals that have the greatest product are 9x9x8x9=5832(for example). Find 
the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of the product?

```
8878756113405462575236653918726828134778693925674034151
7920137625375876563745112107265430496279395295067699468
9563593119860008704378908986898621070005873283268716687
7498755251383504478363147843493162078644536995056796611
0806555533435454864213320704872729760354066688603887209
5485805490493874794592301832103786710261571321930280217
8598033345524930002157694783127368530220610659786256607
6575139449397052724906681901127595408234785540379464472
4431427152957506002654055044998765906655688168331378025
8190795796296444851914755539057934382177170706812832212
6432331761260710710173710066308289621014771600086722835
6114778194252923577772867965453728107193374989067541585
2320669499225713859402058885967278295238434874442519887
1646676870098501069195635642520262048795344914839300759
4758920106117509827855382635829624391516212247383089673
1070699438944769831283902254560518293705210378714927449
6836773363519307227247419925985214110825417051726020608
4305901433616790722383667731628477257006269721674213129
2430995753135566968510753715438054483624324193763271940
7741909247566403472058645026267523175227666253490715607
```

### Solution

I will be going through the following process to get the expected solution. See **System Overview and block diagram**.

### Updates

However, the process followed here will be long. 
So, I have choosen **Regular Expression** with `python` to solve the problem as **regex** will make computation efficent.
 See `q1.py` file for python implementation

#### System Overview/Block diagram
![UML diagram of the object; w/ private data and public API](images/block_diagram.png)
#### Write Failing Test cases
#### Write codes to make the tests go green.
#### Refactored code
  Making code look good, optimizing code, adding/trimming comments.

## Q2
A palindromic number reads the same both ways. The largest palindome made from the product of two 2-digit 
number is 9009 = 91 x 99.  
Find the largest palindrome made from the product of two 3-digit numbers.  
#### System Overview/Block diagram
![UML diagram of the object; w/ private data and public API](images/q2_block_diagram.png)
#### Write Failing Test cases
#### Write codes to make the tests go green.
#### Refactored code
  Making code look good, optimizing code, adding/trimming comments.
## Q3

**Test Case Scenario**  
For application In the division calculator Input 1 and Input 2 is divisor, 
When clicked on Divide button, it should perform division of two number 
specified in the two fields and should show result on result box.

## Q4
If I were a project manager I would use Agile model of software development
for the planning of web application. I would prefer to be bounded under the principles of Agile's Scrum framework.
The steps would be: 

    1. Gathering all the requirements/user story as a product backlog from end-users or a product owner.
        
    2. Breaking down of product backlogs into release backlogs and further breaking release backlogs
       into number of sprint backlogs for each release.
       Sprints are the short duration milestone, that ensures the project is progressing to its goal.
      
    3. Monitoring the project sprint using burndown chart.
       Burndown chart helps us to know if we are in time or not with project shipping time.
       
    4. Organising daily Scrum meeting, to ensure everything is on track,
       and to know the difficulties faced by team members.
       
    5. After each sprint , organising a Retrospective meeting to fine tune everything,
       by testing and debugging by team members for the product to be shipped

## Execution instructions
The programs are written in `ANSI C` and tested with `GCC version 6.3.0 20170406`.  
**Example: In UNIX based OSes**
```bash
$ gcc q1.c -o q1.out
# To run the executible
$ ./q1.out

# compiling q2.c is little bit tricky
$ gcc q2.c -o q2.out -lm
$ ./q2.out

#compiling q1.py
$python q1.py

```
## Note
Here, the expected output is asserted rather than displaying it to `STDOUT`. So, if you desire to display the output you can use the API in any way you want.
