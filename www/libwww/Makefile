# $NetBSD: Makefile,v 1.8 2000/06/01 11:23:43 rh Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=	w3c-${PKGNAME}
PKGNAME=	libwww-5.2.8
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.w3.org/Library/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes
CONFIGURE_ARGS=	--with-zlib --with-regex --without-x

DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src

.include "../../mk/bsd.pkg.mk"
