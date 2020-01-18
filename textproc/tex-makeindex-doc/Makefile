# $NetBSD: Makefile,v 1.9 2020/01/18 23:35:34 rillig Exp $

DISTNAME=	makeindex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.15
TEXLIVE_REV=	35872

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/makeindex
COMMENT=	Documentation for tex-makeindex

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
