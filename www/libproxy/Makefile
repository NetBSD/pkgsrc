# $NetBSD: Makefile,v 1.15 2012/11/27 11:26:23 drochner Exp $
#

DISTNAME=	libproxy-0.3.1
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	http://libproxy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-python
CONFIGURE_ENV+=	PYTHON=${TRUE}
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
PY_PATCHPLIST=	yes
CHECK_PORTABILITY_SKIP= test.d/*
USE_LANGUAGES=	c99
LIBS.SunOS+=	-lnsl -lsocket

PKGCONFIG_OVERRIDE+=	libproxy-1.0.pc.in

# 0.3.0 doesn't install the python bindings even when they
# are enabled, so comment out dependencies.
#BUILDLINK_API_DEPENDS.python26+= python26>=2.6.2nb4

post-extract:
	${RM} -rf ${WRKSRC}/test.d/.svn

#.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
