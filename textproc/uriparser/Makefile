# $NetBSD: Makefile,v 1.6 2012/08/23 15:09:18 drochner Exp $
#

DISTNAME=	uriparser-0.7.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uriparser/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uriparser.sourceforge.net/
COMMENT=	URI parsing library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-doc
USE_LIBTOOL=	yes
USE_FEATURES=	snprintf
PKGCONFIG_OVERRIDE+= liburiparser.pc.in
#TEST_TARGET=	check

.include "../../mk/bsd.fast.prefs.mk"

# needs "libcpptest" for test
#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
#USE_LANGUAGES=	c c++
#.else
CONFIGURE_ARGS+= --disable-test
#.endif

.include "../../mk/bsd.pkg.mk"
