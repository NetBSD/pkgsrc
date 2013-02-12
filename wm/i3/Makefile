# $NetBSD: Makefile,v 1.1.1.1 2013/02/12 23:25:35 tonnerre Exp $
#

DISTNAME=	i3-4.4
CATEGORIES=	wm
MASTER_SITES=	http://i3wm.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://i3wm.org/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

USE_TOOLS+=	gmake bison lex yacc pkg-config perl
USE_LANGUAGES=	c99
MAKE_JOBS_SAFE=	no

PKG_SYSCONFSUBDIR=	i3
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/i3
INSTALLATION_DIRS+=	share/xsessions include/i3

EGDIR=		${PREFIX}/share/examples/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/config.keycodes

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:C/\/i3//}
MAKE_ENV+=	DEBUG=0
MAKE_ENV+=	SHM_SUPPORT=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.for i in i3bar i3-config-wizard i3-input i3-msg i3-nagbar
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for i in i3-config-wizard
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${DESTDIR}${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/i3.config ${DESTDIR}${EGDIR}/config
	${INSTALL_DATA} ${WRKSRC}/i3.config.keycodes ${DESTDIR}${EGDIR}/config.keycodes
	${INSTALL_DATA} ${WRKSRC}/i3.xsession.desktop ${DESTDIR}${PREFIX}/share/xsessions/
	${INSTALL_DATA} ${WRKSRC}/include/i3/ipc.h ${DESTDIR}${PREFIX}/include/i3/
	${INSTALL_SCRIPT} ${WRKSRC}/i3-sensible-editor ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/i3-sensible-pager ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/i3-sensible-terminal ${DESTDIR}${PREFIX}/bin/

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
