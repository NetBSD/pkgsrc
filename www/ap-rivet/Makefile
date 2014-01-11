# $NetBSD: Makefile,v 1.12 2014/01/11 14:42:06 adam Exp $

DISTNAME=	rivet-0.5.0
PKGNAME=	ap13-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://apache.mirror99.com/tcl/rivet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcl.apache.org/rivet/
COMMENT=	System for creating dynamic web content via Tcl

CONFLICTS=	ap-rivet-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

#CONFIGURE_ARGS+=	-prefix ${PREFIX:Q}/lib
#CONFIGURE_ARGS+=	-with-apxs ${APXS:Q}
#CONFIGURE_ARGS+=	-with-tclconfig ${BUILDLINK_PREFIX.tcl:Q}/lib/tclConfig.sh

.include "../../lang/tcl/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

pre-install:
	set -e;								\
	cd ${WRKSRC:Q};							\
	for i in "*" "*/*" "*/*/*"; do					\
		eval ${RM:Q}" -rf $$i/CVS";				\
	done

.include "../../mk/bsd.pkg.mk"
