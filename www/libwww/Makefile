# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:30 tsarna Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=	w3c-${PKGNAME}
PKGNAME=	libwww-5.1m1
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.w3.org/Library/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-zlib --with-regex --without-x
WRKSRC=		${WRKDIR}/w3c-libwww-5.1m

DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src

.include "../../mk/bsd.pkg.mk"
