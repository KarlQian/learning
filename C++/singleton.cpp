    #include "singleton.hpp"
    namespace cc{
    SingleTon* SingleTon::m_pInstance = nullptr;
    std::mutex SingleTon::m_mutex;
    SingleTon* SingleTon::getinstance(){
        if (nullptr==m_pInstance){
            std::lock_guard<std::mutex> guard(m_mutex);
            if (nullptr == m_pInstance){
                m_pInstance = new SingleTon();
            }
        }
        return m_pInstance;
    }
    void SingleTon::destoryInstance(){
        if (m_pInstance!= nullptr){
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }
    
    Single2 Single2::m_Instance;
    Single2 & Single2::getInstance(){
        return m_Instance;
    }

    }