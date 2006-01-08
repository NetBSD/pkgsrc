# $NetBSD: Makefile,v 1.2 2006/01/08 21:17:17 agc Exp $
#

DISTNAME=		tex2page
PKGNAME=		tex2page-20051023
CATEGORIES=		textproc
MASTER_SITES=		http://www.ccs.neu.edu/home/dorai/tex2page/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ccs.neu.edu/home/dorai/tex2page/
COMMENT=		Converts TeX manuscripts into (HTML) web pages

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--dialect=guile

do-build:

do-install:
	$(INSTALL_SCRIPT) ${WRKSRC}/my-tex2page $(PREFIX)/bin/tex2page

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
