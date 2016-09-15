# $NetBSD: Makefile,v 1.15 2016/09/15 15:59:13 wiz Exp $

.include "../../x11/xbindkeys/Makefile.common"

PKGNAME=	${DISTNAME:S/xbindkeys/xbindkeys-tk/}
COMMENT+=	(Tk interface)

DEPENDS+=	xbindkeys>=1.7.3:../../x11/xbindkeys
DEPENDS+=	tk>=8.3.4:../../x11/tk

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbindkeys_show ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbindkeys_show.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
