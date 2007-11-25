# $NetBSD: Makefile,v 1.4 2007/11/25 23:23:25 wiz Exp $

DISTNAME=	dwm-4.7
CATEGORIES=	wm
MASTER_SITES=	http://suckless.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dwm.suckless.org/
COMMENT=	Dynamic window manager

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwm.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
