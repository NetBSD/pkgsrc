# $NetBSD: Makefile,v 1.11 2019/12/06 19:04:13 markd Exp $

DISTNAME=	makeindex
PKGNAME=	tex-${DISTNAME}-2.15
PKGREVISION=	1
TEXLIVE_REV=	35872

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/makeindex
COMMENT=	Style files for makeindex

DEPENDS+=	makeindexk>=2.15:../../textproc/makeindexk

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
