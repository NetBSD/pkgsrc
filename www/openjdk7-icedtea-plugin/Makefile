# $NetBSD: Makefile,v 1.1.1.1 2009/10/14 11:39:25 tnn Exp $
#

DISTNAME=	# from icedtea-extras.mk
PKGNAME=	openjdk7-icedtea-plugin-1.11.0.20091005
CATEGORIES=	www
MASTER_SITES=	# from icedtea-extras.mk

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin
LICENSE=	# GPL2 + Classpath exception

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
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} IcedTeaNPPlugin.so

INSTALLATION_DIRS+=		lib/netscape/plugins

do-install:
	${INSTALL_LIB} ${WRKSRC}/plugin/icedteanp/IcedTeaNPPlugin.so ${DESTDIR}${PREFIX}/lib/netscape/plugins

BUILDLINK_API_DEPENDS.xulrunner+=       xulrunner>=1.9.1.3nb6
.include "../../lang/openjdk7/icedtea-extras.mk"
.include "../../mk/bsd.pkg.mk"
