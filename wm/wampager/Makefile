# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:17 grant Exp $
#

DISTNAME=	wampager-0.9.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.waimea.org/wampager_info.html
COMMENT=	Virtual pager dockapp for the Waimea Window Manager

DEPENDS=	waimea>=0.4.0:../../wm/waimea

USE_BUILDLINK2=	YES
USE_X11=	YES

do-build:
	@${ECHO} "${CC} ${CFLAGS} wampager.c -o wampager ${LDFLAGS} \
	    -lX11 -lXpm -lXext"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} \
	    wampager.c -o wampager ${LDFLAGS} -lX11 -lXpm -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wampager ${PREFIX}/bin

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
