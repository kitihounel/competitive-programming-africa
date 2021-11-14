from collections import namedtuple
from itertools import product
from operator import itemgetter

Idea = namedtuple("Idea", ["id", "a", "b"])
Statement = namedtuple("Statement", ["id", "y"])
Problem = namedtuple("Problem", ["idea_id", "statement_id", "difficulty"])

N = int(input())
ideas = []
for i in range(N):
    a, b = (int(token) for token in input().split(maxsplit=1))
    ideas.append(Idea(i, a, b))
statements = [Statement(i, int(token)) for i, token in enumerate(input().split())]

problems = []
for idea, st in product(ideas, statements):
    p = Problem(idea.id, st.id, idea.a ** 2 + idea.b ** 2 - idea.a * idea.b * st.y)
    problems.append(p)
problems.sort(key=itemgetter(2))

used_ideas = set()
used_statements = set()
m = 0
for p in problems:
    if p.idea_id not in used_ideas and p.statement_id not in used_statements:
        m += p.difficulty
        used_ideas.add(p.idea_id)
        used_statements.add(p.statement_id)
print(m)
