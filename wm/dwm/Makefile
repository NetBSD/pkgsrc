# $NetBSD: Makefile,v 1.2 2007/05/11 21:39:35 tonio Exp $

DISTNAME=	dwm-4.0
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
