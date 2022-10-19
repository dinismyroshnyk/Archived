SELECT emp.nome, funcao, dep.nome
FROM emp, dep
WHERE emp.ndep = dep.ndep
ORDER BY dep.nome, emp.nome
;