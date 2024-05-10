SELECT ndep, nome, local
FROM dep
    MINUS
SELECT d.ndep, d.nome, local
FROM emp e, dep d
WHERE d.ndep = e.ndep
;