# $NetBSD: Makefile,v 1.21 2005/03/24 21:13:02 wiz Exp $

DISTNAME=		unroff-1.0
PKGNAME=		unroff-1.0.2
CATEGORIES=		textproc
MASTER_SITES=		${UNROFF_SITE}/dist/ \
			${UNROFF_SITE}/contrib/

PATCHFILES=		${PATCH1} ${PATCH2}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/unroff/
COMMENT=		Programmable troff translator with backend for HTML

DEPENDS=		elk>=3.0.2:../../lang/elk

DIST_SUBDIR=		unroff

UNROFF_SITE=		http://www-rn.informatik.uni-bremen.de/software/unroff
PATCH1=			me-misc-patch
PATCH2=			misc-patch-2

post-patch:
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig' -print | ${XARGS} ${RM} -f)
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig_dist' -print | ${XARGS} ${RM} -f)

.include "../../mk/bsd.pkg.mk"
