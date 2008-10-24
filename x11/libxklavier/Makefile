# $NetBSD: Makefile,v 1.22 2008/10/24 23:21:20 jnemeth Exp $
#

DISTNAME=	libxklavier-3.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

CONFIGURE_ARGS+=	--enable-xkb-support

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
