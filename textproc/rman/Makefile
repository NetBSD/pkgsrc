# $NetBSD: Makefile,v 1.25 2005/03/24 21:13:02 wiz Exp $

DISTNAME=	rman
PKGNAME=	rman-3.0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://polyglot.sourceforge.net/pub/polyglotman/ \
		http://polyglotman.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://polyglotman.sourceforge.net/
COMMENT=	Produces HTML from formatted and unformatted man pages

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/bin/rman)
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

post-install:
	strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
