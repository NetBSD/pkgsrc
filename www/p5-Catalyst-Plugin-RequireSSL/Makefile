# $NetBSD: Makefile,v 1.12 2017/06/05 14:25:14 ryoon Exp $

DISTNAME=	Catalyst-Plugin-RequireSSL-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::RequireSSL
COMMENT=	Force SSL mode on select pages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.23:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/RequireSSL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
