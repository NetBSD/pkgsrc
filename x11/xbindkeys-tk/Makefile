# $NetBSD: Makefile,v 1.7 2004/12/25 21:44:42 minskim Exp $
#

.include "../../x11/xbindkeys/Makefile.common"

PKGNAME=	${DISTNAME:S/xbindkeys/xbindkeys-tk/}
PKGREVISION=	1
COMMENT+=	(Tk interface)

DEPENDS+=	xbindkeys>=1.7.1:../../x11/xbindkeys
DEPENDS+=	tk>=8.3.4:../../x11/tk

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbindkeys_show ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbindkeys_show.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
