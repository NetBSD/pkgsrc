# $NetBSD: Makefile,v 1.23 2006/01/24 07:33:01 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-panel-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes


PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel
CONF_FILES=		${EGDIR}/contents.xml ${PKG_SYSCONFDIR}/contents.xml
.for _l in ar az ca da el eu fi fr he hu it ja ko lt ms nl pl ro ru sk sv \
	tr vi zh_CN zh_TW
CONF_FILES+=		${EGDIR}/contents.xml.${_l} \
			${PKG_SYSCONFDIR}/contents.xml.${_l}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
