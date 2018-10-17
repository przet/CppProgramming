#include "IDuck.hpp"
#include "Goose.hpp"

class GooseToDuckAdapter : public IDuck {
        private:
                Goose* m_goose;
        public:
                GooseToDuckAdapter(Goose* goose) : m_goose(goose){}
                std::string Quack() override {
                        return m_goose->Honk();
                }
};

