# $NetBSD: Makefile,v 1.34 2009/08/26 19:57:02 sno Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"
.include "../../mk/compiler.mk"

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
PKGREVISION=		2
CATEGORIES=		x11
COMMENT=		Xfce panel

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

OWN_DIRS+=		xdg/xfce4
OWN_DIRS+=		xdg/xfce4/panel
PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel
.for f in clock-14.rc launcher-10.rc launcher-7.rc launcher-8.rc launcher-9.rc \
	panels.xml systray-4.rc xfce4-menu-5.rc
CONF_FILES+=		${EGDIR:Q}/$f ${PKG_SYSCONFDIR:Q}/$f
.endfor

# If using gcc-4, compile the panel launcher without GCC optimization. See
# http://bugzilla.xfce.org/show_bug.cgi?id=2262

.if (!empty(CC_VERSION:Mgcc-4.*))
SUBST_CLASSES+=		launcher
SUBST_STAGE.launcher=	post-configure
SUBST_FILES.launcher=	plugins/launcher/Makefile
SUBST_SED.launcher=	-e 's|-O |-O0 |g'
SUBST_SED.launcher+=	-e 's|-O[123s] |-O0 |g'
.endif

post-install:
	@${ECHO} "Removing the dummy files"
	rm -f ${PREFIX}/bin/xfce4-iconbox ${PREFIX}/bin/xftaskbar4

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
