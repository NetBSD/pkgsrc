# $NetBSD: Makefile,v 1.1 2015/02/25 15:32:19 wiz Exp $

DISTNAME=	texi2mdoc-0.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/texi2mdoc/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mdocml.bsd.lv/texi2mdoc/
COMMENT=	Convert texinfo documentation (texi) into man pages (mdoc)
LICENSE=	isc

BUILD_TARGET=	texi2mdoc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texi2mdoc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/texi2mdoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
