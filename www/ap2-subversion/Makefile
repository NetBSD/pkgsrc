# $NetBSD: Makefile,v 1.1.1.1 2003/02/03 20:24:13 drochner Exp $

DISTNAME=	subversion-r4503
PKGNAME=	ap2-subversion-0.17.1
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/2699/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://subversion.tigris.org/
COMMENT=	WebDAV server (Apache module) for Subversion

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= \
  --with-berkeley-db=${BUILDLINK_PREFIX.db4}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+= --with-apxs=${APXS}
CONFIGURE_ARGS+= --disable-mod-activation
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
SHLIBTOOL_OVERRIDE= ${WRKSRC}/libtool

APACHE_MODULE=	YES

ALL_TARGET=	apache-mod
INSTALL_TARGET=	install-mods-shared

post-extract:
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

.include "../../devel/subversion/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
