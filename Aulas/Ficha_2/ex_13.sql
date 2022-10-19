SELECT enc.nome AS 'Encarregado', emp.nome AS 'Empregado'
FROM emp enc, emp
WHERE emp.encar = enc.nemp
ORDER BY enc.nome, emp.nome
;