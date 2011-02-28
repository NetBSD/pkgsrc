# $NetBSD: Makefile,v 1.5 2011/02/28 14:53:05 wiz Exp $
#

DISTNAME=	uriparser-0.7.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uriparser/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uriparser.sourceforge.net/
COMMENT=	URI parsing library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_FEATURES=	snprintf

TEST_TARGET=	check

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=	c c++
.endif

.include "../../mk/bsd.pkg.mk"
