# $NetBSD: Makefile,v 1.8 2015/04/05 17:02:51 nros Exp $
#

DISTNAME=	i3-4.10.1
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
INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

EGDIR=		${PREFIX}/share/examples/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/config.keycodes

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:C/\/i3//}
MAKE_ENV+=	DEBUG=0
MAKE_ENV+=	SHM_SUPPORT=0

REPLACE_PERL+=	i3-dmenu-desktop
REPLACE_PERL+=	i3-migrate-config-to-v4 
REPLACE_PERL+=	i3-save-tree

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_MESSAGE.conf=	Change src/i3.mk to install conf files in share/examples
SUBST_FILES.conf=	src/i3.mk
SUBST_SED.conf=		-e s,$$\(SYSCONFDIR\),$$\(PREFIX\)/share/examples,g

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
