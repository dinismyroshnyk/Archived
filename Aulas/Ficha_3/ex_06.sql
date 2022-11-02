SELECT
    nome AS 'Nome',
    funcao AS 'Função',
    sal AS 'Salário',
    ROUND(sal + (sal * 0.1355)) AS 'Salário com aumento'
FROM emp
WHERE funcao = 'Continuo'
ORDER BY 4
;