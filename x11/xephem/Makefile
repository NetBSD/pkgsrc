# $NetBSD: Makefile,v 1.85 2026/06/28 00:51:58 gdt Exp $

VERSION=	4.2.0
PKGREVISION=	2
DISTNAME=	XEphem-${VERSION}
PKGNAME=	xephem-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=XEphem/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/XEphem/XEphem
COMMENT=	Interactive astronomical ephemeris program
LICENSE=	mit

# There are still ctype(3) problems.
# \todo Redo patch from https://github.com/XEphem/XEphem/pull/126

# old-school makefile with no synchronization
# (not reported upstream because a bug report today would be disrespectful)
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME}
BUILD_DIRS=		GUI/xephem

USE_TOOLS+=		gmake pax perl:run

X11_LDFLAGS+=		${LIBS}
MAKE_ENV+=		X11_LDFLAGS=${X11_LDFLAGS:Q}

LDFLAGS.SunOS+=		-lnsl -lsocket

# \todo Evaluate and perhaps modernize this section.
REPLACE_PERL+=		${BUILD_DIRS}/auxil/*.pl

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	auxil/astorb2edb.pl auxil/mpcorb2edb.pl

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/xephem/tools \
			${PKGMANDIR}/man1

# xephem looks for app-defaults in hardcoded/wrong places
SUBST_CLASSES+=		ad
SUBST_VARS.ad=		PREFIX
SUBST_FILES.ad=		${BUILD_DIRS}/tools/xedb/xedb.c
SUBST_STAGE.ad=		post-configure
SUBST_MESSAGE.ad=	Fixing path to x11 app-defaults in xedb.c.

# \todo Make this respect user ShareDir config also.
SUBST_CLASSES+=		homeio
SUBST_SED.homeio=	-e "s,@SHAREDIR@,${PREFIX}/share/xephem,"
SUBST_FILES.homeio=	${BUILD_DIRS}/homeio.c
SUBST_STAGE.homeio=	post-configure
SUBST_MESSAGE.homeio=	Fixing path to x11 app-defaults in homeio.c.

post-extract:
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/xephem ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${BUILD_DIRS}/xephem.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xephem.1
	${INSTALL_DATA} ${WRKDIR}/XEphem ${DESTDIR}${PREFIX}/lib/X11/app-defaults
	cd ${WRKSRC}/${BUILD_DIRS}; pax -rw auxil catalogs fifos fits gallery help lo \
		${DESTDIR}${PREFIX}/share/xephem
	${RM} -f ${DESTDIR}${PREFIX}/share/xephem/*/._*
	${CHOWN} -R ${SHAREOWN} ${DESTDIR}${PREFIX}/share/xephem

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
