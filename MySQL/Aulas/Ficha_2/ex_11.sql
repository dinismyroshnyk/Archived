SELECT nemp, e.nome, escalao, d.nome, local, sal, premios
FROM emp e, dep d, descontos
WHERE e.ndep = d.ndep
    AND sal BETWEEN  salinf AND salsup
    AND sal > 100000
    AND d.ndep IN (10, 30)
    AND local LIKE 'C%'
    AND premios IS NOT NULL
    AND premios < sal*14*0.03
    AND escalao IN (1, 2, 3)
    AND encar IS NOT NULL
;