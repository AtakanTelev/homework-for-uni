#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float *assignments = NULL, *quizzes = NULL;
    int assignment_count = 0, quiz_count = 0;
    float assignment_score = 0, quiz_score = 0;
    float assignment_total = 0, quiz_total = 0;
    float midterm_score = 0, final_score = 0;
    float assignment_weight, quiz_weight, midterm_weight, final_weight, total_grade;
    bool valid_input;

    printf("Enter assignment scores (end with -1):\n");
    while (true)
    {
        valid_input = false;
        printf("Assignment %d: ", assignment_count + 1);

        if (scanf("%f", &assignment_score) != 1)
        { // checking for char (str) or nonfloat numbers
            printf("Warning: Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (assignment_score == -1)
            break;
        if (assignment_score < 0 || assignment_score > 100)
        {
            printf("Warning: Invalid score. Please enter a value between 0 and 100.\n");
            continue;
        }
        assignments = realloc(assignments, (assignment_count + 1) * sizeof(float)); // declare a size
        assignments[assignment_count++] = assignment_score;
        assignment_total += assignment_score;
    }
    printf("Enter quiz scores (end with -1):\n");
    while (true)
    {
        valid_input = false;
        printf("Quiz %d: ", quiz_count + 1);

        if (scanf("%f", &quiz_score) != 1)
        {
            printf("Warning: Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (quiz_score == -1)
            break;
        if (quiz_score < 0 || quiz_score > 100)
        {
            printf("Warning: Invalid score. Please enter a value between 0 and 100.\n");
            continue;
        }
        quizzes = realloc(quizzes, (quiz_count + 1) * sizeof(float));
        quizzes[quiz_count++] = quiz_score;
        quiz_total += quiz_score;
    }

    do
    {
        printf("Enter midterm score (0-100): ");
        if (scanf("%f", &midterm_score) != 1)
        {
            printf("Warning: Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (midterm_score < 0 || midterm_score > 100)
            printf("Warning: Invalid score. Please enter a value between 0 and 100.\n");
        else
            valid_input = true;
    } while (!valid_input);
    do
    {
        printf("Enter final exam score (0-100): ");
        if (scanf("%f", &final_score) != 1)
        {
            printf("Warning: Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (final_score < 0 || final_score > 100)
            printf("Warning: Invalid score. Please enter a value between 0 and 100.\n");
        else
            valid_input = true;
    } while (!valid_input);

    assignment_weight = (assignment_total / assignment_count) * 0.1;
    quiz_weight = (quiz_total / quiz_count) * 0.1;
    midterm_weight = midterm_score * 0.2;
    final_weight = final_score * 0.6;

    total_grade = assignment_weight + quiz_weight + midterm_weight + final_weight;

    printf("\n--------------------------------------------------\n");
    printf("| Component       | Weight     | Score    | Total  |\n");
    printf("--------------------------------------------------\n");
    printf("| Assignments     | 10         | %.2f    |  %.2f  |\n", assignment_total / assignment_count, assignment_weight);
    printf("| Quizzes         | 10         | %.2f    |  %.2f  |\n", quiz_total / quiz_count, quiz_weight);
    printf("| Midterm         | 20         | %.2f    | %.2f  |\n", midterm_score, midterm_weight);
    printf("| Final Exam      | 60         | %.2f    | %.2f  |\n", final_score, final_weight);
    printf("--------------------------------------------------\n");
    printf("| Total Grade     |            |          | %.2f  |\n", total_grade);
    printf("--------------------------------------------------\n");

    if (total_grade >= 50)
        printf("Status: Pass\n");
    else
        printf("Status: Fail\n");

    free(assignments); // we are declared a changeable array so we have to delate after.
    free(quizzes);

    return 0;
}