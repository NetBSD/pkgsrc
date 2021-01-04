# $NetBSD: Makefile,v 1.1 2021/01/04 14:52:58 nia Exp $

DISTNAME=	mcwm-20130209-2
PKGNAME=	mcwm-20130209.2
CATEGORIES=	wm x11
MASTER_SITES=	https://hack.org/mc/hacks/mcwm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hack.org/mc/hacks/mcwm/
COMMENT=	Minimalist stacking X window manager based on XCB
LICENSE=	isc

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
.for prog in mcwm hidden
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} \
	    ${DESTDIR}${PREFIX}/bin/${prog}
	${INSTALL_PROGRAM} ${WRKSRC}/${prog}.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${prog}.1
.endfor

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
