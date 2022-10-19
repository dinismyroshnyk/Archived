SELECT nemp, sal, premios, premios/12 AS 'Prémio Mensal'
FROM emp
WHERE premios IS NOT NULL
    AND premios/12 BETWEEN sal*0.01 AND sal*0.05
ORDER BY 4 DESC
;