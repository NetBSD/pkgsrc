# $NetBSD: Makefile,v 1.24 2006/01/04 04:29:08 schmonz Exp $

DISTNAME=		unroff-1.0
PKGNAME=		unroff-1.0.2
CATEGORIES=		textproc
MASTER_SITES=		http://www-rn.informatik.uni-bremen.de/software/unroff/dist/ \
			http://www-rn.informatik.uni-bremen.de/software/unroff/contrib/

PATCHFILES=		me-misc-patch misc-patch-2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/unroff/
COMMENT=		Programmable troff translator with backend for HTML

BROKEN_IN=		pkgsrc-2005Q4

DIST_SUBDIR=		unroff

post-patch:
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig' -print | ${XARGS} ${RM} -f)
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig_dist' -print | ${XARGS} ${RM} -f)

.include "../../lang/elk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
