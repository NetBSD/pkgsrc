# $NetBSD: Makefile,v 1.28 2013/10/10 14:42:36 ryoon Exp $
#

DISTNAME=	icedtea-web-9e1f7dc48c20
PKGNAME=	icedtea-web-1.5pre
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	-http://icedtea.classpath.org/hg/icedtea-web/archive/9e1f7dc48c20.tar.bz2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin and Web Start launcher
#LICENSE=	# GPL2 + Classpath exception

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		autoconf automake gmake gsed perl pkg-config zip

REPLACE_PERL=		javac.in

CONFIGURE_ARGS+=	--with-jdk-home=${PREFIX}/java/openjdk7
CONFIGURE_ARGS+=	--with-rhino=${PREFIX}/java/openjdk7/jre/lib/rhino.jar
CONFIGURE_ARGS+=	--disable-docs

MAKE_ENV+=		BOOT_DIR=${PREFIX}/java/openjdk7

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -if


INSTALLATION_DIRS+=		lib/netscape/plugins

post-install:
	cd ${DESTDIR}/${PREFIX}/lib/netscape/plugins && \
		${LN} -s ../../IcedTeaPlugin.so IcedTeaPlugin.so
	${RM} -r ${DESTDIR}/${PREFIX}/bin ${DESTDIR}/${PREFIX}/man

BUILDLINK_API_DEPENDS.xulrunner17+=       xulrunner17>=17.0.6nb1
.include "../../devel/xulrunner17/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjdk7+=       openjdk7>=1.7.0.147
.include "../../lang/openjdk7/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
