# $NetBSD: Makefile,v 1.4 2004/02/22 15:29:11 kristerw Exp $
#

.include "../../x11/xbindkeys/Makefile.common"

PKGNAME=	${DISTNAME:S/xbindkeys/xbindkeys-tk/}
COMMENT+=	(Tk interface)

DEPENDS+=	xbindkeys>=1.6.5:../../x11/xbindkeys

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbindkeys_show ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbindkeys_show.1 ${PREFIX}/man/man1

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
