# $NetBSD: Makefile,v 1.1 2026/11/08 16:20:52 taca Exp $

DISTNAME=	action_text-trix-2.1.19
CATEGORIES=	textproc devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/basecamp/trix
COMMENT=	Rich text editor for everyday writing
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	81

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
