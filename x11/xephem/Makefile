# $NetBSD: Makefile,v 1.43 2006/07/21 14:27:56 jlam Exp $

DISTNAME=	xephem-3.7.1
PKGREVISION=	1
CATEGORIES=	x11
PKGREVISION=	1
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/
COMMENT=	Interactive astronomical ephemeris program

LICENSE=		xephem-license

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

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
USE_TOOLS+=	gmake perl:run
REPLACE_PERL+=	auxil/*.pl

LIBS.SunOS+=		-lnsl -lsocket
X11_LDFLAGS+=		${LIBS}
PKGSRC_MAKE_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	auxil/astorb2edb.pl auxil/mpcorb2edb.pl

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${PREFIX}/${PKGMANDIR}/man1/xephem.1
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/xephem/tools
	cd ${WRKSRC}; ${CP} -R auxil catalogs fifos fits gallery help lo \
		${PREFIX}/share/xephem
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/xephem

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
