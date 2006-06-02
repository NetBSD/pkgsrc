# $NetBSD: Makefile,v 1.6 2006/06/02 18:27:59 joerg Exp $

DISTNAME=	rivet_0.4.0-1
PKGNAME=	ap13-rivet-0.4.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=tcl/rivet/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tcl.apache.org/rivet/
COMMENT=	System for creating dynamic web content via Tcl

CONFLICTS=	ap-rivet-[0-9]*

WRKSRC=		${WRKDIR}/tcl-rivet
HAS_CONFIGURE=	yes
CONFIGURE_DIRS=	src

CONFIGURE_ENV+=		LANG=C
CONFIGURE_SCRIPT=	./configure.tcl
CONFIGURE_ARGS+=	-prefix ${PREFIX:Q}/lib
CONFIGURE_ARGS+=	-with-apxs ${APXS:Q}
CONFIGURE_ARGS+=	-with-tclconfig ${BUILDLINK_PREFIX.tcl:Q}/lib/tclConfig.sh

.include "../../lang/tcl/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

pre-install:
	set -e;								\
	cd ${WRKSRC:Q};							\
	for i in "*" "*/*" "*/*/*"; do					\
		eval ${RM:Q}" -rf $$i/.OLDEntries $$i/CVS";		\
	done

do-install:
	cd ${WRKSRC:Q}/src && ./make.tcl install

.include "../../mk/bsd.pkg.mk"
