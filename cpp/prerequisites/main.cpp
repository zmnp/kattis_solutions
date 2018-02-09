#include <iostream>
#include <unordered_set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool meet_req;  /* does it meet the degree requirements */
  int i, j;       /* indices */
  int k;          /* the number of courses that were chosen, [1, 100] */
  int m;          /* number of categories, [0, 100] */
  int course_num; /* 4 digit course number */
  int c;          /* number of courses in the category, [1, 100] */
  int r;          /* minimum number of courses from the category
                   * that must be taken, [0, c] */

  while (1) {
    /* read  the number of courses that has been chosen */
    std::cin >> k;
    if (k == 0) { /* end of input */
      break;
    }
    /* read the number of categories */
    std::cin >> m;

    std::unordered_set<int> chosen_courses;
    chosen_courses.reserve(k);
    /* read and save to the set k 4-digit integers;
     * each is the number of a course selected */
    for (i = 0; i < k; ++i) {
      std::cin >> course_num;
      chosen_courses.insert(course_num);
    }

    meet_req = true;
    /* read m lines which represent each category */
    for (j = 0; j < m; ++j) {

      /* read the number of courses in the category (c variable) and
       * the minimum number of courses from the category
       * that must be taken (r variable) */
      std::cin >> c >> r;

      int courses_taken = 0; /* number of courses that was taken
                              * for the current category */

      /* read the c course numbers in the current category */
      for (i = 0; i < c; ++i) {
        std::cin >> course_num;
        if (meet_req) {
          if (chosen_courses.count(course_num)) {
            ++courses_taken;
          }
        }
      }
      if (meet_req && courses_taken < r) {
        meet_req = false;
      }
    }
    if (meet_req) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}
