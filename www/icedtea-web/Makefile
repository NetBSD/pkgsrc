# $NetBSD: Makefile,v 1.42 2016/03/05 11:29:37 jperkin Exp $

# Keep icedtea-web distfile in sync with lang/openjdk7/icedtea-extras.mk
DISTNAME=	icedtea-web-1.5.2
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://icedtea.wildebeest.org/download/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icedtea.classpath.org/
COMMENT=	Java browser plugin and Web Start launcher
#LICENSE=	# GPL2 + Classpath exception

EXTRACT_USING=	gtar

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake bash:run gmake gsed perl pkg-config zip
LICENSE=		gnu-gpl-v2

REPLACE_PERL=		javac.in
REPLACE_BASH=		launcher/launchers.in

CONFIGURE_ENV+=		ac_cv_path_BIN_BASH=${BASH:Q}

.include "../../mk/java-vm.mk"

.if !empty(PKG_JVM:Mopenjdk8)
MAKE_ENV+=		BOOT_DIR=${PREFIX}/java/openjdk8
CONFIGURE_ARGS+=	--with-jdk-home=${PREFIX}/java/openjdk8
# XXX openjdk8 has nashorn instead of rhino. Do we need to ship a local copy of rhino here?
#CONFIGURE_ARGS+=	--with-rhino=${PREFIX}/java/openjdk8/jre/lib/rhino.jar
BUILDLINK_API_DEPENDS.openjdk8+=	openjdk8-[0-9]*
.include "../../lang/openjdk8/buildlink3.mk"
.else
MAKE_ENV+=		BOOT_DIR=${PREFIX}/java/openjdk7
CONFIGURE_ARGS+=	--with-jdk-home=${PREFIX}/java/openjdk7
CONFIGURE_ARGS+=	--with-rhino=${PREFIX}/java/openjdk7/jre/lib/rhino.jar
BUILDLINK_API_DEPENDS.openjdk7+=openjdk7>=1.7.76nb3
.include "../../lang/openjdk7/buildlink3.mk"
.endif
CONFIGURE_ARGS+=	--disable-docs

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -if


INSTALLATION_DIRS+=		lib/netscape/plugins

post-install:
	cd ${DESTDIR}/${PREFIX}/lib/netscape/plugins && \
		${LN} -s ../../IcedTeaPlugin.so IcedTeaPlugin.so

.include "../../devel/xulrunner38/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
