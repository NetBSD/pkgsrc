# $NetBSD: Makefile,v 1.13 2022/12/23 13:34:52 taca Exp $

DISTNAME=	bluecloth-2.2.0
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://deveiate.org/projects/BlueCloth
COMMENT=	Markdown library for Ruby
LICENSE=	original-bsd

USE_GCC_RUNTIME=	yes

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
