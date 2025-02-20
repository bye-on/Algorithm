-- 코드를 입력하세요
SELECT PRICE as MAX_PRICE from PRODUCT 
where price = (select max(price) from product where price);