SELECT
    ndep AS 'NDEP',
    funcao AS 'FUNCAO',
    MAX(sal) AS 'SAL_MAX',
    MIN(sal) AS 'SAL_MIN',
    ROUND(AVG(sal)) AS 'SAL_MED',
    COUNT(*) AS 'QUANTOS'
FROM emp
WHERE nome != 'Jorge Sampaio'
GROUP BY ndep, funcao
HAVING MAX(sal) > 200000
ORDER BY 1, 3
;