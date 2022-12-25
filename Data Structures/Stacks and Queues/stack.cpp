//
// Created by plcla on 5/4/2022.
//

#include "stack.h"

bool Stack::validatePair(char &charInStack, char &charInList) {
    if (charInStack == '(' && charInList == ')')
        return true;
    else if (charInStack == '{' && charInList == '}')
        return true;
    else if (charInStack == '[' && charInList == ']')
        return true;

    return false;
}

bool Stack::isValid(std::string& s) {
    std::stack<char> newStack;

    for (auto& it : s) {
        if (it == '(' || it == '{' || it == '[')
            newStack.push(it);
        else if (!newStack.empty() && validatePair(newStack.top(), it))
            newStack.pop();
        else
            return false;
    }

    if (newStack.empty())
        return true;
    return false;
}

int32_t Stack::calPoints(std::vector<std::string> &ops) {
    std::stack<int32_t> newStack;

    for (auto& it : ops) {
        if (it == "D") {
            if (!newStack.empty())
                newStack.push(newStack.top() * 2);
            else
                continue;
        }
        else if (it == "C") {
            if (!newStack.empty())
                newStack.pop();
            else
                continue;
        }
        else if (it == "+") {
            if (newStack.size() >= 2) {
                int32_t pushFirst, pushSecond;
                pushSecond = newStack.top();
                newStack.pop();
                pushFirst = newStack.top();
                newStack.pop();

                int32_t sum = pushFirst + pushSecond;
                newStack.push(pushFirst);
                newStack.push(pushSecond);
                newStack.push(sum);
            }
            else
                continue;
        }
        else {
            newStack.push(std::stoi(it, nullptr, 10));
        }
    }

    int32_t sum = 0;
    while (!newStack.empty()) {
        sum += newStack.top();
        newStack.pop();
    }
    return sum;
}

bool Stack::backspaceCompare(std::string& s, std::string& t) {
    std::stack<char> stackStringS;
    std::stack<char> stackStringT;

    while (!s.empty()) {
        if (s[0] == '#' && !stackStringS.empty())
            stackStringS.pop();
        else if (s[0] != '#')
            stackStringS.push(s[0]);
        s.erase(s.begin());
    }

    while (!t.empty()) {
        if (t[0] == '#' && !stackStringT.empty())
            stackStringT.pop();
        else if (t[0] != '#')
            stackStringT.push(t[0]);
        t.erase(t.begin());
    }

    if (stackStringS.size() == stackStringT.size()) {
        while (!stackStringS.empty()) {
            if (stackStringS.top() != stackStringT.top())
                return false;
            stackStringS.pop();
            stackStringT.pop();
        }
        return true;
    }
    return false;
}

void Stack::reverseString(std::string& stringReference) {
    std::string copy = stringReference;
    for (int i = 0; i < copy.length(); i++)
        stringReference[i] = copy[copy.length() - i - 1];
}

std::string Stack::stringify(std::stack<char>& st) {
    if (st.size() <= 2) {
        while (!st.empty())
            st.pop();
        return "";
    }

    std::string decomposition;
    while (!st.empty()) {
        decomposition += st.top();
        st.pop();
        if (st.size() == 1)
            st.pop();
    }

    return decomposition;
}

std::string Stack::removeOuterParenthesis(std::string& s) {
    std::stack<char> newStack;
    std::string tempString, resString;
    int32_t numOfOpenParenthesis = 0;
    bool countFlag = false;

    for (auto& it : s) {
        if (it == '(') {
            numOfOpenParenthesis++;
        }
        else if (it == ')') {
            countFlag = true;
            numOfOpenParenthesis--;
        }

        if (countFlag && !numOfOpenParenthesis) {
            tempString = stringify(newStack);
            reverseString(tempString);
            resString += tempString;
            tempString = "";
            countFlag = false;
            continue;
        }

        newStack.push(it);
    }

    return resString;
}

std::string Stack::getPath(std::stack<std::string> &st) {
    std::string path;

    while (!st.empty()) {
        path += st.top();
        st.pop();
    }

    return path;
}

std::string Stack::reversePath(std::string refString) {
    std::string reversed = "/";

    for (int32_t i = refString.length() - 1; i >= 0; i--) {
        if (refString[i] == '/') {
            for (int32_t j = i + 1; refString[j] != '/' && j < refString.length(); j++) {
                reversed += refString[j];
            }
            reversed += '/';
        }
    }

    return reversed;
}

const std::string DOUBLESLASH = "//";
const std::string ONEUP = "/../";
const std::string SINGLEPERIOD = "/./";
bool Stack::isValidPath(std::string refString) {
    refString += '/';

    if (refString == DOUBLESLASH || refString == ONEUP || refString == SINGLEPERIOD) {
        return false;
    }

    return true;
}

std::string Stack::simplifyPath(std::string& path) {
    std::stack<std::string> newStack;
    std::string templateString = "/", resString;

    for (auto it = path.begin() + 1; it != path.end(); it++) {
        if (*it == '/') {
            if (!isValidPath(templateString)) {
                templateString += '/';
                if (!newStack.empty() && templateString == ONEUP)
                    newStack.pop();
            } else
                newStack.push(templateString);

            templateString = "/";
            continue;
        }
        templateString += *it;
    }
    if (!isValidPath(templateString)) {
        templateString += '/';
        if (!newStack.empty() && templateString == ONEUP)
            newStack.pop();
    } else
        newStack.push(templateString);


    resString = reversePath(getPath(newStack));

    if (resString[resString.length() - 1] == '/')
        resString.erase(resString.begin() + resString.length() - 1);
    if (resString.empty())
        resString = "/";
    return resString;
}
