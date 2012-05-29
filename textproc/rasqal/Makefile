# $NetBSD: Makefile,v 1.15 2012/05/29 14:38:49 wiz Exp $

DISTNAME=	rasqal-0.9.29
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librdf.org/rasqal
COMMENT=	Library that handles RDF query syntaxes
LICENSE=	gnu-lgpl-v2.1 OR apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	rasqal.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
BUILDLINK_API_DEPENDS.raptor2+=	raptor2>=2.0.7
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
