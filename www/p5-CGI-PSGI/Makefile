# $NetBSD: Makefile,v 1.21 2023/07/06 09:42:23 wiz Exp $

DISTNAME=	CGI-PSGI-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-PSGI
COMMENT=	Perl 5 module to adapt CGI.pm to the PSGI protocol
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/PSGI/.packlist

#DEPENDS+=	{perl>=5.10.1,p5-CGI>=3.33}:../../www/p5-CGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
