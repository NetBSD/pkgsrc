# $NetBSD: Makefile,v 1.46 2020/11/05 09:07:11 ryoon Exp $

DISTNAME=	rasqal-0.9.33
PKGREVISION=	20
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librdf.org/rasqal
COMMENT=	Library that handles RDF query syntaxes
LICENSE=	gnu-lgpl-v2.1 OR apache-2.0

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	rasqal.pc.in

# XXX: Kludge to avoid uncoditionally pick up some gtkdoc-* tools if gtk-doc
# XXX: package is installed and then fails in the installation phase.
CONFIGURE_ENV+=		ac_cv_path_GTKDOC_CHECK= \
			ac_cv_path_GTKDOC_REBASE= \
			ac_cv_path_GTKDOC_MKPDF=

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
BUILDLINK_API_DEPENDS.raptor2+=	raptor2>=2.0.7
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
