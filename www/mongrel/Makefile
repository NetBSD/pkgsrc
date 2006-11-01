# $NetBSD: Makefile,v 1.1.1.1 2006/11/01 06:38:47 minskim Exp $

DISTNAME=	mongrel-0.3.13.4
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/13231/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Fast HTTP library and server for Ruby

BUILD_DEPENDS+=	rake-[0-9]*:../../devel/rake
DEPENDS+=	rubygems-[0-9]*:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.1:../../misc/ruby-gem_plugin
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=0.4.2:../../misc/ruby-daemons

RUBY_HAS_ARCHLIB=	yes

FIND_PREFIX:=	RAKE_PREFIX=rake
.include "../../mk/find-prefix.mk"

.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake clean
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake rerdoc
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake package

do-install:
	${GEM} install ${WRKSRC}/pkg/${DISTNAME}.gem -l

.include "../../mk/bsd.pkg.mk"
