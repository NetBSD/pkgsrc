# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:37 wiz Exp $

DISTNAME=	POE-Component-Server-PSGI-0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-Server-PSGI
COMMENT=	PSGI Server implementation for POE
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/POE/Component/Server/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE
DEPENDS+=	p5-POE-Filter-HTTP-Parser-[0-9]*:../../www/p5-POE-Filter-HTTP-Parser
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
