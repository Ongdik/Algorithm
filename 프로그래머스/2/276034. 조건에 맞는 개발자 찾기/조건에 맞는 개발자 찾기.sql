select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS 
where 
    SKILL_CODE & (
        select CODE
        from SKILLCODES
        where NAME = 'C#'
    ) or
    SKILL_CODE & (
        select CODE
        from SKILLCODES
        where NAME = 'Python'
    )
order by ID