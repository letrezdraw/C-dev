
#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 20

int page_frames[MAX_FRAMES];
int page_faults = 0;

void initialize_page_frames(int n) {
    for (int i = 0; i < n; i++) {
        page_frames[i] = -1;
    }
}

int is_page_in_memory(int page, int n) {
    for (int i = 0; i < n; i++) {
        if (page_frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void replace_page(int new_page, int n) {
    int replace_index = rand() % n;  // Randomly replace a page
    page_frames[replace_index] = new_page;
    printf("Page %d replaced with %d\n", page_frames[replace_index], new_page);
}

void simulate_demand_paging(int reference_string[], int n, int num_pages) {
    for (int i = 0; i < num_pages; i++) {
        int current_page = reference_string[i];
        if (!is_page_in_memory(current_page, n)) {
            page_faults++;
            printf("Page fault occurred for page %d\n", current_page);
            replace_page(current_page, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    int reference_string[MAX_PAGES] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 12, 1, 19, 8};
    int num_pages = sizeof(reference_string) / sizeof(reference_string[0]);

    initialize_page_frames(n);
    simulate_demand_paging(reference_string, n, num_pages);

    printf("Total number of page faults: %d\n", page_faults);
    return 0;
}
