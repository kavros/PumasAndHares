# Overview
* The coursework is a group exercise where you will collaborate with your fellow students in small groups to
implement the model, write tests and write user and developer documentation.

# Build
* Build project using ```make```

# Run
* Run project using ```./dist/Debug/GNU-Linux/pumasandhares```

# Documentation
* Using the following link you can edit our documentation [link](https://www.overleaf.com/8949884345ypnhgyfsphmr)

# Project Guidelines
## Format code to make readability easier
### 1.0 Braces
  * Open braces should always be at the beginning of the line after the statement that begins the block. Contents of the brace should be indented by 1 tab or 4 spaces. For example:
  
      ```C++
        if (someExpression)
        {
           DoSomething();
        }
        else
        {
           DoSomethingElse();
        }
      ```
      
### 1.1 Naming
  * Every variable has to start with a lowercase letter
  * Every function or class has to start with an uppercase letter
  * Do not use Hungarian notation [wtf is this ?](https://stackoverflow.com/questions/768255/hungarian-notation-in-c-sharp)
  * Do not use a prefix for member variables (_, m_, s_, etc.).
    If you want to distinguish between local and member variables you should use “this.” in C++.
  * Do prefix interfaces names with "I"
  * Do not prefix enums, classes, or delegates with any letter
  
  ### 1.2 Comment Style
   * Comments should be used to describe intention, algorithmic overview, and/or logical flow.
    It would be ideal, if from reading the comments alone, someone other than the author could
    understand a function's intended behavior and general operation. While there are no minimum 
    comment requirements and certainly some very small routines need no commenting at all, 
    it is hoped that most routines will have comments reflecting the programmer's intent and approach.
    The // (two slashes) style of comment tags should be used in most situations.
    Where ever possible, place comments above the code instead of beside it. Here are some examples:
      ```C#
		// This is required for Controller access for hit detection
		FPSController controller = hit.GetComponent<FPSController>();
 
		// Creare a new ray against the ground
		//
		Ray ray = new Ray(hit.transform.position, -Vector3.up);
      ```	
  
 ## 1.3 Source File Organization
  * Source files should be given the name of the public class in the file
  
  
 ## Some Git rules
 <a name="git-workflow"></a>


### 2.1 Writing good commit messages

Having a good guideline for creating commits and sticking to it makes working with Git and collaborating with others a lot easier. Here are some rules of thumb ([source](https://chris.beams.io/posts/git-commit/#seven-rules)):

 * Separate the subject from the body with a newline between the two.

    _Why:_
    > Git is smart enough to distinguish the first line of your commit message as your summary. In fact, if you try git shortlog, instead of git log, you will see a long list of commit messages, consisting of the id of the commit, and the summary only.

 * Limit the subject line to 50 characters and Wrap the body at 72 characters.

    _why_
    > Commits should be as fine-grained and focused as possible, it is not the place to be verbose. [read more...](https://medium.com/@preslavrachev/what-s-with-the-50-72-rule-8a906f61f09c)

 * Capitalize the subject line.
 * Do not end the subject line with a period.
 * Use [imperative mood](https://en.wikipedia.org/wiki/Imperative_mood) in the subject line.

    _Why:_
    > Rather than writing messages that say what a committer has done. It's better to consider these messages as the instructions for what is going to be done after the commit is applied on the repository. [read more...](https://news.ycombinator.com/item?id=2079612)


 * Use the body to explain **what** and **why** as opposed to **how**.

 <a name="documentation"></a>
  
  
  
