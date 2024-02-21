-- 코드를 입력하세요
SELECT A.PRODUCT_ID, A.PRODUCT_NAME, (A.PRICE * SUM(B.AMOUNT)) AS TOTAL_SALES
FROM FOOD_PRODUCT AS A
JOIN FOOD_ORDER AS B
ON A.PRODUCT_ID = B.PRODUCT_ID
WHERE B.PRODUCE_DATE LIKE '2022-05-%'
GROUP BY B.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, PRODUCT_ID