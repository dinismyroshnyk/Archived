SELECT
    funcao AS "Função",
    ROUND(AVG(sal)) AS "Salário Médio"
FROM emp
GROUP BY funcao
HAVING COUNT(*) > 1
ORDER BY 2
;