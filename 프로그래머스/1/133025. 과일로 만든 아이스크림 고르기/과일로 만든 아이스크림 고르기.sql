-- 코드를 입력하세요
SELECT FLAVOR from FIRST_HALF where TOTAL_ORDER >= 3000 and flavor in (select flavor from ICECREAM_INFO where INGREDIENT_TYPE='fruit_based') order by TOTAL_ORDER DESC;