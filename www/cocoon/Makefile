# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 21:55:15 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xerces-J,
# because although Xerces runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	Cocoon-1.7.4
PKGNAME=	cocoon-1.7.4
CATEGORIES=	www
MASTER_SITES=	http://xml.apache.org/dist/cocoon/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/cocoon/

DEPENDS+=	xalan-j-*:../../textproc/xalan-j
DEPENDS+=	fop-*:../../textproc/fop
DEPENDS+=	jakarta-tomcat-*:../../www/jakarta-tomcat

# In addition to the above requirements, cocoon will build in support for the
# following if they are in ${CLASSPATH}
#
# org.apache.cocoon.transformer.XTTransformer ===> pkgsrc/textproc/xt
#
# org.apache.cocoon.processor.ldap.LdapProcessor ===>
#	Sun JNDI API 1.2.1+ (http://java.sun.com/products/jndi/index.html)
#
# org.apache.cocoon.processor.dcp.DCPProcessor ===>
#	FESI 1.21+ (http://home.worldcom.ch/jmlugrin/fesi/download.html)

WRKSRC=		${WRKDIR}/${PKGNAME}
NO_PATCH=
NO_CONFIGURE=

USE_JAVA=	yes
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-extract:
	${RM} ${WRKSRC}/lib/fop_0_12_1.jar ${WRKSRC}/lib/servlet_2_2.jar \
		${WRKSRC}/lib/xalan_1_0_1.jar ${WRKSRC}/lib/xerces_1_0_3.jar
	${SED} -e s,@PREFIX@,${PREFIX},g < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

# Yes -- you have to run build.sh _twice_.  The first time triggers a bug in JDK-1.1 javac,
# and the second time completes successfully.  While we're at it, note that we can't
# rebuild the javadoc documentation, and have to use that which it shipped with, as the
# javadoc target requires StyleBook, which uses features of JDK 1.2
do-build:
	@${ECHO} "------------------------------------------------------------------------"
	@${ECHO} "  Please ignore any compiler errors during this build.  They are"
	@${ECHO} "              handled properly by the build process"
	@${ECHO} "------------------------------------------------------------------------"
	-(cd ${WRKSRC} && ${SH} build.sh)
	cd ${WRKSRC} && ${SH} build.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/cocoon.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/cocoon
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/cocoon ; ${GTAR} pvxf - )
	${MKDIR} ${PREFIX}/share/examples/java/cocoon/WEB-INF
	${INSTALL_DATA} ${FILESDIR}/web.xml ${PREFIX}/share/examples/java/cocoon/WEB-INF
	${INSTALL_DATA} ${WRKSRC}/conf/cocoon.properties ${PREFIX}/share/examples/java/cocoon/WEB-INF
	cd ${WRKSRC}/samples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/cocoon ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"

CLASSPATH:=${CLASSPATH}:${LOCALBASE}/lib/java/fop.jar:${LOCALBASE}/lib/java/xalan.jar:${LOCALBASE}/lib/java/xerces.jar:${LOCALBASE}/jakarta/tomcat/lib/servlet.jar
