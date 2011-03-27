# $NetBSD: Makefile,v 1.15 2011/03/27 09:16:58 obache Exp $

PKGNAME=	jakarta-tomcat4-${TOMCAT_VERSION}
DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}
PKGREVISION=			2
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	www java
MASTER_SITES=	http://archive.apache.org/dist/tomcat/tomcat-4/v${TOMCAT_VERSION}/bin/

MAINTAINER=	erh@NetBSD.org
HOMEPAGE=	http://tomcat.apache.org/
COMMENT=	The Apache Project's Java Servlet 2.3 and JSP 1.2 server

PKG_DESTDIR_SUPPORT=	user-destdir

TOMCAT_VERSION=	4.1.30

# This needs java 1.4 or higher.
USE_JAVA=run
USE_JAVA2=yes

USE_TOOLS+=	pax

TOMCAT_LIB=	${PREFIX}/tomcat4

SAMPLECONFDIR=			${TOMCAT_LIB}/conf
PKG_SYSCONFDIR.jakarta-tomcat4=	${SAMPLECONFDIR}

CFILES=		server.xml web.xml tomcat-users.xml
CFILES+=	catalina.policy jk2.properties

CONF_FILES=	# empty
.for FILE in ${CFILES}
CONF_FILES+=	${SAMPLECONFDIR}/${FILE}.default ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=	tomcat4

FILES_SUBST+=	JAVA_HOME=${PKG_JAVA_HOME:Q} TOMCAT_LIB=${TOMCAT_LIB:Q}

.include "../../mk/java-vm.mk"

do-build:
.for FILE in ${CFILES}
	${MV} -f ${WRKSRC}/conf/${FILE} ${WRKSRC}/conf/${FILE}.default
.endfor

INSTALLATION_DIRS=	${TOMCAT_LIB}

do-install:
	cd ${WRKSRC} && pax -rw -pm . ${DESTDIR}${TOMCAT_LIB}
	@${FIND} ${DESTDIR}${TOMCAT_LIB} -type f -print \
		| ${XARGS} ${CHMOD} a+r
	@${FIND} ${DESTDIR}${TOMCAT_LIB} \( -type f -o -perm -u+x \) -print \
		| ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DESTDIR}${TOMCAT_LIB} -type d -print \
		| ${XARGS} ${CHMOD} a+rx

.include "../../mk/bsd.pkg.mk"
