# $NetBSD: Makefile,v 1.20 2006/02/17 06:49:26 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-${XFCE4_VERSION}
PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce desktop background manager


PKG_SYSCONFSUBDIR=	xdg/xfce4/desktop
EGDIR=			${XFCE4_EGBASE}/desktop
CONF_FILES=		${EGDIR:Q}/menu.xml ${PKG_SYSCONFDIR:Q}/menu.xml
.for l in ca cs da de el es et fi fr he hu ja ko nl pl pt_BR ro ru sk sv \
	uk vi zh_TW
CONF_FILES+=		${EGDIR:Q}/menu.xml.${l} \
			${PKG_SYSCONFDIR:Q}/menu.xml.${l}
.endfor
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml
.for l in cs eu fi he hu ja nl pl pt_BR ro ru sk sv zh_CN zh_TW
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml.${l} \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml.${l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
