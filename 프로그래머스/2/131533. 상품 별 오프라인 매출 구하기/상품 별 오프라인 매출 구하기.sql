select PRODUCT_CODE, sum(P.PRICE * O.SALES_AMOUNT) as SALES
from PRODUCT P
join OFFLINE_SALE O
on P.PRODUCT_ID = O.PRODUCT_ID
group by PRODUCT_CODE
order by SALES desc, PRODUCT_CODE