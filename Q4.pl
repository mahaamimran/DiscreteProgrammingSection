% By declaring task/2 as dynamic the program can modify the completion status of tasks at runtime
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

% Entry point for the program
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