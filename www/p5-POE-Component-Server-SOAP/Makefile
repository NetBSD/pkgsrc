# $NetBSD: Makefile,v 1.1.1.1 2013/11/04 21:37:53 tonnerre Exp $

DISTNAME=	POE-Component-Server-SOAP-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Server-SOAP/
COMMENT=	SOAP Server implementation for POE
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POE/Component/Server/SOAP/.packlist

DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE
DEPENDS+=	p5-POE-Component-Server-SimpleHTTP>=1.54:../../www/p5-POE-Component-Server-SimpleHTTP
DEPENDS+=	p5-SOAP-Lite>=0.55:../../net/p5-SOAP-Lite
DEPENDS+=	perl>=5.6:../../lang/perl5

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
