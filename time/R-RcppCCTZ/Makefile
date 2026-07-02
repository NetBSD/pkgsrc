# $NetBSD: Makefile,v 1.6 2026/07/02 16:01:48 mef Exp $

R_PKGNAME=	RcppCCTZ
R_PKGVER=	0.2.14
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	'Rcpp' Bindings for the 'CCTZ' Library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=		c c++
# only for patch-src_Makevars
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux && ${OPSYS} != Darwin
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif

# https://mail-index.netbsd.org/pkgsrc-users/2025/01/02/msg040775.html
# See
#   /usr/include/wchar.h
#   /usr/pkg/gcc7/lib/gcc/x86_64--netbsd/7.5.0/include-fixed/wchar.h
.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 090900
CWRAPPERS_APPEND.cxx=	-D_NETBSD_SOURCE
.  endif
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
