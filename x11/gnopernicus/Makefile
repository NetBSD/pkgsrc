# $NetBSD: Makefile,v 1.16 2004/04/20 14:35:39 jmmv Exp $
#

DISTNAME=		gnopernicus-0.8.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnopernicus/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of accessibility apps for GNOME 2

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PKG_SYSCONFSUBDIR=	gnopernicus
OWN_DIRS+=		${PKG_SYSCONFDIR}/translation_tables
EGDIR=			${PREFIX}/share/examples/gnopernicus

CONF_FILES=		${EGDIR}/translation_tables/de.a2b \
			${PKG_SYSCONFDIR}/translation_tables/de.a2b
CONF_FILES+=		${EGDIR}/translation_tables/en_US.a2b \
			${PKG_SYSCONFDIR}/translation_tables/en_US.a2b
CONF_FILES+=		${EGDIR}/translation_tables/es.a2b \
			${PKG_SYSCONFDIR}/translation_tables/es.a2b
CONF_FILES+=		${EGDIR}/translation_tables/sv.a2b \
			${PKG_SYSCONFDIR}/translation_tables/sv.a2b

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

CONFIGURE_ARGS+=	--disable-gtk-doc

PKGCONFIG_OVERRIDE+=    gnopernicus-1.0.pc.in

GCONF2_SCHEMAS+=	brlmonitor.schemas
GCONF2_SCHEMAS+=	gnopernicus.schemas
GCONF2_SCHEMAS+=	remote.schemas

.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-mag/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
