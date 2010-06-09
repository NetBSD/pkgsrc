# $NetBSD: Makefile,v 1.8 2010/06/09 16:32:36 minskim Exp $

DISTNAME=	activeresource-2.3.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.8:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
