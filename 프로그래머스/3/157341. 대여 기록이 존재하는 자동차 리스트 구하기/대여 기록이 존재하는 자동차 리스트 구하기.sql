select distinct(C.CAR_ID)
from CAR_RENTAL_COMPANY_CAR C
join CAR_RENTAL_COMPANY_RENTAL_HISTORY RH
on C.CAR_ID = RH.CAR_ID
where C.CAR_TYPE = '세단' and month(START_DATE) = 10
order by C.CAR_ID desc