# $NetBSD: Makefile,v 1.20 2006/12/15 20:33:05 joerg Exp $
#

DISTNAME=	wmfire-0.0.3.9pre4
PKGNAME=	wmfire-0.0.3.9.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://staff.xmms.org/zinx/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Displays generated fire according to system load

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/wmfire

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
