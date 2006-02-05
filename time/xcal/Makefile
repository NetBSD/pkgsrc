# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:11 joerg Exp $
#

DISTNAME=		xcal41
PKGNAME=		xcal-4.1
PKGREVISION=		2
CATEGORIES=		x11 time
MASTER_SITES=		ftp://ftp.hillside.co.uk/xcal/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Calendar with alarms and a notebook for X11

USE_IMAKE=		yes

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; for i in ../Part??; \
	do \
	    ${SED} -e '1,/--shar starts here--/d' $$i | ${SH} >/dev/null 2>&1; \
	done

.include "../../mk/bsd.pkg.mk"
