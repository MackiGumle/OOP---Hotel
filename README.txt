Projekt na téma Hotel
1. Program obsahuje 7 tříd:
1.	Info - čistě abstraktní
2.	Person
3.	Employee
4.	Manager
5.	Guest
6.	Room
7.	Hotel

2. Kód představuje implementaci základů hotelového informačního systému 
Třída Person a Employee jsou abstraktní třídy, z nichž každá obsahuje pouze několik základních metod, např. pro získání jména nebo mzdy. Třída Manager dědí z tříd Person a Employee a přidává vlastní atributy (oddělení) a metody (zobrazení informací).

Třída Guest dědí z třídy Person a má vlastní atributy (přístup k sauně) a metody (zobrazení informací a počet instancí).

Třída Room má atributy (číslo pokoje, cena, seznam hostů) a metody (přidání a odebrání hosta, získání počtu hostů a informací o pokoji).

Třída Hotel má atributy (název, seznam pokojů, hodnocení) a metody (zobrazení informací, přidání pokoje, změna hodnocení).

Hlavní funkce main vytváří několik pokojů a hotelů, přidává hosty do pokojů, odstraňuje hosty a nakonec dealokuje všechny dynamicky vytvořené objekty.

3. Třídy Hotel a Room mají implementováno dynamické pole ukazatelů na objekty jiné třídy.
Třída Room má také metody pro přidání a mazání prvků pole (včetně přeskládání prázdného místa).
4. Třída Manager a Guest má přetížené konstruktory.
5. Třída Guest má třídní proměnnou (static), která udržuje počet instancí třídy, včetně implementace do konstruktoru a destruktoru.
6. Třída Manager dědí z tříd Person a Employee.
7. Třída Person využívá pozdní vazbu.
8. Tento dokument slouží jako dokumentace.
9. Třída Employee využívá protected atribut.
10. Třída Info je ryze abstraktní třída.
11. Třída Room využívá polymorfismus, obsahuje totiž atribut guests, který má datový typ Person* a ukládá do něj třídy Guest a Manager
