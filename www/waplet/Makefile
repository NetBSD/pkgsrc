# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:43 joerg Exp $
#

DISTNAME=	waplet
PKGNAME=	waplet-0.01
CATEGORIES=	www net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waplet/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://waplet.sourceforge.net/
COMMENT=	Java applet-based WAP emulator and WML browser

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS=	share/httpd/htdocs/waplet share/doc/waplet \
			share/examples/waplet

do-install:
	${INSTALL_DATA} ${WRKSRC}/waplet.jar ${DESTDIR}${PREFIX}/share/httpd/htdocs/waplet
.for file in README COPYING Parser.java Tag.java waplet.java
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/waplet
.endfor
.for file in sample.html wap_content.wml
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/examples/waplet
.endfor

.include "../../mk/bsd.pkg.mk"
