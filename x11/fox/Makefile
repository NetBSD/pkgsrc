# $NetBSD: Makefile,v 1.8 2001/08/05 17:04:21 sakamoto Exp $
# FreeBSD Id: ports/x11-toolkits/fox/Makefile,v 1.14 2001/02/23 19:00:05 knu Exp

DISTNAME=	fox-0.99.174
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.cfdrc.com/FOX/fox.html
COMMENT=	Fast and extensive C++ GUI toolkit

.if !defined(FOX_USE_XUNICODE) || ${FOX_USE_XUNICODE} == "YES"

MASTER_SITES+=	http://www.ab.wakwak.com/~tino/jatk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xunicode-0.3.3${EXTRACT_SUFX}

PATCH_SITES=	http://www.ab.wakwak.com/~tino/jatk/fox/
PATCHFILES=	${DISTNAME:C/-/-unicode-/}.diff
PATCH_DIST_STRIP=-p1

CPPFLAGS+=	-I..
X_CFLAGS=	-DUSE_UNICODE
CONFIGURE_ENV+=	X_CFLAGS="${X_CFLAGS}"

.endif

USE_X11BASE=	# defined
USE_LIBTOOL=	# defined
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-opengl=mesa --with-x --with-shm=yes --enable-release

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
