SELECT e.nome, nemp, sal, d.nome, escalao
FROM emp e, dep d, descontos
WHERE e.ndep = d.ndep
    AND sal BETWEEN  salinf AND  salsup
    AND sal BETWEEN  100000 AND 200000
ORDER BY escalao, d.ndep, e.nome
;