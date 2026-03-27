-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred

SELECT m.title
FROM movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON s.person_id = p.id
WHERE p.name IN ("Jennifer Lawrence", "Bradley Cooper")
GROUP BY m.id
HAVING COUNT(DISTINCT p.id) = 2;
