# $NetBSD: Makefile,v 1.13 2015/06/12 10:51:53 wiz Exp $

DISTNAME=	CGI-Compile-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
