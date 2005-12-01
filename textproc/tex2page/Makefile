# $NetBSD: Makefile,v 1.1.1.1 2005/12/01 18:50:14 gdt Exp $
#

DISTNAME=		tex2page
PKGNAME=		tex2page-20051023
CATEGORIES=		textproc
MASTER_SITES=		http://www.ccs.neu.edu/home/dorai/tex2page/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ccs.neu.edu/home/dorai/tex2page/
COMMENT=		SHORT_DESCRIPTION_OF_THE_PACKAGE

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--dialect=guile

do-build:

do-install:
	$(INSTALL_SCRIPT) ${WRKSRC}/my-tex2page $(PREFIX)/bin/tex2page

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
