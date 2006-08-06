# $NetBSD: Makefile,v 1.1.1.1 2006/08/06 17:37:52 wiz Exp $
#

DISTNAME=		trang-20030619
CATEGORIES=		textproc
MASTER_SITES=		http://www.thaiopensource.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/relaxng/trang.html
COMMENT=		Multi-format schema converter based on RELAX NG

DEPENDS+=		jing-[0-9]*:../../textproc/jing

USE_JAVA=		run
USE_JAVA2=		1.4

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/trang
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/trang/trang.jar"' "$$@"' >> ${WRKSRC}/trang

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/trang ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/trang
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${PREFIX}/libexec/trang
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/trang
	${INSTALL_DATA} ${WRKSRC}/copying.txt ${PREFIX}/share/doc/trang
	${INSTALL_DATA} ${WRKSRC}/trang-manual.html ${PREFIX}/share/doc/trang

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
