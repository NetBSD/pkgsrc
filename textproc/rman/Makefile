# $NetBSD: Makefile,v 1.20 2003/03/29 12:42:41 jmmv Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=	rman
PKGNAME=	rman-3.0.9
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	textproc
MASTER_SITES=	ftp://polyglot.sourceforge.net/pub/polyglotman/ \
		http://polyglotman.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://polyglotman.sourceforge.net/
COMMENT=	Produces HTML from formatted and unformatted man pages

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/bin/rman)
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

post-install:
	strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
