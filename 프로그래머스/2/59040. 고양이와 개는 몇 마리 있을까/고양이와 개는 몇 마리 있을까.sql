select ANIMAL_TYPE, count(ANIMAL_ID)
from ANIMAL_INS
where ANIMAL_TYPE = 'Cat' or ANIMAL_TYPE = 'Dog'
group by ANIMAL_TYPE
order by ANIMAL_TYPE