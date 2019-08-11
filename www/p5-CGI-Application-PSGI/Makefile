# $NetBSD: Makefile,v 1.14 2019/08/11 13:24:25 wiz Exp $

DISTNAME=	CGI-Application-PSGI-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-Application-PSGI
COMMENT=	Perl 5 module PSGI adapter for CGI::Application
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/CGI/Application/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
