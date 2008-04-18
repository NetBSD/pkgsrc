# $NetBSD: Makefile,v 1.2 2008/04/18 17:37:10 bjs Exp $
#
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

