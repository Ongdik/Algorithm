select month(START_DATE) as MONTH, CAR_ID, count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(START_DATE) between 8 and 10
    and CAR_ID in (
        select CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where month(START_DATE) between 8 and 10
        group by CAR_ID
        having count(CAR_ID) >= 5)
group by CAR_ID, MONTH
having RECORDS >= 1
order by MONTH, CAR_ID desc
