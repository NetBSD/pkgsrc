# $NetBSD: Makefile,v 1.73 2024/03/11 21:16:01 wiz Exp $

DISTNAME=	pdfgrep-2.1.2
PKGREVISION=	27
CATEGORIES=	textproc
MASTER_SITES=	https://pdfgrep.org/download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pdfgrep.org/
COMMENT=	Pdfgrep is a tool to search text in PDF files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++ c
USE_TOOLS+=	gmake pkg-config

.include "../../devel/pcre/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
