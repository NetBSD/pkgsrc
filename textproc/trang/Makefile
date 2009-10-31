# $NetBSD: Makefile,v 1.3 2009/10/31 02:23:31 wiz Exp $
#

DISTNAME=		trang-20090818
CATEGORIES=		textproc
MASTER_SITES=		http://jing-trang.googlecode.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/relaxng/trang.html
COMMENT=		Multi-format schema converter based on RELAX NG
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		jing-[0-9]*:../../textproc/jing

USE_JAVA=		run
USE_JAVA2=		1.4

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/trang
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/trang/trang.jar"' "$$@"' >> ${WRKSRC}/trang

INSTALLATION_DIRS=	bin libexec/trang share/doc/trang

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/trang ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${DESTDIR}${PREFIX}/libexec/trang
	${INSTALL_DATA} ${WRKSRC}/copying.txt ${DESTDIR}${PREFIX}/share/doc/trang
	${INSTALL_DATA} ${WRKSRC}/trang-manual.html ${DESTDIR}${PREFIX}/share/doc/trang

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
