# $NetBSD: Makefile,v 1.74 2024/09/21 13:28:43 gdt Exp $

DISTNAME=	xephem-3.7.7
CATEGORIES=	x11
# New MASTER_SITES is:
# https://github.com/XEphem/XEphem/archive/refs/tags/4.2.0.tar.gz
MASTER_SITES=	http://97.74.56.125/free/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.clearskyinstitute.com/
#HOMEPAGE+=	https://github.com/XEphem/XEphem
COMMENT=	Interactive astronomical ephemeris program
# 4.2.0 appears to be mit-license
LICENSE=	xephem-license

# Pending adjustment of license wording to clarify the copyright
# holder's intent, permission has been granted to distribute the
# distfile and binary packages without functional changes.
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

# uses built libpng without synchronization
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
USE_TOOLS+=	gmake pax perl:run
REPLACE_PERL+=	auxil/*.pl

LIBS.SunOS+=		-lnsl -lsocket
X11_LDFLAGS+=		${LIBS}
MAKE_ENV+=		X11_LDFLAGS=${X11_LDFLAGS:Q}

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	auxil/astorb2edb.pl auxil/mpcorb2edb.pl

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/xephem/tools \
			${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xephem.1
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${DESTDIR}${PREFIX}/lib/X11/app-defaults
	cd ${WRKSRC}; pax -rw auxil catalogs fifos fits gallery help lo \
		${DESTDIR}${PREFIX}/share/xephem
	${RM} -f ${DESTDIR}${PREFIX}/share/xephem/*/._*
	${CHOWN} -R ${SHAREOWN} ${DESTDIR}${PREFIX}/share/xephem

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
