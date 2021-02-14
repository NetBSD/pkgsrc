# $NetBSD: Makefile,v 1.11 2021/02/14 15:09:30 taca Exp $

DISTNAME=	oniguruma-1.1.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library
LICENSE=	modified-bsd

RUBY_VERSIONS_INCOMPATIBLE=	30

USE_GCC_RUNTIME=	yes

USE_TOOLS+=	pax

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
