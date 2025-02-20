-- 코드를 입력하세요
SELECT PT_NAME, PT_NO, GEND_CD, AGE, 
(case when TLNO is not null then TLNO
else 'NONE'
end) TLNO
from PATIENT 
where age <= 12 and gend_cd = 'W'
order by age DESC, pt_name;