# $NetBSD: Makefile,v 1.19 2022/06/28 11:37:30 wiz Exp $

DISTNAME=	HTTP-Server-Simple-Recorder-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Server-Simple-Recorder
COMMENT=	Perl 5 module mixin to record HTTP::Server::Simple's sockets

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/HTTP/Server/Simple/Recorder/.packlist

BUILD_DEPENDS+=	p5-Test-HTTP-Server-Simple>=0.02:../../www/p5-Test-HTTP-Server-Simple
DEPENDS+=	p5-HTTP-Server-Simple>=0.10:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-IO-Tee-[0-9]*:../../devel/p5-IO-Tee

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
