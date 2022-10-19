SELECT enc.nome AS 'Insatisfeito'
FROM emp fun, emp enc
WHERE enc.nemp = fun.encar
    AND fun.sal > enc.sal
;