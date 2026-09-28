#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <string>

class Participant
{
public:
    Participant(std::string name, double score);
    std::string name() const noexcept;
    double score() const noexcept;
    bool operator<(const Participant &rhs) const noexcept;
    bool operator>(const Participant &rhs) const noexcept;
    bool operator<=(const Participant &rhs) const noexcept;
    bool operator>=(const Participant &rhs) const noexcept;

private:
    std::string m_name;
    double m_score;
};

#endif // PARTICIPANT_HPP
