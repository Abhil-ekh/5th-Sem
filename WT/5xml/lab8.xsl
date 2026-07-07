<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:d1="http://example.com/detail1"
xmlns:d2="http://example.com/detail2">
<xsl:template match="/">
<html>
<body>
<table border="1" cellpadding="5">
<tr bgcolor="lightgray">
    <th>Type</th>
    <th>Name</th>
    <th>Price / Address</th>
</tr>
<tr>
    <td>Fruit</td>
    <td>
        <xsl:value-of select="root/d1:detail/d1:name"/>
    </td>
    <td>
        <xsl:value-of select="root/d1:detail/d1:price"/>
    </td>
</tr>
<tr>
    <td>Person</td>
    <td>
        <xsl:value-of select="root/d2:detail/d2:name"/>
    </td>
    <td>
        <xsl:value-of select="root/d2:detail/d2:address"/>
    </td>
</tr>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>