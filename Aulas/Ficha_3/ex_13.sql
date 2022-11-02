SELECT
    funcao AS "Função",
    COUNT(*) AS "Quantidade"
FROM emp
GROUP BY funcao
ORDER BY funcao
;