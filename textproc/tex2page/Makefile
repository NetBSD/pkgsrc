# $NetBSD: Makefile,v 1.5 2006/02/25 17:48:24 gdt Exp $
#

DISTNAME=		tex2page
PKGNAME=		tex2page-20060131
CATEGORIES=		textproc
MASTER_SITES=		http://www.ccs.neu.edu/home/dorai/tex2page/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ccs.neu.edu/home/dorai/tex2page/
COMMENT=		Converts TeX manuscripts into (HTML) web pages

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--dialect=guile

do-build:
	# build documentation
	(cd ${WRKSRC} && ./my-tex2page tex2page-doc)
	(cd ${WRKSRC} && ./my-tex2page tex2page-doc)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/my-tex2page ${PREFIX}/bin/tex2page
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc//tex2page
	${INSTALL} ${WRKSRC}/*.html ${WRKSRC}/*.gif ${PREFIX}/share/doc//tex2page

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
