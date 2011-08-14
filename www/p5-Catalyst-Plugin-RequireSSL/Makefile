# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:49 obache Exp $

DISTNAME=	Catalyst-Plugin-RequireSSL-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::RequireSSL
COMMENT=	Force SSL mode on select pages

DEPENDS+=	p5-Catalyst-Runtime>=5.23:../../www/p5-Catalyst-Runtime

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/RequireSSL/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
