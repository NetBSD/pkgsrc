# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:29 tsarna Exp $
# FreeBSD Id: Makefile,v 1.6 1997/04/27 00:11:48 asami Exp
#

DISTNAME=	unroff-1.0
PKGNAME=	unroff-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	${UNROFF_SITE}/dist/ \
		${UNROFF_SITE}/contrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PATCH1} ${PATCH2}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-rn.informatik.uni-bremen.de/software/unroff/

RUN_DEPENDS=	elk:../../lang/elk
BUILD_DEPENDS=	elk:../../lang/elk

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	unroff

UNROFF_SITE=	http://www-rn.informatik.uni-bremen.de/software/unroff
PATCH1=		me-misc-patch
PATCH2=		misc-patch-2

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch ${PATCH1}" ; \
		fi; \
		${PATCH} ${PATCH_DIST_ARGS} -p0 < ${PATCH1}; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch ${PATCH2}" ; \
		fi; \
		${PATCH} ${PATCH_DIST_ARGS} -p1 < ${PATCH2})

post-patch:
	@(cd ${WRKSRC} && find . -name '*.orig' -print | xargs rm -f)

.include "../../mk/bsd.pkg.mk"
