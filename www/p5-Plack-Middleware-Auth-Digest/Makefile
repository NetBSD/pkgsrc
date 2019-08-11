# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:56 wiz Exp $

DISTNAME=	Plack-Middleware-Auth-Digest-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-Auth-Digest
COMMENT=	Plack middleware enabling digest authentication
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/Auth/Digest/.packlist

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
BUILD_DEPENDS+=	p5-Module-Build-Tiny-[0-9]*:../../devel/p5-Module-Build-Tiny

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
