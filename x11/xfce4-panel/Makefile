# $NetBSD: Makefile,v 1.25 2006/02/17 06:49:26 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-panel-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	Xfce panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes


PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel
CONF_FILES=		${EGDIR:Q}/contents.xml ${PKG_SYSCONFDIR:Q}/contents.xml
.for l in ar az ca da el eu fi fr he hu it ja ko lt ms nl pl ro ru sk sv \
	tr vi zh_CN zh_TW
CONF_FILES+=		${EGDIR:Q}/contents.xml.${l} \
			${PKG_SYSCONFDIR:Q}/contents.xml.${l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
