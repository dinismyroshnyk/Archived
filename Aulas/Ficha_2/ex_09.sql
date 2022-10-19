SELECT e.nome, funcao, escalao, d.nome
FROM emp e, dep d, descontos
WHERE d.ndep = e.ndep
    AND sal BETWEEN salinf AND salsup
    AND NOT funcao = 'Continuo'
ORDER BY escalao DESC
;