# $NetBSD: Makefile,v 1.5 2014/05/05 00:48:25 ryoon Exp $
#

DISTNAME=	i3-4.7.2
PKGREVISION=	1
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

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	/usr/bin/env perl
REPLACE.perl.new=	${TOOLS_PATH.perl}
REPLACE_FILES.perl=	i3-dmenu-desktop i3-migrate-config-to-v4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.for i in i3 i3-dmenu-desktop i3-migrate-config-to-v4 i3-sensible-editor	\
	i3-sensible-pager i3-sensible-terminal
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for i in i3bar i3-config-wizard i3-input i3-msg i3-nagbar
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_DATA} ${WRKSRC}/i3.config ${DESTDIR}${EGDIR}/config
	${INSTALL_DATA} ${WRKSRC}/i3.config.keycodes ${DESTDIR}${EGDIR}/config.keycodes
	${INSTALL_DATA} ${WRKSRC}/i3.xsession.desktop ${DESTDIR}${PREFIX}/share/xsessions/
	${INSTALL_DATA} ${WRKSRC}/include/i3/ipc.h ${DESTDIR}${PREFIX}/include/i3/

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
