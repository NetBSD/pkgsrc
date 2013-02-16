# $NetBSD: Makefile,v 1.23 2013/02/16 11:24:40 wiz Exp $
#

DISTNAME=		tex2page
DIST_SUBDIR=		tex2page-20060131
PKGNAME=		tex2page-20060131
PKGREVISION=		15
CATEGORIES=		textproc
MASTER_SITES=		http://www.ccs.neu.edu/home/dorai/tex2page/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ccs.neu.edu/home/dorai/tex2page/
COMMENT=		Converts TeX manuscripts into (HTML) web pages

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gs:run

CONFIGURE_ARGS+=	--dialect=guile

# build documentation
do-build:
	(cd ${WRKSRC} && ./my-tex2page tex2page-doc)
	(cd ${WRKSRC} && ./my-tex2page tex2page-doc)

INSTALLATION_DIRS=	bin share/doc//tex2page

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/my-tex2page ${DESTDIR}${PREFIX}/bin/tex2page
	${INSTALL} ${WRKSRC}/*.html ${WRKSRC}/*.gif ${DESTDIR}${PREFIX}/share/doc//tex2page

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../lang/guile16/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
