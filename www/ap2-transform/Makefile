# $NetBSD: Makefile,v 1.7 2005/07/21 16:29:59 wiz Exp $
#

DISTNAME=	mod_transform-0.4.0
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_transform/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_transform/
COMMENT=	Filter module for Apache 2.0 to do dynamic XSL transformations

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-apxs=${APXS}

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
