# $NetBSD: Makefile,v 1.22 2006/02/17 06:49:26 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce utilities


PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR:Q}/xinitrc ${PKG_SYSCONFDIR:Q}/xinitrc

REQD_DIRS+=		${EGDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
