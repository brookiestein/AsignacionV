#include "participant.hpp"

Participant::Participant(std::string name, double score)
    : m_name(name)
    , m_score(score)
{
}

std::string Participant::name() const noexcept
{
    return m_name;
}

double Participant::score() const noexcept
{
    return m_score;
}

// La asignación pide que se ordene en base a la calificación.
bool Participant::operator<(const Participant &rhs) const noexcept
{
    return m_score < rhs.m_score;
}

bool Participant::operator>(const Participant &rhs) const noexcept
{
    return !(*this < rhs);
}

bool Participant::operator<=(const Participant &rhs) const noexcept
{
    return (*this < rhs) || (m_score == rhs.m_score);
}

bool Participant::operator>=(const Participant &rhs) const noexcept
{
    return (*this > rhs) || (m_score == rhs.m_score);
}
