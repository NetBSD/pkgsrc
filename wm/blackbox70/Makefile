# $NetBSD: Makefile,v 1.7 2012/02/16 19:57:57 hans Exp $
#

DISTNAME=	blackbox-0.70.1
PKGNAME=	blackbox70-0.70.1
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	bsetroot-*
CONFLICTS+=	blackbox-*

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

LIBS.SunOS+=	-liconv

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
