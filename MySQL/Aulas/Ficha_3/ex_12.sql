SELECT
    ndep AS 'Número do Departamento',
    (MAX(sal) - MIN(sal)) AS 'Diferença de Salários'
FROM emp
GROUP BY ndep
;