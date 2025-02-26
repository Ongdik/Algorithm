select concat('/home/grep/src/', UGB.BOARD_ID, '/', UGF.FILE_ID, UGF.FILE_NAME, UGF.FILE_EXT) as FILE_PATH
from USED_GOODS_BOARD UGB
join USED_GOODS_FILE UGF
on UGB.BOARD_ID = UGF.BOARD_ID
where UGB.VIEWS in (
    select max(VIEWS)
    from USED_GOODS_BOARD
)
order by UGF.FILE_ID desc