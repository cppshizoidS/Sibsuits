SELECT hr.job_id
FROM (SELECT job_id, COUNT(*) FROM hours GROUP BY job_id) AS hr
JOIN (SELECT * FROM hours WHERE duration > 300) AS h ON hr.job_id = h.job_id 
GROUP BY hr.job_id HAVING COUNT(*) >= 2;
