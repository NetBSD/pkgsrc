# $NetBSD: Makefile,v 1.12 2005/06/15 09:00:15 hira Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-${XFCE4_VERSION}
PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 desktop background manager

USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/desktop
EGDIR=			${XFCE4_EGBASE}/desktop
CONF_FILES=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/menu.xml
.for _l in cs da de es et fi fr he ja ko nl pt_BR ro ru sk uk vi zh_TW
CONF_FILES+=		${EGDIR}/menu.xml.${_l} ${PKG_SYSCONFDIR}/menu.xml.${_l}
.endfor
CONF_FILES+=		${EGDIR}/xfce-registered-categories.xml \
			${PKG_SYSCONFDIR}/xfce-registered-categories.xml
.for _l in cs eu fi hu ja nl pt_BR ro ru sk zh_CN zh_TW
CONF_FILES+=		${EGDIR}/xfce-registered-categories.xml.${_l} \
			${PKG_SYSCONFDIR}/xfce-registered-categories.xml.${_l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

MAKE_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
