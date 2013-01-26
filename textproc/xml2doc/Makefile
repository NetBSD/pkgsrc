# $NetBSD: Makefile,v 1.19 2013/01/26 21:38:56 adam Exp $
#

DISTNAME=	xml2doc-20030510
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	http://xml2doc.sourceforge.net/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml2doc.sourceforge.net/
COMMENT=	Xml to document formats converter

WRKSRC=			${WRKDIR}/xml2doc
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CFLAGS+=	-I${BUILDLINK_PREFIX.libxml2}/include/libxml2
CFLAGS+=	-I${BUILDLINK_PREFIX.pdflib}/include
LDFLAGS+=	-L${BUILDLINK_PREFIX.libxml2}/lib
LDFLAGS+=	-L${BUILDLINK_PREFIX.pdflib}/lib

.include "../../print/pdflib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
