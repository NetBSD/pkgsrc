# $NetBSD: Makefile,v 1.40 2012/09/15 10:07:10 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
PKGREVISION=	12
CATEGORIES=	x11
COMMENT=	Xfce widget library

PKGCONFIG_OVERRIDE=	libxfce4kbd-private/libxfce4kbd-private-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfcegui4/libxfcegui4-1.0.pc.in

CONFIGURE_ARGS+=	--disable-gladeui

EGDIR=			${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml
PKG_SYSCONFSUBDIR=	xdg
CONF_FILES=		${EGDIR}/xfce4-keyboard-shortcuts.xml \
	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xfce4-keyboard-shortcuts.xml

MAKE_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/include/xfce4
MAKE_DIRS+=	${XFCE4_EGBASE} ${XFCE4_EGBASE:Q}/xfconf ${EGDIR}
OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4 ${PKG_SYSCONFDIR}/xfce4/xfconf
OWN_DIRS+=	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
