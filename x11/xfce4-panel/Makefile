# $NetBSD: Makefile,v 1.31 2007/12/07 19:43:30 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"
.include "../../mk/compiler.mk"

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
#PKGREVISION=		1
CATEGORIES=		x11
COMMENT=		Xfce panel

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

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
