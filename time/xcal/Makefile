# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:22 wiz Exp $
#

DISTNAME=		xcal41
PKGNAME=		xcal-4.1
CATEGORIES=		x11 time
MASTER_SITES=		ftp://ftp.hillside.co.uk/xcal/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		kim@tac.nyc.ny.us

USE_IMAKE=		yes
#USE_XAW=		yes
#XAW_TYPE=		standard

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; for i in ../Part??; \
	do \
	    ${SED} -e '1,/--shar starts here--/d' $$i | ${SH} >/dev/null 2>&1; \
	done

.include "../../mk/bsd.pkg.mk"
