# $NetBSD: Makefile,v 1.28 2014/05/05 00:48:28 ryoon Exp $
#

DISTNAME=	eekboard-1.0.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://cloud.github.com/downloads/ueno/eekboard/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/eekboard/
COMMENT=	Virtual keyboard for GNOME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	eek/eek-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-gtk-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-xkl-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eekboard/eekboard-0.90.pc.in

BUILD_DEFS+=		PKG_SYSCONFBASE

EXAMPLESDIR=		${PREFIX}/share/examples/eekboard

INSTALL_MAKE_FLAGS+=	sysconfdir=${EXAMPLESDIR}

MAKE_DIRS+=		${PKG_SYSCONFBASE}/xdg/autostart
CONF_FILES+=		${EXAMPLESDIR}/xdg/autostart/eekboard-autostart.desktop \
			${PKG_SYSCONFBASE}/xdg/autostart/eekboard-autostart.desktop

TEST_TARGET=		check

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
