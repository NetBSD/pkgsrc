# $NetBSD: Makefile,v 1.3 2002/09/01 18:58:52 jlam Exp $
#

DISTNAME=		xcal41
PKGNAME=		xcal-4.1
CATEGORIES=		x11 time
MASTER_SITES=		ftp://ftp.hillside.co.uk/xcal/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		calendar with alarms and a notebook for X11

USE_BUILDLINK2=		yes
USE_IMAKE=		yes

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; for i in ../Part??; \
	do \
	    ${SED} -e '1,/--shar starts here--/d' $$i | ${SH} >/dev/null 2>&1; \
	done

.include "../../mk/bsd.pkg.mk"
