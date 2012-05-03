# $NetBSD: Makefile,v 1.12 2012/05/03 09:55:32 obache Exp $
#

DISTNAME=		xcal41
PKGNAME=		xcal-4.1
PKGREVISION=		4
CATEGORIES=		x11 time
MASTER_SITES=		ftp://ftp.hillside.co.uk/xcal/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Calendar with alarms and a notebook for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		yes

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; for i in ../Part??; \
	do \
	    ${SED} -e '1,/--shar starts here--/d' $$i | ${SH} >/dev/null 2>&1; \
	done

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
