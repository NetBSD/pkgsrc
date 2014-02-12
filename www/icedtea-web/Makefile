# $NetBSD: Makefile,v 1.33 2014/02/12 23:18:45 tron Exp $

# Keep icedtea-web distfile in sync with lang/openjdk7/icedtea-extras.mk
DISTNAME=	icedtea-web-81dfc0552a1c
PKGNAME=	icedtea-web-1.5pre
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	-http://icedtea.classpath.org/hg/icedtea-web/archive/81dfc0552a1c.tar.bz2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin and Web Start launcher
#LICENSE=	# GPL2 + Classpath exception

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake bash gmake gsed perl pkg-config zip
LICENSE=		gnu-gpl-v2

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

.include "../../devel/xulrunner24/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjdk7+=openjdk7>=1.7.25nb4
.include "../../lang/openjdk7/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
