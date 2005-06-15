# $NetBSD: Makefile,v 1.2 2005/06/15 09:03:28 hira Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-session-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 session manager

USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/xfce4-session
EGDIR=			${XFCE4_EGBASE}/session
CONF_FILES=		${EGDIR}/xfce4-session.rc \
			${PKG_SYSCONFDIR}/xfce4-session.rc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

MAKE_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
