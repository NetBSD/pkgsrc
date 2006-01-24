# $NetBSD: Makefile,v 1.18 2006/01/24 07:33:01 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-${XFCE4_VERSION}
PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce desktop background manager


PKG_SYSCONFSUBDIR=	xdg/xfce4/desktop
EGDIR=			${XFCE4_EGBASE}/desktop
CONF_FILES=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/menu.xml
.for _l in ca cs da de el es et fi fr he hu ja ko nl pl pt_BR ro ru sk sv \
	uk vi zh_TW
CONF_FILES+=		${EGDIR}/menu.xml.${_l} ${PKG_SYSCONFDIR}/menu.xml.${_l}
.endfor
CONF_FILES+=		${EGDIR}/xfce-registered-categories.xml \
			${PKG_SYSCONFDIR}/xfce-registered-categories.xml
.for _l in cs eu fi he hu ja nl pl pt_BR ro ru sk sv zh_CN zh_TW
CONF_FILES+=		${EGDIR}/xfce-registered-categories.xml.${_l} \
			${PKG_SYSCONFDIR}/xfce-registered-categories.xml.${_l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
