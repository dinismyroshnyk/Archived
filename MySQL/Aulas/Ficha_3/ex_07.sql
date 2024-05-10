SELECT
    nemp AS 'Num. Empregado',
    nome AS 'Nome',
    YEAR(data_entrada) AS 'Ano',
    MONTH(data_entrada) AS 'Mês',
    DAY(data_entrada) AS 'Dia',
    DAYNAME(data_entrada) AS 'Dia da semana'
FROM emp
WHERE YEAR(data_entrada) > 1985
ORDER BY 3, 4, 5
;