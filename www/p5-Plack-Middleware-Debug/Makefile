# $NetBSD: Makefile,v 1.18 2019/06/30 20:17:41 nia Exp $

DISTNAME=	Plack-Middleware-Debug-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-Debug
COMMENT=	Plack middleware to display information on request/response
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Plack/Middleware/Debug/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-Class-Method-Modifiers>=1.05:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Data-Dumper-Concise-[0-9]*:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Text-MicroTemplate-[0-9]*:../../textproc/p5-Text-MicroTemplate
DEPENDS+=	p5-Module-Versions>=0.01:../../devel/p5-Module-Versions

BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
