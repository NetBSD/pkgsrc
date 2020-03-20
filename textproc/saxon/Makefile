# $NetBSD: Makefile,v 1.28 2020/03/20 11:58:29 nia Exp $

DISTNAME=	SaxonHE9-5-0-1J
PKGNAME=	${DISTNAME:tl:S/-/./g:S/he/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=saxon/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saxon.sourceforge.net/
COMMENT=	Michael H. Kay's Java XSLT processor
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	1.5
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/saxon9he.jar ${DESTDIR}${PREFIX}/lib/java/saxon.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
