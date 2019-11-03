# $NetBSD: Makefile,v 1.25 2019/11/03 09:14:18 rillig Exp $
#

DISTNAME=	wmfire-0.0.3.9pre4
PKGNAME=	wmfire-0.0.3.9.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://staff.xmms.org/zinx/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Displays generated fire according to system load

GNU_CONFIGURE=		YES
INSTALLATION_DIRS+=	share/doc/wmfire

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/wmfire

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
