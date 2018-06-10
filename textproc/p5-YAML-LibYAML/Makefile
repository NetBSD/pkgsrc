# $NetBSD: Makefile,v 1.30 2018/06/10 13:44:03 wen Exp $

DISTNAME=	YAML-LibYAML-0.70
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
