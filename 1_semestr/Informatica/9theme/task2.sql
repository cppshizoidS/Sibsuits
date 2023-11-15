SELECT patient_id, COUNT(doctor_id) as num_doctors FROM hospital WHERE doctor_id IS NOT NULL
GROUP BY patient_id
