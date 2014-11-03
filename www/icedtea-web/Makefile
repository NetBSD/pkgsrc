# $NetBSD: Makefile,v 1.36 2014/11/03 12:31:01 ryoon Exp $

# Keep icedtea-web distfile in sync with lang/openjdk7/icedtea-extras.mk
DISTNAME=	icedtea-web-1.5.1
CATEGORIES=	www
MASTER_SITES=	http://icedtea.wildebeest.org/download/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin and Web Start launcher
#LICENSE=	# GPL2 + Classpath exception

EXTRACT_USING=	bsdtar

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake bash gmake gsed perl pkg-config zip
LICENSE=		gnu-gpl-v2

REPLACE_PERL=		javac.in

CONFIGURE_ENV+=		ac_cv_path_BIN_BASH=${BASH:Q}

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

.include "../../devel/xulrunner31/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjdk7+=openjdk7>=1.7.25nb4
.include "../../lang/openjdk7/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
