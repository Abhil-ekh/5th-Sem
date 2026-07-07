xquery version "1.0";
for $i in doc("lab9.xml")/store/item
where $i/price = 200
return $i