# $NetBSD: Makefile,v 1.4 2026/02/06 08:31:21 wiz Exp $

DISTNAME=	erubis-2.7.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kuwata-lab.com/erubis/
COMMENT=	Fast and extensible eRuby implementation which supports multi-language
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-erubis<2.7.0nb1 erubis-[0-9]*

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
