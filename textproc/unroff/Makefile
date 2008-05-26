# $NetBSD: Makefile,v 1.29 2008/05/26 02:13:24 joerg Exp $

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

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${LIBDIR}
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${INSTALL_PROGRAM} src/unroff ${PREFIX}/bin/unroff
	cd ${WRKSRC} && pax -wr scm ${LIBDIR}
	${INSTALL_DATA_DIR} ${LIBDIR}/doc
	cd ${WRKSRC} && ${INSTALL_DATA} doc/manual.ms ${LIBDIR}/doc
	${INSTALL_DATA_DIR} ${LIBDIR}/misc
	cd ${WRKSRC} && ${INSTALL_DATA} doc/tmac.hyper misc/sample.unroff ${LIBDIR}/misc
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${LIBDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} doc/*.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/elk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
