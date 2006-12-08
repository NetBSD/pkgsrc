# $NetBSD: Makefile,v 1.11 2006/12/08 16:16:12 obache Exp $
#

.include "../../x11/xbindkeys/Makefile.common"

PKGNAME=	${DISTNAME:S/xbindkeys/xbindkeys-tk/}
COMMENT+=	(Tk interface)

DEPENDS+=	xbindkeys>=1.7.3:../../x11/xbindkeys
DEPENDS+=	tk>=8.3.4:../../x11/tk

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbindkeys_show ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbindkeys_show.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
