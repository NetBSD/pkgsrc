# $NetBSD: Makefile,v 1.8 2006/04/17 13:46:49 wiz Exp $
#

DISTNAME=		tex2page
DIST_SUBDIR=		tex2page-20060131
PKGNAME=		tex2page-20060131
PKGREVISION=		3
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

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
