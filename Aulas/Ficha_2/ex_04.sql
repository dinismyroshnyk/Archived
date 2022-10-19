SELECT DISTINCT funcao, escalao
FROM emp,descontos
WHERE sal BETWEEN salinf AND salsup
ORDER BY escalao
;