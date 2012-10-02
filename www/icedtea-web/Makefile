# $NetBSD: Makefile,v 1.14 2012/10/02 17:12:08 tron Exp $
#

DISTNAME=	61e08e67b176
PKGNAME=	icedtea-web-1.2pre
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://icedtea.classpath.org/hg/icedtea-web/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin and Web Start launcher
#LICENSE=	# GPL2 + Classpath exception

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		autoconf automake gmake pkg-config zip
WRKSRC=			${WRKDIR}/icedtea-web-${DISTNAME}

CONFIGURE_ARGS+=	 --with-jdk-home=${PREFIX}/java/openjdk7

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -if

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${WRKSRC}/plugin/icedteanp/IcedTeaPlugin.so launcher.build/javaws

INSTALLATION_DIRS+=		bin lib/netscape/plugins

do-install:
	${INSTALL_LIB} ${WRKSRC}/plugin/icedteanp/IcedTeaPlugin.so ${DESTDIR}${PREFIX}/lib/netscape/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/launcher.build/javaws ${DESTDIR}${PREFIX}/bin

BUILDLINK_API_DEPENDS.xulrunner+=       xulrunner>=5.0
.include "../../devel/xulrunner/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjdk7+=       openjdk7>=1.7.0.147
.include "../../lang/openjdk7/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
