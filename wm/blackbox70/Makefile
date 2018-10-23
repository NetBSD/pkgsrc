# $NetBSD: Makefile,v 1.16 2018/10/23 12:26:06 jperkin Exp $

VERSION=	0.72
DISTNAME=	blackbox-${VERSION}
PKGNAME=	blackbox70-${VERSION}
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	blackboxwm
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/blackboxwm
COMMENT=	Small and fast X11 window manager

CONFLICTS=	bsetroot-[0-9]*
CONFLICTS+=	blackbox-[0-9]*

USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autopoint gettext-m4 gsed pkg-config
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-nls

LIBS+=		${BUILDLINK_LDADD.iconv}

BUILDLINK_DEPMETHOD.libXt?=	build

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
