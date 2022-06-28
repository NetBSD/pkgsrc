# $NetBSD: Makefile,v 1.26 2022/06/28 11:37:15 wiz Exp $

DISTNAME=	Catalyst-Model-Adaptor-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Catalyst::Model::Adaptor
COMMENT=	Use a plain class as a Catalyst model
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Catalyst/Model/Adaptor/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
