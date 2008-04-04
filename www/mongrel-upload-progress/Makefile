# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:54 jlam Exp $

DISTNAME=	mongrel_upload_progress-0.2.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Mongrel plugin to track file upload status

DEPENDS+=	mongrel>=0.3.13.3:../../www/mongrel
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.1:../../misc/ruby-gem_plugin

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
