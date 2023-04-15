% Define dynamic predicates for tasks and their completion status
:- dynamic task/2.

% Initialize tasks
task(work, false).
task(study, false).
task(exercise, false).

% Rule to mark a task as completed
complete_task(Task) :-
    retract(task(Task, _)),
    assert(task(Task, true)).

% Rule to check if a task is completed
task_completed(Task) :-
    task(Task, true).

% Rule to check if a task is not completed
task_not_completed(Task) :-
    task(Task, false).

% Rule to display tasks and their completion status
display_tasks :-
    write('Task\t\tCompletion Status'), nl,
    write('-----------------------------------'), nl,
    task(Task, Completion),
    write(Task), write('\t\t'),
    (Completion = true -> write('Completed') ; write('Not Completed')),
    nl,
    fail.
display_tasks.

% Rule to add a new task
add_task(Task) :-
    \+ task(Task, _), % Check if task doesn't already exist
    assert(task(Task, false)),
    write('Task added: '), write(Task), nl.

% Entry point for the program
start :-
    write('Welcome to Task Tracker!'), nl,
    write('Available commands:'), nl,
    write('add_task(Task). - Add a new task'), nl,
    write('complete_task(Task). - Mark a task as completed'), nl,
    write('task_completed(Task). - Check if a task is completed'), nl,
    write('task_not_completed(Task). - Check if a task is not completed'), nl,
    write('display_tasks. - Display all tasks and their completion status'), nl,
    write('Type "halt." to exit.'), nl.

% Start the program
:- start.