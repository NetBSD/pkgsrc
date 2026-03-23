# $NetBSD: Makefile,v 1.79 2026/03/23 10:12:16 nia Exp $

VERSION=	4.2.0
DISTNAME=	XEphem-${VERSION}
PKGNAME=	xephem-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=XEphem/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/XEphem/XEphem
COMMENT=	Interactive astronomical ephemeris program
LICENSE=	mit

# License was previously xephem-licenes (boutique, almost free). Do not
# delete this comment; I will do so eventually when licensing is 100%
# resolved.
#
# From: "Elwood C. Downey" <ecdowney@clearskyinstitute.com>
# Subject: Re: license terms, tarball mirroring, binary packages
# To: "Greg Troxel" <gdt@ir.bbn.com>
# Date: Wed, 10 May 2006 18:41:01 -0600 (MDT)
# [rest omitted]
# In the mean time, please consider this email to grant permissions for
# the NetBSD distros to make available both through online download and
# physical media both the original XEphem tarball and a binary built
# from the original tarball (including possible changes for porting but
# not changes in functionality).

# old-school makefile with no synchronization
# (not reported upstream because a bug report today would be disrespectful)
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME}/GUI/xephem
USE_TOOLS+=		gmake pax perl:run

X11_LDFLAGS+=		${LIBS}
MAKE_ENV+=		X11_LDFLAGS=${X11_LDFLAGS:Q}

LDFLAGS.SunOS+=		-lnsl -lsocket

# \todo Evaluate and perhaps modernize this section.
REPLACE_PERL+=		auxil/*.pl

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	auxil/astorb2edb.pl auxil/mpcorb2edb.pl

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/xephem/tools \
			${PKGMANDIR}/man1

# xephem looks for app-defaults in hardcoded/wrong places
SUBST_CLASSES+=		ad
SUBST_VARS.ad=		PREFIX
SUBST_FILES.ad=		tools/xedb/xedb.c
SUBST_STAGE.ad=		post-configure
SUBST_MESSAGE.ad=	Fixing path to x11 app-defaults in xedb.c.

# \todo Make this respect user ShareDir config also.
SUBST_CLASSES+=		homeio
SUBST_SED.homeio=	-e "s,@SHAREDIR@,${PREFIX}/share/xephem,"
SUBST_FILES.homeio=	homeio.c
SUBST_STAGE.homeio=	post-configure
SUBST_MESSAGE.homeio=	Fixing path to x11 app-defaults in homeio.c.

post-extract:
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xephem.1
	${INSTALL_DATA} ${WRKDIR}/XEphem ${DESTDIR}${PREFIX}/lib/X11/app-defaults
	cd ${WRKSRC}; pax -rw auxil catalogs fifos fits gallery help lo \
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
