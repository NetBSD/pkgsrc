# $NetBSD: Makefile,v 1.24 2007/01/18 15:16:02 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-${XFCE4_VERSION}
PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	4
CATEGORIES=	x11
COMMENT=	Xfce desktop background manager


PKG_SYSCONFSUBDIR=	xdg/xfce4/desktop
EGDIR=			${XFCE4_EGBASE}/desktop
CONF_FILES=		${EGDIR:Q}/menu.xml ${PKG_SYSCONFDIR:Q}/menu.xml
.for l in ca cs da de el es et fi fr he hu ja ko nl pl pt_BR ro ru sk sv \
	uk vi zh_TW
CONF_FILES+=		${EGDIR:Q}/menu.xml.${l:Q} \
			${PKG_SYSCONFDIR:Q}/menu.xml.${l:Q}
.endfor
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml
.for l in cs eu fi he hu ja nl pl pt_BR ro ru sk sv zh_CN zh_TW
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml.${l:Q} \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml.${l:Q}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE:Q} ${EGDIR:Q}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
