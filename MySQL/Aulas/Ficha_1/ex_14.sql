SELECT nemp, nome, ndep, sal, premios
FROM emp
WHERE sal > 100000
    AND ndep IN (10, 30)
    AND premios < sal*14*0.03
    AND encar IS NOT NULL
    AND premios IS NOT NULL
;