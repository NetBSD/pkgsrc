# $NetBSD: Makefile,v 1.4 2003/05/05 19:05:22 jmmv Exp $
#

DISTNAME=	subversion-0.20.1
PKGNAME=	${DISTNAME:S/^/ap2-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/3440/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://subversion.tigris.org/
COMMENT=	WebDAV server (Apache module) for Subversion

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

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
