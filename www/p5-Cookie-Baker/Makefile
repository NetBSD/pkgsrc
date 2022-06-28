# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:19 wiz Exp $

DISTNAME=	Cookie-Baker-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cookie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cookie-Baker
COMMENT=	Perl extension for cookie string generator/parser
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Time>=0:../../time/p5-Test-Time
DEPENDS+=	p5-URI>=0:../../www/p5-URI

USE_LANGUAGES=	#
PERL5_PACKLIST=	auto/Cookie/Baker/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
