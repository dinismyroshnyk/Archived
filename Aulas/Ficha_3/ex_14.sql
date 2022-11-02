SELECT
    funcao AS "Função",
    COUNT(*) AS "Quantidade"
FROM emp
WHERE funcao LIKE '%o'
    OR funcao = 'Analista'
GROUP BY funcao
ORDER BY funcao
;