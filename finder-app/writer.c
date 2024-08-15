#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

void write_to_file(const char* writefile, const char* writestr) {
    FILE* file = fopen(writefile, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the provided string to the file
    fprintf(file, "%s", writestr);
    fclose(file);

    // Log the action using syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);
    closelog();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        exit(1);
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];

    write_to_file(writefile, writestr);

    return 0;
}
