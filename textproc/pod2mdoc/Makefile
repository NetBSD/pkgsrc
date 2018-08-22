# $NetBSD: Makefile,v 1.13 2018/08/22 09:47:12 wiz Exp $

DISTNAME=	pod2mdoc-0.2
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/pod2mdoc/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mdocml.bsd.lv/pod2mdoc/
COMMENT=	Convert perl documentation (POD) into man pages (mdoc)
LICENSE=	isc

BUILD_TARGET=	pod2mdoc

INSTALLATION_DIRS=	bin	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pod2mdoc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pod2mdoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

CPPFLAGS.NetBSD+=	-DHAVE_OHASH=0

.include "../../mk/bsd.pkg.mk"
