# $NetBSD: Makefile,v 1.13 2005/06/15 09:04:32 hira Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 utilities

USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR}/xinitrc ${PKG_SYSCONFDIR}/xinitrc

MAKE_DIRS+=		${EGDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
