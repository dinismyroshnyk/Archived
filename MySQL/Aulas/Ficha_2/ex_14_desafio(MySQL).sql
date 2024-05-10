SELECT d.ndep, d.nome, local
FROM dep d
LEFT JOIN emp e ON (d.ndep = e.ndep)
WHERE e.ndep IS NULL
;