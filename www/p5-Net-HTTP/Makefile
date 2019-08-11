# $NetBSD: Makefile,v 1.27 2019/08/11 13:24:54 wiz Exp $

DISTNAME=	Net-HTTP-6.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-HTTP
COMMENT=	Perl 5 module for low-level HTTP connections (client)
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Net/HTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
