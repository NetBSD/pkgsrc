# $NetBSD: Makefile,v 1.2 2003/09/17 15:12:14 jmmv Exp $
#

.include "../../x11/xbindkeys/Makefile.common"

PKGNAME=	${DISTNAME:S/xbindkeys/xbindkeys-tk/}
COMMENT+=	(Tk interface)

DEPENDS+=	xbindkeys>=1.5.5nb1:../../x11/xbindkeys

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbindkeys_show ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbindkeys_show.1 ${PREFIX}/man/man1

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
