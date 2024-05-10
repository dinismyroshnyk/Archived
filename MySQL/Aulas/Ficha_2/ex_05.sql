SELECT nome, funcao, sal
FROM emp, descontos
WHERE sal BETWEEN salinf AND salsup
    AND escalao = 4
ORDER BY nome
;