// Source : https://leetcode.com/problems/combine-two-tables/
// Author : Nan
// Date   : 2019-06-01
// Runtime: 303 ms

/*
* Easy SQL question.
*
* Time complexity O(-), Space complexity O(-)
*/

# Write your MySQL query statement below
SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person LEFT JOIN Address on Person.PersonId = Address.PersonId;