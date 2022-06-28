# $NetBSD: Makefile,v 1.25 2022/06/28 11:37:11 wiz Exp $

DISTNAME=	CGI-Emulate-PSGI-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-Emulate-PSGI
COMMENT=	Perl 5 module prodiving PSGI adapter for CGI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Emulate/PSGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
