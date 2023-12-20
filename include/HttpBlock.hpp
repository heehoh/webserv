#ifndef HTTPBLOCK_HPP
#define HTTPBLOCK_HPP

#include <iostream>
#include <limits>
#include <map>
#include <vector>

// 문제가 httpblock을 생성자로 다 만들려고 했다
// 근데 httpblock을 만들려면 httpblock안의 checkDirective가 필요
// 1. checkDirective을 다른 클래스로 옮기기
// 1-1. config
// 1-2. 다른 클래스 만들기
// 2. httpblock을 기본값으로 일단 생성 후 setter로 값 바꿔주기
class HttpBlock
{
  protected:
    // root 기본값 html, index index.html, errorpage ""(없음), client_max_body_size = 1m;
    std::string mRoot;
    std::vector<std::string> mIndexs;
    std::vector<std::string> mErrorPages;
    unsigned int mClientMaxBodySize;

  public:
    HttpBlock(std::string root, std::vector<std::string> index, std::vector<std::string> errorpage,
              unsigned int clientMaxBodySize);
    HttpBlock(const HttpBlock &other);
    HttpBlock &operator=(const HttpBlock &rhs);
    // todo : friend 없애야함
    friend std::ostream &operator<<(std::ostream &os, HttpBlock &httpBlock);
};

#endif