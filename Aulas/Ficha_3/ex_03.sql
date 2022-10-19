SELECT
    COUNT(nome) AS 'Empregados sem Prémios'
FROM emp
WHERE premios IS NULL
;