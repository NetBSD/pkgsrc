# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:57 jlam Exp $
#

DISTNAME=	mod_transform-0.4.0
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_transform/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_transform/
COMMENT=	Filter module for Apache 2.0 to do dynamic XSL transformations

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
