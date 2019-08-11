# $NetBSD: Makefile,v 1.14 2019/08/11 13:24:55 wiz Exp $

DISTNAME=	Plack-Handler-AnyEvent-SCGI-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Handler-AnyEvent-SCGI
COMMENT=	PSGI handler on AnyEvent::SCGI
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Handler/AnyEvent/SCGI/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Module-Build-Tiny>=0.039:../../devel/p5-Module-Build-Tiny
DEPENDS+=	p5-AnyEvent-SCGI-[0-9]*:../../www/p5-AnyEvent-SCGI
DEPENDS+=	p5-Plack>=0.9901:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
