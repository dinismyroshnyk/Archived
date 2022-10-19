SELECT nome, funcao
FROM emp
WHERE nome LIKE '%v%'
   OR  nome LIKE '%u%'
;