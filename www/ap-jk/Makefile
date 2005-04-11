# $NetBSD: Makefile,v 1.27 2005/04/11 21:47:50 tv Exp $

DISTNAME=	jakarta-tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap-jk-${JK_VERSION}
JK_VERSION=	1.2.8
CATEGORIES=	www java
MASTER_SITES=	http://www.apache.org/dist/jakarta/tomcat-connectors/jk/source/jk-${JK_VERSION}/

MAINTAINER=	erh@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/tomcat/connectors-doc/
COMMENT=	Apache connector for accessing Jakarta Tomcat

WRKSRC=			${WRKDIR}/${DISTNAME}/jk/native
APACHE_MODULE=	YES
BUILD_DEFS+=	JK_ENABLE_JNI

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

SUBST_CLASSES+=		jk-lt
SUBST_STAGE.jk-lt=	post-configure
SUBST_FILES.jk-lt=	Makefile common/Makefile apache-2.0/Makefile
SUBST_SED.jk-lt=	-e "s|^\(LIBTOOL =\) [^ ]*$$|\1 \$$(SHELL) \$$(top_builddir)/libtool|g"
SUBST_MESSAGE.jk-lt=	"Fixing libtool references."

# XXX The standard --with-apxs2 when using apache2 doesn't work
CONFIGURE_ARGS+=	--with-apxs="${APXS}"

.if defined(JK_ENABLE_JNI)
USE_JAVA=	yes
CONFIGURE_ARGS+=	--enable-jni
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME}
SUBST_FILES.jk-lt+=	jni/Makefile
.endif

.include "../../mk/apache.mk"
.if defined(JK_ENABLE_JNI)
.include "../../mk/java-vm.mk"
.endif
.include "../../mk/bsd.pkg.mk"
