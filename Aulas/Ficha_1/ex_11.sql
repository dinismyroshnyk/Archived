SELECT nome, funcao, ((sal * 14) + IFNULL(premios, 0)) AS 'Remuneração Anual'
FROM emp
;