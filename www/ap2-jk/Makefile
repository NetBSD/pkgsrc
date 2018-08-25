# $NetBSD: Makefile,v 1.11.4.2 2018/08/25 01:53:50 manu Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	${APACHE_PKG_PREFIX}-jk-${JK_VERSION}
JK_VERSION=	1.2.37
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE:=tomcat/tomcat-connectors/jk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tomcat.apache.org/connectors-doc/
COMMENT=	Apache connector for accessing Jakarta Tomcat
LICENSE=	apache-2.0

CONFLICTS=	ap-jk-[0-9]*

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${PREFIX}/share/httpd/build/instdso.sh \
	    SH_LIBTOOL=${PREFIX}/share/httpd/build/libtool \
	    ${WRKSRC}/apache-2.0/mod_jk.la \
	    ${DESTDIR}${PREFIX}/lib/httpd

WRKSRC=		${WRKDIR}/${DISTNAME}/native
APACHE_MODULE=	YES
BUILD_DEFS+=	JK_ENABLE_JNI

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
OVERRIDE_DIRDEPTH=	3

SUBST_CLASSES+=		jk-lt
SUBST_STAGE.jk-lt=	post-configure
SUBST_FILES.jk-lt=	Makefile common/Makefile apache-2.0/Makefile
SUBST_SED.jk-lt=	-e "s|^\\(LIBTOOL =\\) [^ ]*\$$|\\1 \$$(SHELL) \$$(top_builddir)/libtool|g"
SUBST_MESSAGE.jk-lt=	Fixing libtool references.

# XXX The standard --with-apxs2 when using apache2 doesn't work
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}

.if defined(JK_ENABLE_JNI)
USE_JAVA=	yes
CONFIGURE_ARGS+=	--enable-jni
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME:Q}
SUBST_FILES.jk-lt+=	jni/Makefile
.endif

.if defined(JK_ENABLE_JNI)
.include "../../mk/java-vm.mk"
.endif

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
