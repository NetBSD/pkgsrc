# $NetBSD: Makefile,v 1.48 2023/11/08 13:21:08 wiz Exp $

DISTNAME=	raptor2-2.0.16
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librdf.org/raptor/
COMMENT=	RDF Parser Toolkit written in C
LICENSE=	gnu-lgpl-v2.1 OR apache-2.0

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFLICTS=	raptor-[0-9]*

PKGCONFIG_OVERRIDE+=	raptor2.pc.in
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
