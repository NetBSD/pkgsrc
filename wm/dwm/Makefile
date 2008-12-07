# $NetBSD: Makefile,v 1.6 2008/12/07 15:46:39 tonio Exp $

DISTNAME=	dwm-5.3.1
CATEGORIES=	wm
MASTER_SITES=	http://code.suckless.org/dl/dwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suckless.org/dwm/
COMMENT=	Dynamic window manager

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
