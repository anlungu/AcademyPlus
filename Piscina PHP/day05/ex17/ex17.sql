SELECT count(id_sub) AS nb_susc, round(avg(price)) AS av_susc, sum(mod(duration_sub, 42)) AS ft FROM subscription;