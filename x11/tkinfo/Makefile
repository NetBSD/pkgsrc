# $NetBSD: Makefile,v 1.15 2001/05/05 19:51:20 jlam Exp $
# FreeBSD Id: Makefile,v 1.15 1997/12/16 09:26:12 tg Exp
#

DISTNAME=	tkinfo-2.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/doctools/info/} \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://math-www.uni-paderborn.de/~axel/tkinfo/
COMMENT=	Tk script to read and display GNU "info" files

DEPENDS=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
NO_BUILD=	yes

post-patch:
	cd ${WRKSRC}; \
	  ${MV} tkinfo tkinfo.src; \
	  ${SED} \
	    -e 's|@LOCALBASE@|${LOCALBASE}|g' \
	    -e 's|@X11BASE@|${X11BASE}|g' \
	    < tkinfo.src > tkinfo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkinfo.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
