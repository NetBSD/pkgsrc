# $NetBSD: Makefile,v 1.3 2000/11/11 17:49:28 tron Exp $
#

DISTNAME=	waplet
PKGNAME=	waplet-0.01
CATEGORIES=	www net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waplet/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://waplet.sourceforge.net/

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/waplet
	${INSTALL_DATA} ${WRKSRC}/waplet.jar ${PREFIX}/share/httpd/htdocs/waplet
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/waplet
.for file in README COPYING Parser.java Tag.java waplet.java
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/waplet
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/waplet
.for file in sample.html wap_content.wml
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/waplet
.endfor

.include "../../mk/bsd.pkg.mk"
