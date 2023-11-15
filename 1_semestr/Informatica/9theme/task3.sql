<?xml version="1.0" encoding="UTF-8"?>
<SqlQuery>
<Id>452</Id>
 SELECT country, MAX(penalty_count) AS max_penalty_count FROM soccer WHERE penalty_count > 0 GROUP BY country
  </Query>
</SqlQuery>
