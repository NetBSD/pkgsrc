# $NetBSD: Makefile,v 1.19 2022/08/29 14:20:57 wiz Exp $

DISTNAME=	termtter-2.2.8
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://termtter.github.com/
COMMENT=	Terminal based Twitter client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-termcolor>=1.0.0:../../devel/ruby-termcolor
DEPENDS+=	${RUBY_PKGPREFIX}-rubytter>=1.5.1:../../net/ruby-rubytter
DEPENDS+=	${RUBY_PKGPREFIX}-notify>=0.5.1:../../sysutils/ruby-notify

OVERRIDE_GEMSPEC+=	highline>=1.5.0
OVERRIDE_GEMSPEC+=	json_pure:json>=1.1.3
OVERRIDE_GEMSPEC+=	termcolor>=1.0.0
RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_INCOMPATIBLE=	26 # ruby-oauth via ruby-rubytter

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
