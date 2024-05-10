SELECT
    nemp AS 'Número de Empregado',
    nome AS 'Nome',
    data_entrada AS 'Data',
    DATEDIFF(SYSDATE(), data_entrada) AS 'Diferença de Dias',
    IF(DATEDIFF(SYSDATE(), data_entrada) > 365 * (30 + 7), 'Platina',
        IF(DATEDIFF(SYSDATE(), data_entrada) > 365 * (25 + 7), 'Ouro',
            IF(DATEDIFF(SYSDATE(), data_entrada) > 365 * (20 + 7), 'Prata',
                IF(DATEDIFF(SYSDATE(), data_entrada) > 365 * (15 + 7), 'Bronze', 'Sem Prémio')))) AS 'Prémio'
FROM emp
ORDER BY 4
;