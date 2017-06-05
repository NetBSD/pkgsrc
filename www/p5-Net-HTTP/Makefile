# $NetBSD: Makefile,v 1.21 2017/06/05 14:25:27 ryoon Exp $

DISTNAME=	Net-HTTP-6.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-HTTP/
COMMENT=	Perl 5 module for low-level HTTP connections (client)
LICENSE=	${PERL5_LICENSE}

#necessary for test
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Net/HTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
