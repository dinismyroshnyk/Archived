SELECT
    enc.nemp AS 'Número do Encarregado',
    enc.data_entrada AS 'Data de Entrada',
    fun.nemp AS 'Número do Funcionário',
    fun.data_entrada AS 'Data de Entrada',
    ABS(DATEDIFF(fun.data_entrada, enc.data_entrada)) AS 'Diferença de Dias'
FROM emp enc, emp fun
WHERE fun.encar = enc.nemp
    AND ABS(DATEDIFF(fun.data_entrada, enc.data_entrada)) >= 1000
ORDER BY 5
;