SELECT
    YEAR(data_entrada) AS 'Ano de Entrada',
    COUNT(*) AS 'Nr. de Empregados'
FROM emp
GROUP BY 1
ORDER BY 1
;