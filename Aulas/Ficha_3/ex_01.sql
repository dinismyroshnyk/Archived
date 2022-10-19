SELECT
    UPPER(e.nome) AS 'Nome',
    LOWER(e.funcao) AS 'Função',
    CONCAT(UPPER(SUBSTR(d.nome, 1, 1)), LOWER(SUBSTR(d.nome, 2))) AS 'Departamento'
FROM emp e, dep d
WHERE e.ndep = d.ndep
    AND e.funcao = 'Vendedor'
    ORDER BY e.nome
;