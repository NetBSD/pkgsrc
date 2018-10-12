# $NetBSD: Makefile,v 1.14 2018/10/12 18:28:53 he Exp $

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
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	automake autoconf

LIBS+=		${BUILDLINK_LDADD.iconv}

BUILDLINK_DEPMETHOD.libXt?=	build

pre-configure:
		cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
