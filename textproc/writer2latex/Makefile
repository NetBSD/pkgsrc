# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=	${W2L}beta2
PKGNAME=	writer2latex-0.4b2
CATEGORIES=	textproc
MASTER_SITES=	http://www.hj-gym.dk/~hj/writer2latex/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hj-gym.dk/~hj/writer2latex/
COMMENT=	Convert OpenOffice.org/StarOffice documents to LaTeX and other formats

WRKSRC=		${WRKDIR}/${W2L}
USE_JAVA2=	yes
USE_JAVA=	run

W2L=		writer2latex04
W2LPATH=	${PREFIX}/share/${W2L}

INSTALLATION_DIRS=	bin

do-configure:
.for scr in w2l
	${SED}	-e 's|^\(java\)|${PKG_JAVA_HOME}/bin/\1|'		\
		-e 's|^\(W2LPATH\).*|\1="${W2LPATH}"|'			\
		-e 's|bash|sh|g'					\
		< ${WRKSRC}/${scr} > ${WRKSRC}/${scr}.new
	${MV} ${WRKSRC}/${scr}.new ${WRKSRC}/${scr}
.endfor

do-build:
	${RM} -rf ${WRKSRC}/source

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/w2l ${PREFIX}/bin/w2l
	${INSTALL_DATA_DIR} ${W2LPATH}
	${CP} -R ${WRKSRC}/* ${W2LPATH}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
