# $NetBSD: Makefile,v 1.5 2001/05/22 09:32:27 wiz Exp $
# FreeBSD Id: ports/x11-toolkits/fox/Makefile,v 1.14 2001/02/23 19:00:05 knu Exp

DISTNAME=	fox-0.99.167
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.cfdrc.com/FOX/fox.html
COMMENT=	Fast and extensive C++ GUI toolkit

DEPENDS+=	jpeg-*:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

.if !defined(USE_XUNICODE) || ${USE_XUNICODE} == "YES"

MASTER_SITES+=	http://www.ab.wakwak.com/~tino/jatk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xunicode-0.3.2${EXTRACT_SUFX}

PATCH_SITES=	http://www.ab.wakwak.com/~tino/jatk/fox/
PATCHFILES=	${DISTNAME:C/-/-unicode-/}.diff
PATCH_DIST_STRIP=-p1

CPPFLAGS+=	-I..
X_CFLAGS=	-DUSE_XUNICODE
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" X_CFLAGS="${X_CFLAGS}"

.endif

USE_X11BASE=	# defined
USE_MESA=	# defined
USE_LIBTOOL=	# defined
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-opengl=mesa --with-x --with-shm=yes --enable-release

.include "../../mk/bsd.pkg.mk"
