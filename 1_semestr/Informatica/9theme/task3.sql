SELECT country, MAX(penalty_count) AS max_penalty_count FROM soccer WHERE penalty_count > 0 GROUP BY country
