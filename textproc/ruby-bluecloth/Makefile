# $NetBSD: Makefile,v 1.10 2017/09/04 18:08:29 wiz Exp $

DISTNAME=	bluecloth-2.2.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://deveiate.org/projects/BlueCloth
COMMENT=	Markdown library for Ruby
LICENSE=	original-bsd

CONFLICTS+=	ruby[1-9][0-9]-bluecloth-[0-9]*

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
