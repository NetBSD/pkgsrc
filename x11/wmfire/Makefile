# $NetBSD: Makefile,v 1.22 2009/12/17 17:48:42 abs Exp $
#

DISTNAME=	wmfire-0.0.3.9pre4
PKGNAME=	wmfire-0.0.3.9.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://staff.xmms.org/zinx/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Displays generated fire according to system load
PKG_DESTDIR_SUPPORT= user-destdir

GNU_CONFIGURE=	YES
INSTALLATION_DIRS+= share/doc/wmfire

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/wmfire

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
