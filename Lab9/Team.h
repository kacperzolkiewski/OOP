#pragma once 
#include <set>
#include <algorithm>
#include <iterator>
#include <list>


//Klasa Team opakowująca kontener posortowanych obiektów Member
class Team {
  public:
  // funkcja dodająca element do kontenera
  void add(Member obiect) {m_team.insert(obiect);}

  // funkcja zwracająca nasz kontener.
  const std::set<Member, Comparison>& getTeam() const {return m_team;}

  //Przeładowanie operatora, który zwraca część wspólną dwóch klas Team.
  Team operator-(const Team& other) const {
    Team team1;
    std::set_intersection(m_team.begin(), m_team.end(), other.m_team.begin(), other.m_team.end(), std::inserter(team1.m_team, team1.m_team.begin()));
    return team1;
  }

  //Przeładowanie operatora, który zwraca nowy Team złożony z dwóch dodanych do siebie "Team-ów", ale bez powtarzania elementów.
  Team operator+(const Team& other) const {
    Team team1;
    team1.m_team = m_team;
    team1.m_team.insert(other.m_team.begin(), other.m_team.end());
    return team1;
  }

  //funkcja usuwająca obiekty z kontenera, przyjmuje jako argument funkcję porównującą, który element usunąć.
  template <typename T>
  void kill(T&& fun) {
    std::list<Member> members;
    std::copy(m_team.begin(), m_team.end(), std::back_inserter(members));
    members.erase(std::remove_if(members.begin(), members.end(), fun), members.end());
    m_team.clear();
    m_team = std::set<Member, Comparison>(members.begin(), members.end());
  }

  private:
  //kontener na klasę Member, który do porównania elementów używa Funktora Comparison.
  std::set<Member, Comparison> m_team;
};

std::ostream& operator<<(std::ostream& os, const Team& team) {
  std::copy(team.getTeam().begin(), team.getTeam().end(), std::ostream_iterator<Member>(os, "\n"));
  return os;
}