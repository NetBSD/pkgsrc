# $NetBSD: Makefile,v 1.17 2005/11/09 07:09:05 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce utilities

USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR}/xinitrc ${PKG_SYSCONFDIR}/xinitrc

REQD_DIRS+=		${EGDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "options.mk"

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
