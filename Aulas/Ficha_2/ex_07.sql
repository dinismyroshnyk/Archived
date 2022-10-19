SELECT e.nome, funcao, sal, local
FROM emp e, dep d
WHERE e.ndep = d.ndep
    AND sal > 150000
    AND local = 'Coimbra'
;