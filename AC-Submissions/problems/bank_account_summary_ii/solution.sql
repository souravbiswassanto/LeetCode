# Write your MySQL query statement below
select p.name, sum(t.amount) as balance from users p left join transactions t using(account) group by t.account having sum(t.amount) > 10000