# $NetBSD: Makefile,v 1.18 2003/12/15 02:55:53 xtraeme Exp $
#

DISTNAME=	control-center-2.4.0
PKGNAME=	gnome2-${DISTNAME}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/control-center/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 configuration utility

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS= 	apps_gnome_settings_daemon_default_editor.schemas
GCONF2_SCHEMAS+=	apps_gnome_settings_daemon_screensaver.schemas
GCONF2_SCHEMAS+=	desktop_gnome_font_rendering.schemas
GCONF2_SCHEMAS+=	themus.schemas
GCONF2_SCHEMAS+=	fontilus.schemas

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/gnome2-control-center
CONF_FILES=		${EGDIR}/theme-method.conf \
			${PKG_SYSCONFDIR}/theme-method.conf
CONF_FILES+=		${EGDIR}/font-method.conf \
			${PKG_SYSCONFDIR}/font-method.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/themus/theme-method.conf \
		${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/fontilus/font-method.conf \
		${EGDIR}

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../wm/metacity/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
