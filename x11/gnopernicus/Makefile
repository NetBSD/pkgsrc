# $NetBSD: Makefile,v 1.1.1.1 2003/12/30 17:56:39 xtraeme Exp $
#

DISTNAME=		gnopernicus-0.7.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnopernicus/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of accessibility apps for GNOME 2

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

CONFIGURE_ARGS+=	--disable-gtk-doc

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/gnopernicus-1.0.pc.in

GCONF2_SCHEMAS+=	brlmonitor.schemas
GCONF2_SCHEMAS+=	gnopernicus.schemas
GCONF2_SCHEMAS+=	remote.schemas

.include "../../audio/gnome-speech/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-mag/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
