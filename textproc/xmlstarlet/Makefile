# $NetBSD: Makefile,v 1.19 2014/01/01 11:52:36 wiz Exp $
#

DISTNAME=		xmlstarlet-1.3.1
PKGREVISION=		2
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

INSTALLATION_DIRS+=	share/doc/xmlstarlet

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xmlstarlet-ug.pdf ${DESTDIR}${PREFIX}/share/doc/xmlstarlet
	${INSTALL_DATA} ${WRKSRC}/doc/xmlstarlet.txt ${DESTDIR}${PREFIX}/share/doc/xmlstarlet


.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
