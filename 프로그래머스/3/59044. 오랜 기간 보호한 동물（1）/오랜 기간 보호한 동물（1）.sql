select NAME, DATETIME
from ANIMAL_INS AI
where not exists (
    select ANIMAL_ID
    from ANIMAL_OUTS AO
    where AI.ANIMAL_ID = AO.ANIMAL_ID
)
order by DATETIME
limit 3