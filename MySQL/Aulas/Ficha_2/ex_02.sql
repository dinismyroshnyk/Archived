SELECT emp.nome, sal, dep.ndep, dep.nome
FROM emp, dep
WHERE dep.ndep = emp.ndep
    AND emp.nome LIKE 'A%R%'
;