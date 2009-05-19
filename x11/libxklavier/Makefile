# $NetBSD: Makefile,v 1.26 2009/05/19 08:59:38 wiz Exp $
#

DISTNAME=	libxklavier-3.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

CONFIGURE_ARGS+=	--enable-xkb-support
CONFIGURE_ARGS+=	--with-xmodmap-base=${PREFIX}/share/xmodmap

.include "../../mk/bsd.prefs.mk"
.if exists(${X11BASE}/share/X11/xkb/rules/xorg.xml)
CONFIGURE_ARGS+=	--with-xkb-base=${X11BASE}/share/X11/xkb
.else
CONFIGURE_ARGS+=	--with-xkb-base=${X11BASE}/lib/X11/xkb
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
