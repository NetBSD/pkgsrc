# $NetBSD: Makefile,v 1.11 2018/08/22 09:47:49 wiz Exp $

DISTNAME=	POE-Component-Server-SimpleHTTP-2.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Server-SimpleHTTP/
COMMENT=	Simple HTTP Server implementation for POE
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/POE/Component/Server/SimpleHTTP/.packlist

BUILD_DEPENDS+=	p5-POE-Filter-HTTP-Parser>=1.06:../../www/p5-POE-Filter-HTTP-Parser
BUILD_DEPENDS+=	p5-Test-POE-Client-TCP>=0.10:../../devel/p5-Test-POE-Client-TCP
DEPENDS+=	p5-POE>=1.0:../../devel/p5-POE
DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
#DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-Moose>=0.90:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-POE>=0.205:../../devel/p5-MooseX-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
