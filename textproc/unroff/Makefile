# $NetBSD: Makefile,v 1.31 2012/10/25 06:57:05 asau Exp $

DISTNAME=		unroff-1.0
PKGNAME=		unroff-1.0.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www-rn.informatik.uni-bremen.de/software/unroff/dist/

PATCHFILES=		me-misc-patch misc-patch-2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/unroff/
COMMENT=		Programmable troff translator with backend for HTML

DIST_SUBDIR=		unroff

USE_TOOLS+=	pax

CFLAGS+=		-DBSD
BUILD_DIRS=		src

post-patch:
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig' -print | ${XARGS} ${RM} -f)
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig_dist' -print | ${XARGS} ${RM} -f)

LIBDIR=		${PREFIX}/share/unroff

INSTALLATION_DIRS=	bin ${LIBDIR}/doc ${LIBDIR}/misc ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} src/unroff ${DESTDIR}${PREFIX}/bin/unroff
	cd ${WRKSRC} && pax -wr scm ${DESTDIR}${LIBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} doc/manual.ms ${DESTDIR}${LIBDIR}/doc
	cd ${WRKSRC} && ${INSTALL_DATA} doc/tmac.hyper misc/sample.unroff ${DESTDIR}${LIBDIR}/misc
	cd ${WRKSRC} && ${INSTALL_MAN} doc/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/elk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
