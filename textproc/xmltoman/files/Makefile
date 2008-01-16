
SCRIPTS=	xmltoman xmlmantohtml
MAN=		xmltoman.1 xmlmantohtml.1

.PATH: ${.CURDIR}/xml
FILES=		xmltoman.dtd xmltoman.css xmltoman.xsl
FILESDIR=	${PREFIX}/share/xmltoman

MKCATPAGES=	no
CLEANFILES=	*.1

.include <bsd.prog.mk>

xmltoman.1: xml/xmltoman.1.xml
	./xmltoman ${.OODATE} > ${.TARGET}

xmlmantohtml.1: xml/xmlmantohtml.1.xml
	./xmltoman ${.OODATE} > ${.TARGET}

