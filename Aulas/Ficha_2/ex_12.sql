SELECT e.nome, funcao, d.nome
FROM dep d
LEFT JOIN emp e ON d.ndep = e.ndep
ORDER BY d.nome, e.nome
;