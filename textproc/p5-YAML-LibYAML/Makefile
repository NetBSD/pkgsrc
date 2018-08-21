# $NetBSD: Makefile,v 1.31 2018/08/21 12:19:30 wiz Exp $

DISTNAME=	YAML-LibYAML-0.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML-LibYAML/
COMMENT=	Perl XS binding to libyaml
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/YAML/LibYAML/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
