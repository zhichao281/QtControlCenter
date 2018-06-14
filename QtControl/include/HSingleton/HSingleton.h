/*
 * Author   : JJHuang
 * Version  : 1.0
 * DateTime : 2017-06-09
 * Describe : 单实例模板
 */

#pragma once

#include <QMutex>

template<typename T>
class HSingletonTemplate
{
public:
    HSingletonTemplate(){}
    ~HSingletonTemplate(){}

    static T& get()
    {
        static T instance;
        return instance;
    }
};

template<typename T>
class HSingletonTemplatePtr
{
public:
    HSingletonTemplatePtr(){}
    ~HSingletonTemplatePtr(){}

    static T* get()
    {
        if (!m_instance)
        {
            static QMutex mtx;
            mtx.lock();
            m_instance = new T;
            mtx.unlock();
        }
        return m_instance;
    }

private:
    static T *m_instance;

};

template<class T>
T* HSingletonTemplatePtr<T>::m_instance = nullptr;

//#define gblXXXGet HSingletonTemplatePtr<XXX>::get()

