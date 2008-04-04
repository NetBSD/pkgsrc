# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:24:00 jlam Exp $

DISTNAME=	merb-gen-0.9.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb application and plugin generator scripts

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	rubigen>=1.2.4:../../devel/rubigen
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
