# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:43 wiz Exp $
#

DISTNAME=	mod_transform-0.4.0
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_transform/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_transform/
COMMENT=	Filter module for Apache 2.0 to do dynamic XSL transformations

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
