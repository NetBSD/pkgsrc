# $NetBSD: Makefile,v 1.3 2021/09/05 02:20:49 wen Exp $

DISTNAME=	YAML-LibYAML-0.83
PKGNAME=	p5-${DISTNAME:C/LibYAML/XS/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/YAML::XS
COMMENT=	Perl YAML Serialization using XS and libyaml
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/YAML/LibYAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
