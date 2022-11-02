SELECT
    nemp AS 'Número do Empregado',
    nome AS 'Nome',
    data_entrada AS 'Data de Entrada',
    DATEDIFF(SYSDATE(), data_entrada) AS 'Diferença de Dias'
FROM emp
WHERE DATEDIFF(DATE_ADD(SYSDATE(), INTERVAL 1 YEAR), data_entrada)  > (35 + 5) * 365
;