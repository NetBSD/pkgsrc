# $NetBSD: Makefile,v 1.18 2006/02/05 23:11:44 joerg Exp $
#

DISTNAME=	wmfire-0.0.3.9pre4
PKGNAME=	wmfire-0.0.3.9.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://staff.xmms.org/zinx/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Displays generated fire according to system load

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/wmfire

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
