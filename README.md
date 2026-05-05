# SYSTEM LOG ANALYZER

## DESCRIPTION

A CLI tool written in C++ that analyzes log files and reports the number of ERROR, WARNING and INFO entries.

## FEATURES

- List available log files 
- Analyze a specific log file
- Analyze all log files
- Help command
- Exit command 
- Basic error handling

## HOW TO COMPILE AND RUN
To compile, do:

`g++ main.cpp logAnalyzer.cpp -o -std=c++17 logAnalyzer`

then do:\
`./logAnalyzer`

to run the program.

## COMMANDS
`show logs`\
`show all`\
`show sample.log`\
`help`\
`exit`


## PROJECT STRUCTURE
.
├── data\
│   ├── sample.log\
│   └── sample2.log\
├── src\
│   ├── main.cpp\
│   └── logAnalyzer.cpp\
├── logAnalyzer\       # Executable (generated after compilation)
├── README.md\
└── .gitignore\

## POTENTIAL IMPROVEMENTS

- Track the most frequent errors
- Improve command parsing (done)
- Generation of output report files.