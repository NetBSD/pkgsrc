# $NetBSD: Makefile,v 1.10 2018/03/22 08:14:52 adam Exp $

DISTNAME=	oniguruma-1.1.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes

USE_TOOLS+=	pax

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
