//
// Created by adygha on 10/31/17.
//

//Предположим, что наша программа состоит из файлов header.hpp,
//file1.cpp, file2.cpp и file3.cpp. При этом файл header.hpp включается во все .cpp файлы.
//Внутри header.hpp мы написали следующий код.
//Указание: для прохождения теста будет полезно вспомнить,
//что означают ключевые слова static (тут) и inline (тут).

//Отметьте правильные утверждения.
//Замечание: ﻿давайте предполагать, что inline функция не будет встроена компилятором.

namespace
{
    struct Test
    {
        std::string data;
    };

    inline void foo() { ... }

    static void bar() { ... }

   void foobar() { ... }
}

+В каждой единице трансляции будет свой собственный класс Test.
+После компиляции в программе будет три различные функции foo.
 Функция foo определена как inline, и поэтому после компиляции останется только одна такая функция.
 Функция foobar не является ни inline, ни static, поэтому её нельзя определять в заголовочном файле,
 иначе мы получим ошибку линковки.
+Функцию foobar можно определить в заголовочном файле, т.к. она определена в безымянном пространстве имён.
 Функция bar определена как static, и поэтому её нельзя определять в заголовочном файле.
 Указатель на статическую функцию bar нельзя передать из одной единицы трансляции в другую.
+В результате компиляции в каждой единице трансляции будут свои функции foo, bar и foobar.