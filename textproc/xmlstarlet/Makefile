# $NetBSD: Makefile,v 1.26 2021/12/08 16:06:47 adam Exp $
#

DISTNAME=		xmlstarlet-1.6.1
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmlstar/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmlstar.sourceforge.net/
COMMENT=		Command line utilities for XML manipulation
LICENSE=		mit

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-libxslt-prefix=${BUILDLINK_PREFIX.libxslt}
PTHREAD_OPTS+=		require

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.12
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.9

TEST_TARGET=	check

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
