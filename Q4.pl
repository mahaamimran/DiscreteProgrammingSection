% Maham Imran 22i-2733
% friendly reminder for Maham: you can use the following command to run the program
% swipl -s Q4.pl -g start -t halt
% or in terminal, cd dir, swipl, ['Q4.pl'].


% declaring task/2 as dynamic means the program can modify status @ runtime
% the 2 represents that it takes 2 arguments, the task name and the completion status
:- dynamic task/2.

% Initializing
task(work,false).
task(study,false).
task(exercise,false).
task(sleep,false).
task(eat,false).

% Rule 1
complete_task(X):-
    % removing the old task first
    retract(task(X,_)),
    % adding the new task
    assert(task(X,true)).

% Rule 2
task_completed(Y):-
    task(Y,true).

% Rule 3
display:-
    write('Task\t\tCompled/Not Completed'), nl,
    write('-----------------------------------'), nl,
    task(Task, Completion),
    write(Task), write('\t\t'),
    (Completion = true -> write('Completed') ; write('Not Completed')),nl,
    fail.
display.

% Rule 4
add_task(Z) :-
    \+ task(Z,_), % Check if task doesn't already exist
    assert(task(Z, false)),
    write('Task added: '), write(Z), nl.

% the main 
start :-
    write('Welcome!'), nl,
    write('What action would you like to perform?'), nl,
    write('Adding a new task:\t\tadd_task(X).'), nl,
    write('Mark task as completed:\t\tcomplete_task(Y).'), nl,
    write('Check status of task:\t\ttask_completed(Z).'), nl,
    write('Display tasks & status:\t\tdisplay.'), nl,
    write('Enter "halt." to exit.'), nl.
% Start the program
:- start.