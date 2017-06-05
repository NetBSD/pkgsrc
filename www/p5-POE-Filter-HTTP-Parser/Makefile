# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:27 ryoon Exp $

DISTNAME=	POE-Filter-HTTP-Parser-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Filter-HTTP-Parser/
COMMENT=	HTTP POE filter for HTTP clients or servers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POE/Filter/HTTP/Parser/.packlist

BUILD_DEPENDS+=	p5-Test-POE-Client-TCP>=0.1:../../devel/p5-Test-POE-Client-TCP
BUILD_DEPENDS+=	p5-Test-POE-Server-TCP>=0.16:../../devel/p5-Test-POE-Server-TCP
DEPENDS+=	p5-HTTP-Parser>=0.04:../../www/p5-HTTP-Parser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-POE>=1.003:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
