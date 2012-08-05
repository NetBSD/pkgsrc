# $NetBSD: Makefile,v 1.11 2012/08/05 13:39:04 shattered Exp $
#

DISTNAME=	libproxy-0.3.1
CATEGORIES=	www gnome
MASTER_SITES=	http://libproxy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

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
#PYTHON_VERSIONS_ACCEPTED=	25 27 26
#BUILDLINK_API_DEPENDS.python26+= python26>=2.6.2nb4
#BUILDLINK_API_DEPENDS.python25+= python25>=2.5.4nb2

post-extract:
	${RM} -rf ${WRKSRC}/test.d/.svn

#.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
