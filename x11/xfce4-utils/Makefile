# $NetBSD: Makefile,v 1.21 2006/02/05 23:11:47 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce utilities


PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}
CONF_FILES=		${EGDIR}/xinitrc ${PKG_SYSCONFDIR}/xinitrc

REQD_DIRS+=		${EGDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
