# $NetBSD: Makefile,v 1.35 2002/08/07 15:56:22 fredb Exp $

DISTNAME=		w3c-libwww-5.3.2
PKGNAME=		libwww-5.3.2
PKGREVISION=		3
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl="${BUILDLINK_PREFIX.openssl}"

DOCDIR=			${PREFIX}/share/doc/libwww
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

pre-configure:
	cd ${WRKSRC}; \
	    ${LOCALBASE}/bin/aclocal && \
	    ${LOCALBASE}/bin/automake && \
	    ${LOCALBASE}/bin/autoconf

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
