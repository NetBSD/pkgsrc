# $NetBSD: Makefile,v 1.3 1998/07/14 17:12:35 tv Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=	w3c-${PKGNAME}
PKGNAME=	libwww-5.1m1
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	tv@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-zlib --with-regex --without-x
CONFIGURE_ENV=	LIBTOOL=${PREFIX}/bin/libtool
WRKSRC=		${WRKDIR}/w3c-libwww-5.1m

DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src

.include "../../mk/bsd.pkg.mk"
