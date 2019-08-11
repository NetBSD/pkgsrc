# $NetBSD: Makefile,v 1.18 2019/08/11 13:25:01 wiz Exp $

DISTNAME=	Template-Toolkit-Simple-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Toolkit-Simple
COMMENT=	Perl 5 module providing a simple Interface to Template Toolkit
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Template/Toolkit/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Template-Toolkit>=2.22:../../www/p5-Template-Toolkit
DEPENDS+=	p5-YAML-LibYAML>=0.37:../../textproc/p5-YAML-LibYAML
BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

REPLACE_PERL=	bin/tt-render

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
