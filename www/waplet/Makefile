# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 07:04:25 rh Exp $
#

DISTNAME=	waplet
PKGNAME=	waplet-0.01
CATEGORIES=	www net
MASTER_SITES=	http://download.sourceforge.net/waplet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://waplet.sourceforge.net/

DEPENDS+=	apache-*:../../www/apache

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
