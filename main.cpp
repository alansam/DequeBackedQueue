//  This is free and unencumbered software
//  released into the public domain.
//  @see  LICENSE.md
//  @see  https://unlicense.org

#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <algorithm>

using namespace std::literals::string_literals;

static
constexpr
auto clc_show = [](auto & clc, auto const & tt) {
  std::cout << tt;
  std::for_each(clc.cbegin(), clc.cend(), [](auto const & v_) {
    std::cout << std::setw(3) << v_;
  });
  std::cout << std::endl;
};

static
constexpr
auto q_show = [](auto & q_, auto const & tt) {
  std::cout << tt;
  for (auto e_ { 0ul }; e_ < q_.size(); ++e_) {
    auto emt = std::move(q_.front());
    q_.pop();
    std::cout << std::setw(3) << emt;
    q_.push(std::move(emt));
  }
  std::cout << std::endl;
};

int main(int argc, char const * argv[]) {
  std::cout << "DequeBackedQueue!\n"s;

  auto dq = std::deque<int> { 2, 4, 5, 7, 3, 9, };
  auto qq = std::queue<int, std::deque<int>>(dq);

  std::cout << "presort\n";
  clc_show(dq, "dq: "s);
  q_show(qq, "qq: "s);
  std::cout.put('\n');

  std::cout << "sorted\n"s;
  std::sort(dq.begin(), dq.end());
  clc_show(dq, "dq: "s);
  q_show(qq, "qq: "s);
  std::cout.put('\n');

  while (qq.size() > 0) {
    std::cout << "dq sz = "s << dq.size() << ", "s
              << "qq sz = "s << qq.size() << '\n';
    std::cout << "qq front: "s
              << qq.front()
              << '\n';
    qq.pop();
    std::cout << "dq sz = "s << dq.size() << ", "s
              << "qq sz = "s << qq.size() << '\n';
    clc_show(dq, "dq: "s);
    q_show(qq, "qq: "s);
    std::cout.put('\n');
  }
  std::cout << std::endl;

  return 0;
}
