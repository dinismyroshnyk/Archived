SELECT
    COUNT(nome) AS 'Total de Empregados',
    AVG(sal) AS 'Salário médio mensal',
    SUM(sal*14 + IFNULL(premios, 0)) AS 'Remuneração total anual'
FROM emp
;