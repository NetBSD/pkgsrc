# $NetBSD: Makefile,v 1.18 2001/05/03 13:53:10 jlam Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=	rman
PKGNAME=	rman-3.0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://polyglot.sourceforge.net/pub/polyglotman/ \
		http://polyglotman.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://polyglotman.sourceforge.net/
COMMENT=	Produces HTML from formatted and unformatted man pages

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/bin/rman)
IGNORE=		"Rosetta Man is included in your X distribution."
.endif

post-install:
	strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
