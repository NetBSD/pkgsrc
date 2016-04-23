# $NetBSD: Makefile,v 1.1 2016/04/23 18:32:09 adam Exp $

DISTNAME=	wslay-1.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tatsuhiro-t/wslay/
COMMENT=	WebSocket library written in C
LICENSE=	mit

# parallel build fails when building man-pages with sphinx
MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4:../../textproc/py-sphinx

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SPHINX_BUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}
PKGCONFIG_OVERRIDE+=	lib/libwslay.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i && automake && autoconf

# Only needed for examples
#.include "../../devel/cunit/buildlink3.mk"
#.include "../../security/nettle/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
