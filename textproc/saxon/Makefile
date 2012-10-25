# $NetBSD: Makefile,v 1.22 2012/10/25 06:57:00 asau Exp $
#

DISTNAME=	saxon
PKGNAME=	saxon-6.0.2
PKGREVISION=	3
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE}saxon6.0.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.breathe.com/mhkay/saxon/
COMMENT=	Michael H. Kay's Java XSLT processor

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
USE_JAVA=	run
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

post-extract:
	chmod -R u+w,go-w ${WRKSRC}

INSTALLATION_DIRS= lib/java share/doc/java share/examples/java/saxon

do-install:
	${INSTALL_DATA} ${WRKSRC}/saxon.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKSRC} && pax -rw -s '/^doc/saxon/' doc ${DESTDIR}${PREFIX}/share/doc/java
	cd ${WRKSRC} && pax -rw -s '/^samples/saxon/' samples ${DESTDIR}${PREFIX}/share/examples/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
