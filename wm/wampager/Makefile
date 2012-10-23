# $NetBSD: Makefile,v 1.18 2012/10/23 10:24:15 wiz Exp $
#

DISTNAME=	wampager-0.9.1
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://waimea.sourceforge.net/
COMMENT=	Virtual pager dockapp for the Waimea Window Manager

DEPENDS+=	waimea>=0.4.0:../../wm/waimea

INSTALLATION_DIRS=	bin

do-build:
	@${ECHO} "${CC} ${CFLAGS} wampager.c -o wampager ${LDFLAGS} \
	    -lX11 -lXpm -lXext"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} \
	    wampager.c -o wampager ${LDFLAGS} -lX11 -lXpm -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wampager ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
