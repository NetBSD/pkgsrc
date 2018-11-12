# $NetBSD: Makefile,v 1.103 2018/11/12 03:53:07 ryoon Exp $
#

DISTNAME=		gnopernicus-1.1.1
PKGREVISION=		48
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnopernicus/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Collection of accessibility apps for GNOME 2

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-sysconfsubdir=
PKG_SYSCONFSUBDIR=	gnopernicus
OWN_DIRS+=		${PKG_SYSCONFDIR}/translation_tables
EGDIR=			${PREFIX}/share/examples/gnopernicus
REPLACE_SH+=		gnopi/gnopernicus-mag-config

CONF_FILES=		${EGDIR}/translation_tables/de.a2b \
			${PKG_SYSCONFDIR}/translation_tables/de.a2b
CONF_FILES+=		${EGDIR}/translation_tables/en_US.a2b \
			${PKG_SYSCONFDIR}/translation_tables/en_US.a2b
CONF_FILES+=		${EGDIR}/translation_tables/es.a2b \
			${PKG_SYSCONFDIR}/translation_tables/es.a2b
CONF_FILES+=		${EGDIR}/translation_tables/fr.a2b \
			${PKG_SYSCONFDIR}/translation_tables/fr.a2b
CONF_FILES+=		${EGDIR}/translation_tables/sv.a2b \
			${PKG_SYSCONFDIR}/translation_tables/sv.a2b
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	translationdir=${EGDIR}/translation_tables

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnopernicus
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

CONFIGURE_ARGS+=	--disable-gtk-doc

PKGCONFIG_OVERRIDE+=	gnopernicus-1.0.pc.in

GCONF_SCHEMAS+=	brlmonitor.schemas
GCONF_SCHEMAS+=	gnopernicus.schemas
GCONF_SCHEMAS+=	remote.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.4.1
BUILDLINK_API_DEPENDS.gnome-speech+=	gnome-speech>=0.3.5
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libxml2+=		libxml2>=2.6.7

.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-mag/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
