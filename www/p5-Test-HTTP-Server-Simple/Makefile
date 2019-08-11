# $NetBSD: Makefile,v 1.17 2019/08/11 13:25:02 wiz Exp $

DISTNAME=	Test-HTTP-Server-Simple-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-HTTP-Server-Simple
COMMENT=	Perl 5 module providing Test::More functions for HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/HTTP/Server/Simple/.packlist

DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
# This may be only a build dependency - No, it's not
#DEPENDS+=	{perl>=5.10,p5-Test-Simple>0.62}:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
