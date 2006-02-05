# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:15 joerg Exp $
#

DISTNAME=	wampager-0.9.1
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.waimea.org/wampager_info.html
COMMENT=	Virtual pager dockapp for the Waimea Window Manager

DEPENDS+=	waimea>=0.4.0:../../wm/waimea

INSTALLATION_DIRS=	bin

do-build:
	@${ECHO} "${CC} ${CFLAGS} wampager.c -o wampager ${LDFLAGS} \
	    -lX11 -lXpm -lXext"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} \
	    wampager.c -o wampager ${LDFLAGS} -lX11 -lXpm -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wampager ${PREFIX}/bin

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
