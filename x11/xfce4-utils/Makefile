# $NetBSD: Makefile,v 1.31 2008/07/14 12:56:19 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce utilities

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR:Q}/xinitrc ${PKG_SYSCONFDIR:Q}/xinitrc
USE_TOOLS+=		xinit:run

REQD_DIRS+=		${EGDIR}

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
