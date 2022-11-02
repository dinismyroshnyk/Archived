SELECT
    funcao AS "Função",
    SUM(sal) AS "Somatório dos salários",
    COUNT(*) AS "Nr. de funcionários"
FROM emp
WHERE funcao != 'Presidente'
GROUP BY funcao
HAVING SUM(sal) >= 1000000
;