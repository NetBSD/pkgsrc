# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:30 wiz Exp $

DISTNAME=	HTTP-Server-Simple-PSGI-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Server-Simple-PSGI
COMMENT=	PSGI handler for HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Server/Simple/PSGI/.packlist

DEPENDS+=	p5-HTTP-Server-Simple>=0.42:../../www/p5-HTTP-Server-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
