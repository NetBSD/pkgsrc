# $NetBSD: Makefile,v 1.19 2018/08/22 09:47:29 wiz Exp $

DISTNAME=	CGI-Compile-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Compile/
COMMENT=	Perl 5 module to compile .cgi scripts to a code reference
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Compile/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
# for make test
BUILD_DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI
BUILD_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
BUILD_DEPENDS+=	p5-Switch-[0-9]*:../../lang/p5-Switch

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
