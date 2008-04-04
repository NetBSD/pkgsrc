# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:26:58 jlam Exp $

DISTNAME=	thoth_delicious-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	del.icio.us plugin for the Thoth blog engine

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.2:../../textproc/ruby-json-pure
DEPENDS+=	thoth>=0.1.0:../../www/thoth

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
