select ORDER_ID, PRODUCT_ID, date_format(OUT_DATE, '%Y-%m-%d'), 
    case
        when OUT_DATE <= '2022-05-01' then '출고완료'
        when OUT_DATE > '2022-05-01' then '출고대기'
        else '출고미정'
    end
from FOOD_ORDER
order by ORDER_ID