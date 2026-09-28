#include <algorithm>
#include <cctype>
#include <optional>
#include <print>
#include <string>
#include <vector>

#include "input.hpp"
#include "participant.hpp"

void print(const std::vector<Participant> &participants);
int partition(std::vector<Participant> &participants, int low, int high);
void sort(std::vector<Participant> &participants, int low, int high);
std::optional<Participant> search(const std::vector<Participant> &participants,
                                  const std::string &name, int index = 0);
double sum(double score1, double score2);
double sum(const std::vector<Participant> &participants, int index = 0);
double average(const std::vector<Participant> &participants);

int main()
{
    std::vector<Participant> participants {
        {"Brayan", 20},
        {"Eugenio Rafael", 50},
        {"Stephanye", 95},
        {"Nieves", 75},
        {"Marco", 10}
    };

    std::println("Participantes sin ordenar:\n");
    print(participants);

    sort(participants, 0, participants.size() - 1);

    std::println(
        "\nParticipantes ordenados por calificación del mayor al menor:\n");
    print(participants);
    std::println();

    auto name = Input::input("Buscar participante por nombre");

    std::ranges::transform(name, name.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });

    auto participant = search(participants, name);

    if (participant)
        std::println("{} tiene una nota de {}.", participant->name(),
                     participant->score());
    else
        std::println(stderr, "No se encontró el participante {}.", name);

    std::println("\nEl promedio de las calificaciones es: {}.\n",
                 average(participants));
}

void print(const std::vector<Participant> &participants)
{
    for (const auto &participant : participants) {
        std::println("Nombre: {}, Calificación: {}", participant.name(),
                     participant.score());
    }
}

int partition(std::vector<Participant> &participants, int low, int high)
{
    auto pivot = participants[high];

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        // La asignación pide que se ordene del mayor al menor.
        if (participants[j] >= pivot) {
            ++i;
            std::swap(participants[i], participants[j]);
        }
    }

    std::swap(participants[i + 1], participants[high]);

    return i + 1;
}

void sort(std::vector<Participant> &participants, int low, int high)
{
    if (low < high) {
        int index = partition(participants, low, high);
        sort(participants, low, index - 1);
        sort(participants, index + 1, high);
    }
}

std::optional<Participant> search(const std::vector<Participant> &participants,
                                  const std::string &name, int index)
{
    if (participants.empty() || index >= participants.size())
        return std::nullopt;

    auto pname = participants[index].name();

    // We're obviouly trusting that name comes in lowercase.
    // Can be improved, yeah.
    std::ranges::transform(pname, pname.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });

    if (pname == name)
        return participants[index];

    return search(participants, name, (index + 1));
}

double sum(double score1, double score2)
{
    return score1 + score2;
}

double sum(const std::vector<Participant> &participants, int index)
{
    if (index == participants.size())
        return 0;
    else if ((index + 1) == participants.size())
        return participants[index].score();

    double s = participants[index].score() + participants[index + 1].score();
    return s + sum(participants, index + 2);
}

double average(const std::vector<Participant> &participants)
{
    if (participants.empty())
        return 0.0;

    return sum(participants, 0) / participants.size();
}
