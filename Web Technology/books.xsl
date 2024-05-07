<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
  <html>
  <head>
    <style type="text/css">
      body { font-family: Arial; }
      h2 { color: red; }
      div { margin-bottom: 10px; }
    </style>
  </head>
  <body>
    <h1>Books</h1>
    <xsl:for-each select="books/book">
      <div>
        <h2><xsl:value-of select="title"/></h2>
        <p><xsl:value-of select="author"/></p>
        <p><xsl:value-of select="year"/></p>
      </div>
    </xsl:for-each>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>
