SELECT nome, ((sal*14)+IFNULL(premios, 0))*0.1 AS '10% Sal. Anual',premios
FROM emp
WHERE funcao = 'Vendedor'
    AND funcao < ((sal*14)+IFNULL(premios, 0))*0.1
    ORDER BY 2 , nome
;