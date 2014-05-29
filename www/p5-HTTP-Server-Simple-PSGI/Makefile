# $NetBSD: Makefile,v 1.7 2014/05/29 23:38:09 wiz Exp $

DISTNAME=	HTTP-Server-Simple-PSGI-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-PSGI/
COMMENT=	PSGI handler for HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTTP/Server/Simple/PSGI/.packlist

DEPENDS+=	p5-HTTP-Server-Simple>=0.42:../../www/p5-HTTP-Server-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
