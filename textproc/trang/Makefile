# $NetBSD: Makefile,v 1.5 2025/07/14 08:38:15 pho Exp $
#

DISTNAME=		trang-20241231
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=relaxng/}
GITHUB_PROJECT=		jing-trang
GITHUB_RELEASE=		V${PKGVERSION_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://relaxng.org/jclark/
COMMENT=		Multi-format schema converter based on RELAX NG
LICENSE=		modified-bsd

DEPENDS+=		jing-[0-9]*:../../textproc/jing

USE_JAVA=		run
USE_JAVA2=		8

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
