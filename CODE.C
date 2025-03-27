#include <stdio.h>
#include <string.h>

void chatbot_response(char input[]) {
    // Convert input to lowercase for case insensitivity
    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
    }

    // Check for common phrases
    if (strstr(input, "hello") || strstr(input, "hi")) {
        printf("Chatbot: Hello! How can I help you today?\n");
    } else if (strstr(input, "how are you")) {
        printf("Chatbot: I'm just a bot, but I'm doing great! How about you?\n");
    } else if (strstr(input, "your name")) {
        printf("Chatbot: I'm a simple chatbot created in C.\n");
    } else if (strstr(input, "bye")) {
        printf("Chatbot: Goodbye! Have a great day!\n");
    } else {
        printf("Chatbot: Sorry, I don't understand that. Can you rephrase?\n");
    }
}

int main()
{
    char input[100];

    printf("Chatbot: Hello! Type your message (type 'bye' to exit).\n");

    while (1)
{
        printf("You: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Exit if the user types "bye"
        if (strstr(input, "bye"))
{
            chatbot_response(input);
            break;
        }

        chatbot_response(input);
    }

    return 0;
}
