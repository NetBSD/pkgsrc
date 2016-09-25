# $NetBSD: Makefile,v 1.9 2016/09/25 21:13:09 wiz Exp $

DISTNAME=	dateutils-0.4.0
CATEGORIES=	time
#MASTER_SITES=	${MASTER_SITE_GITHUB:=hroptatyr/}
MASTER_SITES+=	https://bitbucket.org/hroptatyr/dateutils/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fresse.org/dateutils/
COMMENT=	Command line tools for working with dates
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake makeinfo bison flex
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE= no

INFO_FILES=		yes
TEST_TARGET=		check
INCLUDEDIR=		include/${PKGBASE}
AUTO_MKDIRS=		YES

post-build:
	(cd ${WRKSRC}/lib; ${GMAKE})

post-install:
	(cd ${WRKSRC}/lib; \
	env DESTDIR=${DESTDIR} ${GMAKE} install-libLIBRARIES)
# To have the similar PLIST of previous version, installing headers.
.for i in \
	boops.h \
	date-core-strpf.h \
	date-core.h \
	dt-core-strpf.h \
	dt-core-tz-glue.h \
	dt-core.h \
	generics.h \
	gmtime.h \
	leaps.h \
	leapseconds.def \
	leapseconds.h \
	nifty.h \
	strops.h \
	time-core-strpf.h \
	time-core.h \
	token.h \
	tzmap.h \
	tzraw.h \
	version.h
	(cd ${WRKSRC}/lib; ${INSTALL_DATA} ${i} ${DESTDIR}${PREFIX}/${INCLUDEDIR})
.endfor

.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
