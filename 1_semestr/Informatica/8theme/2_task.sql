SELECT COUNT(*) as total_penalty_shots,
SUM(CASE WHEN result = ‘miss’ THEN 1 ELSE 0 END) as missed_penalty_shots,
SUM(CASE WHEN result=‘save’ THEN 1 ELSE 0 END) as saved_penalty_shots
FROM soccer.penalty_shootouts;
