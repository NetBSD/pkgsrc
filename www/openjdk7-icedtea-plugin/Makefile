# $NetBSD: Makefile,v 1.6 2010/05/23 10:50:42 tnn Exp $
#

DISTNAME=	# from icedtea-extras.mk
PKGNAME=	openjdk7-icedtea-plugin-1.12.0.20100521
CATEGORIES=	www
MASTER_SITES=	# from icedtea-extras.mk

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin
#LICENSE=	# GPL2 + Classpath exception

PKG_DESTDIR_SUPPORT=	user-destdir

ICEDTEA_PACKAGE=	yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${ICEDTEA}

CONFIGURE_ARGS+=	--enable-npplugin

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/java/openjdk7
PREPEND_PATH+=			${PREFIX}/java/openjdk7/bin

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=		plugin/icedteanp/IcedTeaNPPlugin.cc
SUBST_SED.fix-paths+=		-e 's,%s/../../bin/java,${PREFIX}/java/openjdk7/bin/java,g'

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${WRKSRC}/plugin.build/icedteanp/IcedTeaNPPlugin.so

INSTALLATION_DIRS+=		lib/netscape/plugins

do-install:
	${INSTALL_LIB} ${WRKSRC}/plugin.build/icedteanp/IcedTeaNPPlugin.so ${DESTDIR}${PREFIX}/lib/netscape/plugins

BUILDLINK_API_DEPENDS.xulrunner+=       xulrunner>=1.9.1.3nb6
.include "../../lang/openjdk7/icedtea-extras.mk"
.include "../../mk/bsd.pkg.mk"
