# $NetBSD: Makefile,v 1.8 2014/03/13 11:08:52 jperkin Exp $

DISTNAME=	bluecloth-2.2.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deveiate.org/projects/BlueCloth
COMMENT=	Markdown library for Ruby
LICENSE=	original-bsd

CONFLICTS+=	ruby[1-9][0-9]-bluecloth-[0-9]*

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
