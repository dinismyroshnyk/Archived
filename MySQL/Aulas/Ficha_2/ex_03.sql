SELECT emp.nome, sal, dep.nome, local
FROM emp, dep
WHERE emp.ndep = dep.ndep
    AND sal < 150000
;