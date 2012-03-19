# $NetBSD: Makefile,v 1.1.1.1 2012/03/19 09:12:26 markd Exp $
#

DISTNAME=	raptor2-2.0.6
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librdf.org/raptor/
COMMENT=	RDF Parser Toolkit written in C
LICENSE=	gnu-lgpl-v2.1 OR apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	raptor2.pc.in
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
