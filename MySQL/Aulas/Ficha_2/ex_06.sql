SELECT e.nome, funcao, d.nome, sal
FROM emp e, dep d, descontos
WHERE e.ndep = d.ndep
    AND sal BETWEEN salinf AND salsup
    AND escalao = 4
ORDER BY e.nome
;