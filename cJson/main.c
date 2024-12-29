#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Test_Parse_Command()
{
    const char *json_msg = "{\"command\":\"ENA\",\"nodeID\":129,\"data\":null}";
    cJSON *root = cJSON_Parse(json_msg);

    if (!root)
    {
        printf("JSON Parse Error: %s\n", cJSON_GetErrorPtr());
        return;
    }

    cJSON *nodeID = cJSON_GetObjectItem(root, "nodeID");
    if (nodeID && cJSON_IsNumber(nodeID))
    {
        printf("Parsed nodeID: %d\n", nodeID->valueint);
    }
    else
    {
        printf("nodeID not found or not a number\n");
    }

    cJSON_Delete(root);
}

void Parse_Command(const char *json_msg)
{
    cJSON *root = cJSON_Parse(json_msg);
    if (!root)
    {
        printf("Error: JSON Parse Failed\r\n");
        return;
    }

    cJSON *command = cJSON_GetObjectItemCaseSensitive(root, "command");
    cJSON *nodeID = cJSON_GetObjectItemCaseSensitive(root, "nodeID");
    cJSON *data = cJSON_GetObjectItemCaseSensitive(root, "data");

    if (cJSON_IsString(command) && cJSON_IsNumber(nodeID))
    {
        printf("Command: %s, nodeID: %d\r\n", command->valuestring, nodeID->valueint);
    }

    cJSON_Delete(root);
}

void Load_Test_Cases(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Cannot open file %s\r\n", filename);
        return;
    }

    // Read file content into buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer)
    {
        printf("Error: Memory allocation failed\r\n");
        fclose(file);
        return;
    }
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Ensure null termination
    fclose(file);

    // Parse JSON content
    cJSON *testCases = cJSON_Parse(buffer);
    free(buffer); // Free the file buffer

    if (!testCases)
    {
        printf("Error: JSON Parse Failed\r\n");
        return;
    }

    // Process each test case
    cJSON *testCase;
    cJSON_ArrayForEach(testCase, testCases)
    {
        char *jsonString = cJSON_Print(testCase);
        printf("Processing Test Case: %s\r\n", jsonString);
        free(jsonString);

        // Pass test case JSON string to the command parser
        Parse_Command(cJSON_Print(testCase));
    }

    cJSON_Delete(testCases);
}

int htoi(char *hex)
{
    int value = 0;
    int digit = 0;
    int count = 0;
    int i = strlen(hex) - 1;

    while (i >= 2)
    {
        switch (hex[i])
        {
        case 'A':
            digit = 10;
            break;
        case 'B':
            digit = 11;
            break;
        case 'C':
            digit = 12;
            break;
        case 'D':
            digit = 13;
            break;
        case 'E':
            digit = 14;
            break;
        case 'F':
            digit = 15;
            break;
        default:
            digit = hex[i] - 0x30;
        }

        // obtaining the decimal number
        value = value + (digit)*pow((double)16, (double)count);
        count++;
        i--;
    }
    return value;
}

void itoh(int decimal, char hex[])
{
    int temp = 0;
    int i = 0;
    while (decimal != 0)
    {
        temp = decimal % 16;

        // converting decimal number
        // in to a hexa decimal
        // number
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hex[i++] = temp;
        decimal = decimal / 16;
    }
    hex[i] = '\0';
}

int main()
{
    // Test_Parse_Command();
    char jsonBuffer[50];
    const char *my_json = "{\"command\":\"ENA\",\"nodeID\":129,\"data\":null}";

    Load_Test_Cases("commands.json");

    int a = htoi("0x81");
    printf("%d -> ", a);
    char hex[10];
    itoh(129, hex);
    printf("%s\n", hex);
}