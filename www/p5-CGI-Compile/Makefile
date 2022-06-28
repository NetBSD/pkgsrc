# $NetBSD: Makefile,v 1.27 2022/06/28 11:37:10 wiz Exp $

DISTNAME=	CGI-Compile-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-Compile
COMMENT=	Perl 5 module to compile .cgi scripts to a code reference
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CGI/Compile/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
TEST_DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI
TEST_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
TEST_DEPENDS+=	p5-Switch-[0-9]*:../../lang/p5-Switch
TEST_DEPENDS+=	p5-Sub-Name>=0:../../devel/p5-Sub-Name
TEST_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
